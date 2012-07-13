package ethercat.datalinklayer;


simple EtherCatMACSlave extends EtherCatMAC
{
    gates:
        input upperLayerIn;
        output upperLayerOut;
        inout phys1;
        inout phys2;
    
}
