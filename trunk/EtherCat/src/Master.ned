package ethercat;
import ethercat.applicationlayer.*;
import ethercat.datalinklayer.*;

module Master
{
    parameters:
        @display("i=misc/node_vs;bgb=153,185");
    gates:
        inout gate;
    submodules:
        application: MasterApplication {
            @display("p=79,46");
        }
        mac: EtherCatMACMaster {
            @display("p=79,135");
        }
    connections allowunconnected:
        application.out --> mac.upperLayerIn;
        application.in <-- mac.upperLayerOut;
        mac.phys <--> gate;


}

