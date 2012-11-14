package ethercat.datalinklayer;


simple EtherCatMACSlave 
{
    parameters:
        double delay;
        int scenario=default(1);
        int probability=default(50);
    gates:
        inout phys1;
        inout phys2;
        input upperLayerIn;
        output upperLayerOut;   
}
