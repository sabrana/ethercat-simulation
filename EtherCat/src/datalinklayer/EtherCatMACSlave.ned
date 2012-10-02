package ethercat.datalinklayer;


simple EtherCatMACSlave 
{
    parameters:
        double delay;
    gates:
        inout phys1;
        inout phys2;
        input upperLayerIn;
        output upperLayerOut;   
}
