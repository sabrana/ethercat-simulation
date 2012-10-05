//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

//
// TODO generated message class
//
struct type12PDU
{
    unsigned char CMD; // 0x01 command APRD
    unsigned char IDX; // Index
    short ADP; // auto increment address
    short ADO; // Physical memory or register address
    int LEN; // unsigned 11bit
    char reserved; // unsigned 3bit
    bool C;// unsigned 1bit
    bool NEXT; // unsigned 1bit
    short IRQ; //External event 
    char DATA; // Data, structure as specified in 5.6, 6 or by DLS-user
    short WKC; //Working counter
}

packet EtherCatFrame {
    int length;
    char reserved;
    char type;
    type12PDU pdu[115];
   
}
