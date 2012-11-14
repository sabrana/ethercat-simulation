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

#include "EtherCatMACMaster.h"
#include "EthernetFrame_m.h"

Define_Module(EtherCatMACMaster);



EtherCatMACMaster::EtherCatMACMaster()
{

    byteReturn=0;
    type1=0;
    type2=0;
    type3=0;
    type4=0;
    type5=0;
    type6=0;
    type7=0;
}

EtherCatMACMaster::~EtherCatMACMaster()
{
    // Dispose of dynamically allocated the objects
}


void EtherCatMACMaster::initialize()
{

        //delay variabile con max pari al parametro di configurazione
        int delayMax=par("delay");
        nFrameToSend=par("nFrameToSend");
        onlyEndPdu=par("onlyEndPdu");
        probabiltyGlobalFrame=par("probabiltyGlobalFrame");
        delay=uniform(0.000009,delayMax);//delayMax=0.000001;

}

void EtherCatMACMaster::handleMessage(cMessage *msg)
{

    if (msg->isSelfMessage()){
        EV << "I'm EtherCatMACMaster and receive event msg" << endl;
        send(msg->dup(),"phys$o");
    }

    if(msg->getArrivalGate()==gate("upperLayerIn")){
        EV << "I'm EtherCatMACMaster and receive payload from MasterApplication Layer"<< msg << "\n";
        EthernetFrame *ethf = new EthernetFrame("ethernet-frame"); // subclassed from cPacket
        EV << "Scheduling first send to t=5.0s\n";


        // TUTTI I FRAME (DEFAULT)
        if(!onlyEndPdu){
        int byte=1;
        int byteRotation;
        int frameSended=0;
        while(frameSended!=nFrameToSend){
            byteRotation=byte-1;
            frameSended++;
                //preamble ethernet frame
                for(byte; byte<=7+byteRotation; byte++){
                    //preamble ethernet frame
                    ev << "Adding " << byte +byteRotation <<" /7 packet of preamble ethernet frame"<< endl;
                    cPacket *c=new cPacket("Preamble");
                    c->setByteLength(1);
                    scheduleAt(simTime()+delay*byte, c->dup());
                }

                //SFD ethernet frame
                for(byte; byte<=8+byteRotation; byte++){
                    ev << "Adding " << byte-7 +byteRotation <<"/1 packet of SFD ethernet frame"<< endl;
                    cPacket *c=new cPacket("SFD");
                    c->setByteLength(1);
                    scheduleAt(simTime()+delay*byte, c->dup());
                }

                //Destination MAC Address ethernet frame
                for(byte; byte<=14+byteRotation; byte++){
                    //preamble ethernet frame
                    ev << "Adding " << byte-8 +byteRotation<<" /6 packet of DA ethernet frame"<< endl;
                    cPacket *c=new cPacket("DA");
                    c->setByteLength(1);
                    scheduleAt(simTime()+delay*byte, c->dup());
                }

                //Source MAC Address ethernet frame
                for(byte; byte<=20+byteRotation; byte++){
                    //preamble ethernet frame
                    ev << "Adding " << byte-14 +byteRotation <<" /6 packet of SA ethernet frame"<< endl;
                    cPacket *c=new cPacket("SA");
                    c->setByteLength(1);
                    scheduleAt(simTime()+delay*byte, c->dup());
                }

                //EtherType ethernet frame
                for(byte; byte<=22+byteRotation; byte++){
                    ev << "Adding " << byte-16 +byteRotation<<" /2 packet of EtherType ethernet frame"<< endl;
                    cPacket *c=new cPacket("EtherType");
                    c->setByteLength(1);
                    scheduleAt(simTime()+delay*byte, c->dup());
                }

                //PayLoad ethernet frame
                EtherCatFrame* frame=(EtherCatFrame*)msg;
                int length_payload=frame->getLength();

                //HDR: 2 byte
                for(byte; byte<=22+2+byteRotation; byte++){
                    ev << "Adding " << byte-22 +byteRotation<<" /"<<length_payload<<" packet of PayLoad ethernet frame: HDR"<< endl;
                        cPacket *c=new cPacket("Frame HDR");
                        c->setByteLength(1);
                        //settiamo il valore del frame HDR nell'ultimo byte inviato
                        if(byte==22+2+byteRotation){
                            cMsgPar *length=new cMsgPar("length");
                            length->setLongValue(length_payload);
                            c->addPar(length);
                        }
                    scheduleAt(simTime()+delay*byte, c->dup());
                }

                // n PDU12
                int start=24;

                //ottengo il numero di pdu
                int dim=0;
                for(int i=0;i<frame->getPduArraySize();i++){

                        if(frame->getPdu(i).LEN!=0)
                            dim++;

                    }

                for(int i=0;i<=dim;i++){
                    type12PDU pdu=frame->getPdu(i);
                        for(byte; byte<=start+pdu.LEN+byteRotation; byte++){
                        ev << "Adding " << byte-22 +byteRotation<<" /"<<length_payload<<" packet of PayLoad ethernet frame: PDU "<<i<< endl;
                            cPacket *c=new cPacket("PDU");
                            c->setByteLength(1);
                            //settiamo il valore del frame HDR nell'ultimo byte inviato
                            if(byte==start+pdu.LEN+byteRotation){
                                c->setName("END_PDU");

                                cMsgPar *length=new cMsgPar("LEN");
                                length->setLongValue(length_payload);

                                cMsgPar *adp=new cMsgPar("ADP");
                                adp->setLongValue(pdu.ADP);

                                cMsgPar *global=new cMsgPar("global");
                                int random=uniform (1, 100);
                                    if(random<=probabiltyGlobalFrame){
                                       global->setBoolValue(true);
                                    }
                                    else{
                                       global->setBoolValue(false);
                                    }
                                cMsgPar *timeStamp=new cMsgPar("timeStamp");
                                SimTime timer=simTime()+delay*byte;
                                timeStamp->setLongValue(timer.raw());

                                cMsgPar *nodeNumber=new cMsgPar("nodeNumber");
                                nodeNumber->setLongValue(0);

                                cMsgPar *deadline=new cMsgPar("deadl");
                                deadline->setLongValue(0);

                                cMsgPar *bitWise=new cMsgPar("bitWise");
                                bitWise->setStringValue("11111111");
                                // questa è la frame a più bassa priorità


                                c->addPar(length);
                                c->addPar(adp);
                                c->addPar(global);
                                c->addPar(timeStamp);
                                c->addPar(nodeNumber);
                                c->addPar(deadline);
                                c->addPar(bitWise);

                            }

                        scheduleAt(simTime()+delay*byte, c->dup());
                    }
                    start=start+=pdu.LEN;
                }



                //FCS ethernet frame
                for(byte; byte<=length_payload+26+byteRotation; byte++){
                    ev << "Adding " << byte-(length_payload+22)+byteRotation <<" /4 packet of FCS ethernet frame"<< endl;
                    cPacket *c=new cPacket("FCS");
                    c->setByteLength(1);
                    scheduleAt(simTime()+delay*byte, c->dup());
                }
            }
        }

        // MANDIAMO SOLO I PDU
        else{
            //PayLoad ethernet frame
            EtherCatFrame* frame=(EtherCatFrame*)msg;
            int length_payload=frame->getLength();
            int dim=0;
            int start=24;
            int byte=24;
                for(int i=0;i<frame->getPduArraySize();i++){
                        if(frame->getPdu(i).LEN!=0)
                            dim++;
                }

                for(int i=0;i<=dim;i++){
                    type12PDU pdu=frame->getPdu(i);
                        for(byte; byte<=start+pdu.LEN; byte++){
                        ev << "Adding " << byte-22 <<" /"<<length_payload<<" packet of PayLoad ethernet frame: PDU "<<i<< endl;
                            cPacket *c=new cPacket("PDU");
                            c->setByteLength(1);
                            //settiamo il valore del frame HDR nell'ultimo byte inviato
                            if(byte==start+pdu.LEN){
                                c->setName("END_PDU");

                                cMsgPar *length=new cMsgPar("LEN");
                                length->setLongValue(length_payload);

                                cMsgPar *adp=new cMsgPar("ADP");
                                adp->setLongValue(pdu.ADP);

                                cMsgPar *global=new cMsgPar("global");
                                global->setBoolValue(true);

                                cMsgPar *timeStamp=new cMsgPar("timeStamp");
                                SimTime timer=simTime()+delay*byte;
                                timeStamp->setLongValue(timer.raw());

                                cMsgPar *nodeNumber=new cMsgPar("nodeNumber");
                                nodeNumber->setLongValue(0);

                                cMsgPar *deadline=new cMsgPar("deadline");
                                deadline->setLongValue(0);


                                cMsgPar *deadl=new cMsgPar("deadl");
                                deadl->setLongValue(0);



                                cMsgPar *bitWise=new cMsgPar("bitWise");
                                bitWise->setStringValue("11111111");
                                // questa è la frame a più bassa priorità

                                c->addPar(length);
                                c->addPar(adp);
                                c->addPar(global);
                                c->addPar(timeStamp);
                                c->addPar(nodeNumber);
                                c->addPar(deadl);
                                c->addPar(deadline);
                                c->addPar(bitWise);

                            }

                            // MANDO SOLO I PDU END OVVERO SOLO QUELLI CONTENENTI INFORMAZIONI
                            else{
                                continue;
                            }

                        scheduleAt(simTime()+delay*byte, c->dup());
                    }
                }
        }




   }else if(msg->getArrivalGate()==gate("phys$i")){

       if(strcmp(msg->getName(),"Preamble")==0){
                  type1++;
       }
       if(strcmp(msg->getName(),"SFD")==0){
                  type2++;
       }
       if(strcmp(msg->getName(),"DA")==0){
                  type3++;
       }
       if(strcmp(msg->getName(),"SA")==0){
                  type4++;
       }
       if(strcmp(msg->getName(),"EtherType")==0){
                  type5++;
       }
       if(strcmp(msg->getName(),"PDU")==0 || strcmp(msg->getName(),"END_PDU")==0 ||  strcmp(msg->getName(),"Frame HDR")==0  ){
                  type6++;
       }
       if(strcmp(msg->getName(),"FCS")==0){
                  type7++;
       }
       byteReturn++;

   }


}


void EtherCatMACMaster::finish(){
        ev << "Preamble:" << type1   << "\n";
        ev << "SFD:" <<      type2   << "\n";
        ev << "DA:" <<       type3   << "\n";
        ev << "SA:" <<       type4   << "\n";
        ev << "EtherType:"<< type5   << "\n";
        ev << "PayLoad:" <<  type6   << "\n";
        ev << "FCS:" <<      type7   << "\n";
        ev << "byteReturn:" << byteReturn << "\n";
        ev << "valueData:" <<  this->valueData << "\n";
    }



