
package ethercat;

import ethercat.physicallayer.EthernetLine;


network DaisyChain
{
    parameters:
        int n = default(5);
    submodules:
        
        master: Master;
        slave[n]: Slave {
            @display("p=,,ring,");
            
        }

    connections allowunconnected:
        master.gate  <--> EthernetLine <--> slave[0].prev;
        for i=0..n-2 {
            slave[i].next <--> EthernetLine <--> slave[(i+1)].prev;
        }
}
