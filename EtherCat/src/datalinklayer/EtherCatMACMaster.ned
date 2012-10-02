package ethercat.datalinklayer;

simple EtherCatMACMaster 
{
    parameters:
        double delay;
	gates:
		inout phys;
		input upperLayerIn;
        output upperLayerOut;
	

}
