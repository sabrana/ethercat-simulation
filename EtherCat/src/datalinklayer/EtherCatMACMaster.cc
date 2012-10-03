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
        delay=par("delay");
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


            int byte=1;

            //preamble ethernet frame
            for(byte; byte<=7; byte++){
                //preamble ethernet frame
                ev << "Adding " << byte <<" /7 packet of preamble ethernet frame";
                cPacket *c=new cPacket("Preamble");
                c->setByteLength(1);
                scheduleAt(simTime()+delay*byte, c->dup());
            }

            //SFD ethernet frame
            for(byte; byte<=8; byte++){
                ev << "Adding " << byte-7 <<"/1 packet of SFD ethernet frame";
                cPacket *c=new cPacket("SFD");
                c->setByteLength(1);
                scheduleAt(simTime()+delay*byte, c->dup());
            }

            //Destination MAC Address ethernet frame
            for(byte; byte<=14; byte++){
                //preamble ethernet frame


                ev << "Adding " << byte-8 <<" /6 packet of DA ethernet frame";
                cPacket *c=new cPacket("DA");
                c->setByteLength(1);
                scheduleAt(simTime()+delay*byte, c->dup());
            }

            //Source MAC Address ethernet frame
            for(byte; byte<=20; byte++){
                //preamble ethernet frame
                ev << "Adding " << byte-14 <<" /6 packet of SA ethernet frame";
                cPacket *c=new cPacket("SA");
                c->setByteLength(1);
                scheduleAt(simTime()+delay*byte, c->dup());
            }

            //EtherType ethernet frame
            for(byte; byte<=22; byte++){
                ev << "Adding " << byte-16 <<" /2 packet of EtherType ethernet frame";
                cPacket *c=new cPacket("EtherType");
                c->setByteLength(1);
                scheduleAt(simTime()+delay*byte, c->dup());
            }

            //PayLoad ethernet frame
            cPacket* payload=(cPacket*)msg;
            EtherCatFrame* frame=(EtherCatFrame*)msg;
            this->valueData=frame->getData();
            int dim_payload=payload->getByteLength();
            for(byte; byte<=dim_payload+22; byte++){
                ev << "Adding " << byte-22 <<" /1498 packet of PayLoad ethernet frame";

                cPacket *c=new cPacket("PayLoad");
                c->setByteLength(1);
                scheduleAt(simTime()+delay*byte, c->dup());
            }

            //FCS ethernet frame
            for(byte; byte<=dim_payload+26; byte++){
                ev << "Adding " << byte-(1500+22) <<" /4 packet of FCS ethernet frame";
                cPacket *c=new cPacket("FCS");
                c->setByteLength(1);
                scheduleAt(simTime()+delay*byte, c->dup());
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
       if(strcmp(msg->getName(),"PayLoad")==0){
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



