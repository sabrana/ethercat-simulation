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

Define_Module(EtherCatMACMaster);

void EtherCatMACMaster::initialize()
{
    // TODO - Generated method body
}

void EtherCatMACMaster::handleMessage(cMessage *msg)
{
    EV << "I'm EtherCatMACMaster and receive "<< msg << "\n";
    send(msg,"upperLayerOut");
    EV << "I'm EtherCatMACMaster and re-send "<< msg << "\n";
}


