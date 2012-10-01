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
#include "split8_m.h"

Define_Module(EtherCatMACMaster);

EtherCatMACMaster::EtherCatMACMaster()
{
    // Set the pointer to NULL, so that the destructor won't crash
    // even if initialize() doesn't get called because of a runtime
    // error or user cancellation during the startup process.
    event = tempMsg = NULL;
}

EtherCatMACMaster::~EtherCatMACMaster()
{
    // Dispose of dynamically allocated the objects
    cancelAndDelete(event);
    delete tempMsg;
}


void EtherCatMACMaster::initialize()
{

    // Create the event object we'll use for timing -- just any ordinary message.
        event = new cMessage("event");

        // No tictoc message yet.
        tempMsg = NULL;


            // We don't start right away, but instead send an message to ourselves
            // (a "self-message") -- we'll do the first sending when it arrives
            // back to us, at t=5.0s simulated time.


}

void EtherCatMACMaster::handleMessage(cMessage *msg)
{

    if (msg->isSelfMessage()){
        EV << "I'm EtherCatMACMaster and receive event msg" << endl;
        send(tempMsg->dup(),"phys$o");
    }

    if(msg->getArrivalGate()==gate("upperLayerIn")){
        EV << "I'm EtherCatMACMaster and receive payload from MasterApplication Layer"<< msg << "\n";
        EthernetFrame *ethf = new EthernetFrame("ethernet-frame"); // subclassed from cPacket
        ethf->setByteLength(26);
        ethf->encapsulate((cPacket*)msg);
        ev << "I'm EtherCatMACMaster and encapsulate payload in EthernetFrame"<<ethf->getByteLength() << endl; // --> 26+1498 = 1524


        cPacket *c=new cPacket();
        c->setByteLength(1);

        EV << "Scheduling first send to t=5.0s\n";
        tempMsg = c;


          for (int i=1; i<=ethf->getByteLength(); i++){
                ev << "Adding other consecutives packets n" ;
           scheduleAt(simTime()+uniform(0,1)*i, event->dup());
           }




        EV << "I'm EtherCatMACMaster and send "<< ethf << "to Slave\n";
   }else if(msg->getArrivalGate()==gate("phys$i")){
        //da implementare
   }
}



