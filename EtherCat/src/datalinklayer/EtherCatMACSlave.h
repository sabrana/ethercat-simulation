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
#include <stdio.h>
#include <stdlib.h>

/**
 * TODO - Generated class
 */
class EtherCatMACSlave : public cSimpleModule
{
  private:
    simtime_t delay;
    cQueue queue;
    cQueue queueTemp;
    int scenario;
    int prob;
    bool underControl; // Se ho scritto nella frame, setto una flag in maniera tale da
                       // non riscrivere lo stesso valore nella frame successiva
    int relativeDeadline;
    int node;
    int timeStart; // corrisponde ad identificare la frame attraverso un timeStamp del Master
                   // alla partenza della frame
    int nContestWin;
  public:
    EtherCatMACSlave();
    virtual ~EtherCatMACSlave();

  protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
    virtual void finish();
    virtual void setDeadlineOnFrame(cMessage *msg);
    virtual void queueGenerator();
    virtual bool controlIfIwon(cMessage *msg);
};

#endif
