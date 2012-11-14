//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include "EtherCatMACSlave.h"
#include "EthernetFrame_m.h"

bool stampFinish=false;




EtherCatMACSlave::EtherCatMACSlave()
{
}

EtherCatMACSlave::~EtherCatMACSlave()
{
}

Define_Module(EtherCatMACSlave);

void EtherCatMACSlave::initialize()
{
    delay=par("delay");
    scenario=par("scenario");
    prob=par("probability");
    nContestWin=0;
    relativeDeadline=1;
    underControl=false;
}

void EtherCatMACSlave::handleMessage(cMessage *msg)
{
    //EV << "I'm EtherCatMACSlave and handleMessage to gate "<< msg->getArrivalGate()->getFullName() << endl;

    if(msg->isSelfMessage()){
            EV << "I'm EtherCatMACSlave and receive pyload "<< msg << "\n";
            if(gate("phys2$o")->getNextGate()->isConnected()){
                send(msg->dup(),"phys2$o");
                EV << "I'm EtherCatMACSlave and send "<< msg << "to other Slave\n";
            }else{

                EV << "I'm EtherCatMACSlave and finish chain"<<endl;
                if(strcmp(msg->getName(),"END_PDU")==0){
                    if(controlIfIwon(msg)){
                        EV << "Ho vinto \n";
                    }
                }
                send(msg->dup(),"phys1$o");
            }
        }

    else if(msg->getArrivalGate()==gate("phys1$i")){
       // EV << "I'm EtherCatMACSlave and receive single 1byte cPacket  "<< msg << ", is Global Value?:"<<  \n";
        EV << "GET NAME:" << msg->getName() << "\n";
        if(strcmp(msg->getName(),"END_PDU")==0){

            //identifico il nodo
            cMsgPar *nodeNumber=&msg->par("nodeNumber");
            long nodeNumberValue=nodeNumber->longValue();
            nodeNumberValue++;
            node=nodeNumberValue;
            if(node==0){
                node=nodeNumberValue;
            }
            nodeNumber->setLongValue(nodeNumberValue);
            //lancio il generatore di code

            //operazioni sull'indirizzo sequenziale
            cMsgPar *adp=&msg->par("ADP");
            long address=adp->longValue();
            address++;
            adp->setLongValue(address);

            //operazioni per recuperare il parametro di flag global
            //ovvero se il pacchetto vale per tutti i messaggi
            cMsgPar *global=&msg->par("global");
            bool globalValue=global->boolValue();

            EV << "I'm EtherCatMACSlave and receive single 1byte cPacket  "<< msg << ", is Global Value?: "<<globalValue<<"\n";

            if(globalValue){
                queueGenerator();
                stampFinish=true;
                ev << "Global Message arrived:" << relativeDeadline << "\n";
                setDeadlineOnFrame(msg);
                cPacket *byte = (cPacket*)msg;
                send(byte,"upperLayerOut");
            }


            else if(address==0){
                    cPacket *byte = (cPacket*)msg;
                    ev << "I'm EtherCatMACSlave and decapsulate payload lenght: "<<byte->getByteLength() << endl;
                    send(byte,"upperLayerOut");
                    EV << "I'm EtherCatMACSlave and send "<< byte << "to my upperLayerOut\n";
                }
            else{

                    scheduleAt(simTime()+delay, msg->dup());//era event
                    //scheduleAt(simTime()+uniform(0,1), event->dup());
                }
        }

        else{
            scheduleAt(simTime()+delay, msg->dup());//era event
            //scheduleAt(simTime()+uniform(0,1), event->dup());

        }

    }else if(msg->getArrivalGate()==gate("upperLayerIn")){
        scheduleAt(simTime()+delay, msg->dup());//era event
        //scheduleAt(simTime()+uniform(0,1), event->dup());


    }else if(msg->getArrivalGate()==gate("phys2$i")){
            if(strcmp(msg->getName(),"END_PDU")==0){
                //cMsgPar *deadl=&msg->par("deadl");
                //long deadlineValue=deadl->longValue();
                //EV << "Verifico se vinco relDed: "<< relativeDeadline << " dedVal: "<< deadlineValue << "\n";
                if(controlIfIwon(msg)){
                    EV << "Ho vinto \n";
                }
            }
            send(msg,"phys1$o");
                EV << "I'm EtherCatMACSlave and send "<< msg << "to prev slave\n";
        }
    else
        EV << "Error"<<endl;
}


