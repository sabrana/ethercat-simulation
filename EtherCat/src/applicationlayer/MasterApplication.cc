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

Define_Module(MasterApplication);

void MasterApplication::initialize()
{
    cPacket *payload = new cPacket("payload");
    payload->setByteLength(1498);
    EV << "I'm MasterApplication and send payload"<< payload << "\n";
    send(payload,"out");
}

void MasterApplication::handleMessage(cMessage *msg)
{
    EV << "I'm MasterApplication and re-send "<< msg << "\n";
    send(msg,"out");
}
