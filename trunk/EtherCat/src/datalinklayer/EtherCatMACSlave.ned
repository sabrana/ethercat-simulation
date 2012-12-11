package ethercat.datalinklayer;


simple EtherCatMACSlave 
{
    parameters:
        int indice;
        double delaySlave;
        double time1;
        double time2;
        double time3;
        int percHigh;
    	int percMedium;
        int scenario=default(1);
        double probability=default(50);
        int typeOfDeadline;//relative=1,absolute=2
        bool swapper=default(false);
        //bool enable_arb_pen;
    gates:
        inout phys1;
        inout phys2;
        input upperLayerIn;
        output upperLayerOut;   
}
