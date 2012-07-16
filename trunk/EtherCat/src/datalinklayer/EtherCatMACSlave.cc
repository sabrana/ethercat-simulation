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


Define_Module(EtherCatMACSlave);

void EtherCatMACSlave::initialize()
{
    // TODO - Generated method body
}

void EtherCatMACSlave::handleMessage(cMessage *msg)
{
    EV << "I'm EtherCatMACSlave and handleMessage to gate "<< msg->getArrivalGate()->getFullName() << endl;
    if(msg->getArrivalGate()==gate("phys1$i")){
        EV << "I'm EtherCatMACSlave and receive ethf "<< msg << "\n";
        cPacket *ethf = (cPacket*)msg;
        cPacket *payload = ethf->decapsulate();
        ev << "I'm EtherCatMACSlave and decapsulate payload lenght: "<<payload->getByteLength() << endl; // --> 26+1498 = 1524
        send(payload,"upperLayerOut");
            EV << "I'm EtherCatMACSlave and send "<< ethf << "to my upperLayerOut\n";
    }
    else if(msg->getArrivalGate()==gate("upperLayerIn")){
        EV << "I'm EtherCatMACSlave and receive psyload "<< msg << "\n";
        cPacket *ethf = new cPacket("ethernet-frame"); // subclassed from cPacket
        ethf->setByteLength(26);

        ethf->encapsulate((cPacket*)msg);
        ev << ethf->getByteLength() << endl; // --> 26+1498 = 1524


        if(gate("phys2$o")->getNextGate()->isConnected()){
            send(ethf,"phys2$o");
            EV << "I'm EtherCatMACSlave and send "<< ethf << "to other Slave\n";
        }else{
            EV << "I'm EtherCatMACSlave and finish chain"<<endl;
            send(ethf,"phys1$o");
        }
    }else if(msg->getArrivalGate()==gate("phys2$i")){
            EV << "I'm EtherCatMACSlave and receive return ethf "<< msg << "\n";
            send(msg,"phys1$o");
                EV << "I'm EtherCatMACSlave and send "<< msg << "to prev slave\n";
        }

}
