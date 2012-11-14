package ethercat.datalinklayer;

simple EtherCatMACMaster 
{
    parameters:
        double delay;
        bool onlyEndPdu;
	gates:
		inout phys;
		input upperLayerIn;
        output upperLayerOut;
	

}
