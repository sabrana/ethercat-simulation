package ethercat.physicallayer;

channel EthernetLine  extends EtherLink {
    //delay = 0.1us; //0
    datarate=100Mbps;// 10
}

channel EtherLink extends ned.DatarateChannel
{
    double length @unit(m) = default(10m);
    delay = replaceUnit(length / 2e8, "s");
}