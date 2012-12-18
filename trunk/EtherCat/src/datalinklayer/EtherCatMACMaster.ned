package ethercat.datalinklayer;

simple EtherCatMACMaster 
{
    parameters:
        double delayByteToByte;
        double delayFrameToFrame;
        bool onlyEndPdu=default(false);
        int nGlobalFrame;
        //bool enable_arb_pen;
        int scenario=default(1);
        double probability=default(0.1);
        int nFrameToSend;
        int typeOfDeadline;//relative=1,absolute=2
        double time3;
        double time2;
        double time1;
        bool print;
        
	gates:
		inout phys;
		input upperLayerIn;
        output upperLayerOut;
	

}
