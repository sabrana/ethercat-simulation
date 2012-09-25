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

#include "SlaveApplication.h"
#include "EtherCatFrame_m.h"

Define_Module(SlaveApplication);

void SlaveApplication::initialize()
{
    // TODO - Generated method body
}

void SlaveApplication::handleMessage(cMessage *msg)
{
    EV << "I'm EtherCatApplicationSlave and receive payload "<< msg << "\n";
    EtherCatFrame *payload = (EtherCatFrame*)msg;
    srand ( time(NULL) );
    int ns=rand() % 100;
    _sleep((ns/100000)*payload->getByteLength());
    send(msg,"out");
    EV << "I'm MasterApplication and RE-send payload"<< msg << "\n";

}
