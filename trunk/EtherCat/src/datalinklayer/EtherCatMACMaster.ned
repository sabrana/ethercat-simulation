package ethercat.datalinklayer;

simple EtherCatMACMaster 
{
    parameters:
        double delay;
        bool onlyEndPdu;
        int probabiltyGlobalFrame;
        //bool enable_arb_pen;
        int scenario=default(1);
        int nFrameToSend;
        int typeOfDeadline;//relative=1,absolute=2
	gates:
		inout phys;
		input upperLayerIn;
        output upperLayerOut;
	

}
