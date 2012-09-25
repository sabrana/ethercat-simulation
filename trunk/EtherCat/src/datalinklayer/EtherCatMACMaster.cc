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

void EtherCatMACMaster::initialize()
{

    // TODO - Generated method body
}

void EtherCatMACMaster::handleMessage(cMessage *msg)
{

    //if(!payload->isSelfMessage()){
    //    scheduleAt(1.0, payload->dup());
    //}
    //else{
    //}
    EV << "I'm EtherCatMACMaster and handleMessage to gate "<< msg->getArrivalGate()->getFullName() << endl;
    if(msg->getArrivalGate()==gate("upperLayerIn")){
        EV << "I'm EtherCatMACMaster and receive payload from MasterApplication Layer"<< msg << "\n";
        EthernetFrame *ethf = new EthernetFrame("ethernet-frame"); // subclassed from cPacket
        ethf->setByteLength(26);
        ethf->encapsulate((cPacket*)msg);
        ev << "I'm EtherCatMACMaster and encapsulate payload in EthernetFrame"<<ethf->getByteLength() << endl; // --> 26+1498 = 1524

        //    send(ethf,"phys$o");
        for(int i=0;i<ethf->getByteLength();i++){
            cPacket *c=new cPacket();
            c->setByteLength(1);
            send(c,"phys$o");
        }
        EV << "I'm EtherCatMACMaster and send "<< ethf << "to Slave\n";
    }else if(msg->getArrivalGate()==gate("phys$i")){
        //da implementare
    }
}



