package ethercat.datalinklayer;


simple EtherCatMACSlave 
{
    parameters:
        double delay;
        int scenario=default(1);
        int probability=default(50);
        int typeOfDeadline;//relative=1,absolute=2
        bool swapper=default(false);
        bool enable_arb_pen;
    gates:
        inout phys1;
        inout phys2;
        input upperLayerIn;
        output upperLayerOut;   
}