bool EtherCatMACSlave::controlIfIwon(cMessage *msg){
    // verifico che ho scritto in qualche frame il mio valore, ovvero
    // che sto partecipando ad una contesa
    if(!underControl){
        return false;
    }
    cMsgPar *timeStamp=&msg->par("timeStamp");
    long timeStampValue=timeStamp->longValue();
    // verifico che sto confrontando lo stesso frame che ho settato in partenza
    if(timeStampValue!=timeStart){
        return false;
    }

    // se siamo arrivati qui significa che stiamo controllando la frame giusta
    // sia che vinco sia che perdo, posso ripartecipare alle contese
    underControl=false;

    if(scenario==1){
        if(queue.length()>0){
            cMsgPar *queueHead= check_and_cast<cMsgPar*>(queue.get(0));
            long queueHeadValue=queueHead->longValue();
            cMsgPar *deadl=&msg->par("deadl");
            long deadlineValue=deadl->longValue();
            EV << "confronto Se ho vinto, la testa vale:"<< queueHead->longValue() << "\n";
            if(queueHeadValue==deadlineValue){
                nContestWin++;
                queue.pop();
                return true;
            }
        }
    }
    if(scenario==2){
        if(queue.length()>0){
            cMsgPar *queueHead= check_and_cast<cMsgPar*>(queue.get(0));
            std::string stringValue= queueHead->stringValue();
            cMsgPar *bitWise=&msg->par("bitWise");
            std::string bitWiseValue=bitWise->stringValue();
            EV << "confronto Se ho vinto, la testa vale:"<< queueHead << "\n";
            if(stringValue==bitWiseValue){
                nContestWin++;
                queue.pop();
                return true;
            }
        }
    }
    return false;
}

void EtherCatMACSlave::setDeadlineOnFrame(cMessage *msg){
    if(underControl)
    {
        return;
    }
    if(scenario==1){
        cMsgPar *deadl=&msg->par("deadl");
        long deadlValue=deadl->longValue();
        EV << "I'm EtherCatMACSlave "<< node<<" And I verified the Frame, deadValue: "<< deadlValue<< " and relativeDeadLine: "<< relativeDeadline << "\n";
        if(queue.length()>0){
            cMsgPar *queueHead= check_and_cast<cMsgPar*>(queue.get(0));
            EV << "confronto il frame passante:"<<deadlValue<<" , la testa vale:"<< queueHead->longValue() << "\n";
            if(deadlValue==0 || deadlValue>queueHead->longValue() ){
                // mi conservo il valore del timeStamp della frame
                // in maniera tale da poterla riconoscere al suo ritorno.
                cMsgPar *timeStamp=&msg->par("timeStamp");
                long timeStampValue=timeStamp->longValue();
                timeStart=timeStampValue;

                // setto una flag in maniera tale da non scrivere niente nelle frame successive
                underControl=true;

                EV << "I'm EtherCatMACSlave "<< node<<" And I win the context and I write:" << queueHead->longValue() << "\n";
                deadl->setLongValue(queueHead->longValue());
            }
        }
    }
    if(scenario==2){
            cMsgPar *bitWise=&msg->par("bitWise");
            std::string bitWiseValue=bitWise->stringValue();
            //EV << "I'm EtherCatMACSlave "<< node<<" And I verified the Frame, deadValue: "<< deadlValue<< " and relativeDeadLine: "<< relativeDeadline << "\n";
            if(queue.length()>0){
                cMsgPar *queueHead= check_and_cast<cMsgPar*>(queue.get(0));
                std::string stringValue= queueHead->stringValue();
                if( bitWiseValue >stringValue){
                    // mi conservo il valore del timeStamp della frame
                    // in maniera tale da poterla riconoscere al suo ritorno.
                    cMsgPar *timeStamp=&msg->par("timeStamp");
                    long timeStampValue=timeStamp->longValue();
                    timeStart=timeStampValue;

                    // setto una flag in maniera tale da non scrivere niente nelle frame successive
                    underControl=true;

                    EV << "I'm EtherCatMACSlave "<< node<<" And I win the context and I write:" << queueHead << "\n";
                    bitWise->setStringValue(queueHead->stringValue());
                }
            }
        }
}

