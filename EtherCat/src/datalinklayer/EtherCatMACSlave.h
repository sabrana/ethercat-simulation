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
    double time1;
    double time2;
    double time3;

    cQueue queue;
    cQueue queueTemp;
    cQueue queueSched;
    cQueue timeStampQueue;
    cQueue bornTimeStamp;

    int percHigh;
    int percMedium;

    bool level1;
    bool level2;
    bool level3;

    bool setLevel;

    int globalPacket;
    bool enable_arb_pen;
    bool swapper;
    int scenario;
    int typeOfDeadline;//relative=1,absolute=2
    double prob;
    bool underControl; // Se ho scritto nella frame, setto una flag in maniera tale da
                       // non riscrivere lo stesso valore nella frame successiva
    double absoluteDeadline;
    unsigned int indice;
    double timeStart; // corrisponde ad identificare la frame attraverso un timeStamp del Master
                   // alla partenza della frame
    int nContestWin;
    char priority[8];// for like-can configuration
  public:
    EtherCatMACSlave();
    virtual ~EtherCatMACSlave();

  protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
    virtual void finish();
    void setDeadlineOnFrame(cMessage *msg);
    void queueGenerator();
    bool controlIfIwon(cMessage *msg);
    bool test(const char* a ,const char* b);
    int sortQueue(cMsgPar *bitWise);
    void checkIfIWinOnArbPend(cMessage *msg);
};

#endif
