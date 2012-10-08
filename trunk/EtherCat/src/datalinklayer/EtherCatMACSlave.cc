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
#include "split8_m.h"

EtherCatMACSlave::EtherCatMACSlave()
{
    // Set the pointer to NULL, so that the destructor won't crash
    // even if initialize() doesn't get called because of a runtime
    // error or user cancellation during the startup process.
    event = tempMsg = NULL;
    counter=0;
}

EtherCatMACSlave::~EtherCatMACSlave()
{
    // Dispose of dynamically allocated the objects
    cancelAndDelete(event);
    delete tempMsg;
}

Define_Module(EtherCatMACSlave);

void EtherCatMACSlave::initialize()
{
    delay=par("delay");
    event = new cMessage("event");
    tempMsg = NULL;
}

void EtherCatMACSlave::handleMessage(cMessage *msg)
{
    //EV << "I'm EtherCatMACSlave and handleMessage to gate "<< msg->getArrivalGate()->getFullName() << endl;

    if(msg->isSelfMessage()){
            EV << "I'm EtherCatMACSlave and receive pyload "<< msg << "\n";



            if(gate("phys2$o")->getNextGate()->isConnected()){
                send(tempMsg->dup(),"phys2$o");
                EV << "I'm EtherCatMACSlave and send "<< tempMsg << "to other Slave\n";
            }else{
                EV << "I'm EtherCatMACSlave and finish chain"<<endl;
                send(tempMsg->dup(),"phys1$o");
            }
        }

    else if(msg->getArrivalGate()==gate("phys1$i")){
        EV << "I'm EtherCatMACSlave and receive single 1byte cPacket  "<< msg << "\n";
        EV << "GET NAME:" << msg->getName() << "\n";
        if(strcmp(msg->getName(),"END_PDU")==0){
            counter++;
            cMsgPar *adp=&msg->par("ADP");
            long address=adp->longValue();
            address++;
            adp->setLongValue(address);

            if(address==0){
            cPacket *byte = (cPacket*)msg;
            ev << "I'm EtherCatMACSlave and decapsulate payload lenght: "<<byte->getByteLength() << endl;
            send(byte,"upperLayerOut");
            EV << "I'm EtherCatMACSlave and send "<< byte << "to my upperLayerOut\n";
            }
        else{
                tempMsg = msg->dup();
                scheduleAt(simTime()+delay, event->dup());
                //scheduleAt(simTime()+uniform(0,1), event->dup());

            }
        }

        else{
            tempMsg = msg->dup();
            scheduleAt(simTime()+delay, event->dup());
            //scheduleAt(simTime()+uniform(0,1), event->dup());

        }

    }else if(msg->getArrivalGate()==gate("upperLayerIn")){

        tempMsg = msg->dup();
        scheduleAt(simTime()+delay, event->dup());
        //scheduleAt(simTime()+uniform(0,1), event->dup());


    }else if(msg->getArrivalGate()==gate("phys2$i")){
            EV << "I'm EtherCatMACSlave and receive return ethf "<< tempMsg << "\n";
            send(msg,"phys1$o");
                EV << "I'm EtherCatMACSlave and send "<< msg << "to prev slave\n";
        }
    else
        EV << "Error"<<endl;
}
void EtherCatMACSlave::finish(){
    //EV << "I'm EtherCatMACSlave and counter "<< counter << "\n";

}

