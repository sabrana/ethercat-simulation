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

#ifndef __ETHERCAT_ETHERCATMACSLAVE_H_
#define __ETHERCAT_ETHERCATMACSLAVE_H_

#include <omnetpp.h>

/**
 * TODO - Generated class
 */
class EtherCatMACSlave : public cSimpleModule
{
  private:
    simtime_t delay;
    cQueue queue;
    cMessage *event; // pointer to the event object which we'll use for timing
    cMessage *tempMsg; // variable to remember the message until we send it back
    int counter;
    int relativeDeadline;
    int node;
    int nContestWin;
  public:
    EtherCatMACSlave();
    virtual ~EtherCatMACSlave();

  protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
    virtual void finish();
    virtual bool checkPriority(cMessage *msg);
    virtual void queueGenerator();
};

#endif
