package ethercat.datalinklayer;


simple EtherCatMACSlave 
{
    gates:
        inout phys1;
        inout phys2;
        input upperLayerIn;
        output upperLayerOut;   
}