void EtherCatMACSlave::queueGenerator(){

    int random=uniform (1, 100);
    if(random>=prob)
        return;

    if(scenario==1){
        relativeDeadline=uniform (1.0, 100000000.0);
        cMsgPar *relDeadl=new cMsgPar("relativeDeadline");
        //EV <<"Simtime(): "<< simTime().raw()<<" relativeDeadline:"<<relativeDeadline<< " diff: "<<simTime().raw()-relativeDeadline;
        relDeadl->setLongValue(simTime().raw()-relativeDeadline);
        queue.insert(relDeadl->dup());
        queueTemp.insert(relDeadl->dup());
    }
    if(scenario==2){
        relativeDeadline=uniform (0,256);
        char result[8]={'0','0','0','0','0','0','0','0'};
        itoa (relativeDeadline,result,2);
        cMsgPar *bitWise=new cMsgPar("bitWise");
        bitWise->setStringValue(result);
        queue.insert(bitWise->dup());
        queueTemp.insert(bitWise->dup());
    }
}



void EtherCatMACSlave::finish(){
    if(stampFinish){
        if(scenario==1){
            EV << "I'm EtherCatMACSlave "<< node<<" and the time Start is "<< timeStart << "\n";
            EV << "I'm EtherCatMACSlave "<< node<<" and the time Arrived is ";
            for(int i=0;i<queue.length();i++){
                cMsgPar *par= check_and_cast<cMsgPar*>(queue.get(i));
                EV <<  par->longValue() << ", ";
            }
            EV <<"\nTemp:";
            for(int i=0;i<queueTemp.length();i++){
                        cMsgPar *par= check_and_cast<cMsgPar*>(queueTemp.get(i));
                        EV <<  par->longValue() << ", ";
            }
            EV <<"\n";
            //EV << "I'm EtherCatMACSlave "<< node<<" and the difference time is "<< relativeDeadline-timeStart << "\n";
            EV << "I'm EtherCatMACSlave "<< node<<" and I win "<< nContestWin << " times \n";
        }
        if(scenario==2){
            EV << "I'm EtherCatMACSlave "<< node<<" and the time Start is "<< timeStart << "\n";
            EV << "I'm EtherCatMACSlave "<< node<<" and the time Arrived is ";
            for(int i=0;i<queue.length();i++){
                cMsgPar *par= check_and_cast<cMsgPar*>(queue.get(i));
                EV <<  par->stringValue() << ", ";
            }
            EV <<"\nTemp:";
            for(int i=0;i<queueTemp.length();i++){
                        cMsgPar *par= check_and_cast<cMsgPar*>(queueTemp.get(i));
                        EV <<  par->stringValue() << ", ";
            }
            EV <<"\n";
            //EV << "I'm EtherCatMACSlave "<< node<<" and the difference time is "<< relativeDeadline-timeStart << "\n";
            EV << "I'm EtherCatMACSlave "<< node<<" and I win "<< nContestWin << " times \n";
        }
    }
}


