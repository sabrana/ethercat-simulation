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

#include "MasterApplication.h"
#include "EtherCatFrame_m.h"

Define_Module(MasterApplication);

void MasterApplication::initialize()
{


    EtherCatFrame *payload = new EtherCatFrame("payload");

    //simuliamo di fare tanti PDU quanti sono gli slave a disposizione
    int dimPayload=2;

    int dimMaxSet=1498;

    int npdu=par("pdu_number");

    //int dim_pdu=1498-npdu+1;
    int dim_max_pdu=1498/npdu;


    for(int i=1;i<=npdu;i++){
        int dimPDU=100;//uniform(13,dim_max_pdu);

        payload->getPdu(i).LEN=dimPDU;
        //setto i valori degli indirizzi sequenziali
        payload->getPdu(i).ADP=-i;

        dimPayload+=dimPDU;
        ev<< "dim PDU: "<<dimPDU<<"; dim payload"<<payload<<"" <<i<<" "<<dimPayload<<"\n";
        //dim_pdu-=dimPayload;
    }
    payload->setLength(dimPayload);
    payload->setByteLength(dimPayload);//Ethercat Datagram

    EV << "I'm MasterApplication and send payload"<< payload << "of "<< payload->getByteLength() <<" length\n";
    send(payload,"out");
    //scheduleAt(5.0, payload->dup());


}

void MasterApplication::handleMessage(cMessage *msg)
{

    EV << "I'm MasterApplication and re-send "<< msg << "\n";
    send(msg,"out");


}
