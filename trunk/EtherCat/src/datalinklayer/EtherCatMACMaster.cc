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

void EtherCatMACMaster::handleMessage(cMessage *payload)
{

    //if(!payload->isSelfMessage()){
    //    scheduleAt(1.0, payload->dup());
    //}
    //else{
    EV << "I'm EtherCatMACMaster and receive payload "<< payload << "\n";
    EthernetFrame *ethf = new EthernetFrame("ethernet-frame"); // subclassed from cPacket
    ethf->setByteLength(26);
    ethf->encapsulate((cPacket*)payload);
    //ev << ethf->getByteLength() << endl; // --> 26+1498 = 1524
    //splitter(ethf);
    send(ethf,"phys$o");
    EV << "I'm EtherCatMACMaster and send "<< ethf << "to Slave\n";
    //}
}
void EtherCatMACMaster::splitter(EthernetFrame *ethf){
    split8 s;
    split8 s2;
   //s.getVector(ethf->getHeader(0));
   // s.getVector(ethf->getHeader(8));
    EV << "1:" << s.getBitLength() << endl;
    EV << "2:" << s.getByteLength() << endl;
    EV << "3:" << s.getClassName() << endl;
    EV << "4:" << s.getContextPointer() << endl;
    EV << "5:" << s.getControlInfo() << endl;
    EV << "6:" << s.getDescriptor() << endl;
    EV << "7:" << s.getFullName() << endl;
    EV << "8:" << s.getVector(0) << endl;
    EV << "9:" << s.getVectorArraySize() << endl;
    EV << "10:" << s.getParList() << endl;
    EV << "11:" << s.getParList() << endl;
    //EV << "Header2:" << ethf->getHeader(3) << endl;
    //EV << "HeaderSize:" <<ethf->getByteLength() << endl;
}


