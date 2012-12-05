
package ethercat;

import ethercat.physicallayer.EthernetLine;


network DaisyChain
{
    parameters:
        int n = default(5);
        master.mac.delay = default(1);
        slave[*].mac.delay = default(1);
        @display("bgb=523,309;bgl=8");
    submodules:

        master: Master {
            @display("is=s;p=253,54");

        }
        slave[n]: Slave {
            indice=index;
            @display("p=253,122,ring");

        }

    connections allowunconnected:
        master.gate <--> EthernetLine <--> slave[0].prev;
        for i=0..n-2 {
            slave[i].next <--> EthernetLine <--> slave[(i+1)].prev;
        }
}
