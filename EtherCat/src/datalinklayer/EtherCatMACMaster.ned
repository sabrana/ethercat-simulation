package ethercat.datalinklayer;

simple EtherCatMACMaster 
{
    parameters:
        double delay;
        bool onlyEndPdu;
        int probabiltyGlobalFrame;
        int nFrameToSend;
	gates:
		inout phys;
		input upperLayerIn;
        output upperLayerOut;
	

}
