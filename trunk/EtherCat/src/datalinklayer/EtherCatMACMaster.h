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

#ifndef __ETHERCAT_ETHERCATMACMASTER_H_
#define __ETHERCAT_ETHERCATMACMASTER_H_

#include <omnetpp.h>
#include <fstream>
#include "EthernetFrame_m.h"

#include "../applicationlayer/EtherCatFrame_m.h"

/**
 * TODO - Generated class
 */
class EtherCatMACMaster : public cSimpleModule
{
  private:
      simtime_t delay;
      simtime_t delayFrameToFrame;// ritardo tra una frame ethernet ed un altra
      bool onlyEndPdu;
      cQueue queue;
      cQueue queueSched;
      cQueue queueTimeStamp; // quando parte ovvero mando il primo
      cQueue queueTimeStampFinishSend; // quando parte l'ultimo pacchetto della prima frame
      cQueue queueTimeStampCameBack;
      cQueue queueTimeStampCameBackFinish;
      cQueue diffDeadTimestamp;
      int nFrameToSend;
      bool setCameBack;
      bool setStart;
      int countFCS;
      int countFCS2;

      int nGlobalFrame;
      bool enable_arb_pen;
      int typeOfDeadline;//relative=1,absolute=2
      int type1;
      int type2;
      int type3;
      int type4;
      int type5;
      int type6;
      int type7;
      int type8;
      int type9;
      int type10;
      int byteReturn;
      int valueData;
      int scenario;
      const char* previusValue;
      long previusTimestamp;

      int sched;
      int miss;

      double time1;
      double time2;
      double time3;

      double probability;

  public:

    EtherCatMACMaster();
    virtual ~EtherCatMACMaster();

  protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
    virtual void finish();


};

#endif
