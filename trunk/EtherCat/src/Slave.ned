package ethercat;
import ethercat.applicationlayer.*;
import ethercat.datalinklayer.*;

module Slave
{
    parameters:
        int indice;
        @display("i=misc/node_vs;bgb=173,164");
    gates:
        inout prev;
        inout next;
    submodules:
        application: SlaveApplication {
            @display("p=83,34;is=vl");
        }
        mac: EtherCatMACSlave {
            indice=indice;
            @display("p=83,119");
        }
    connections allowunconnected:
        application.out --> mac.upperLayerIn;
        application.in <-- mac.upperLayerOut;
        mac.phys1 <--> prev;
        mac.phys2 <--> next;
}
