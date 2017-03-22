#include <iostream>
#include <fstream>
#include <string>
#include <iostream>
#include <pcap.h>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <netinet/in.h>
#include <netinet/ip.h>
#include <net/if.h>
#include <netinet/if_ether.h>
#include <bitset>
#include <cstdlib>
#include "stdfx.h"


using namespace std;

/* int to byte string */
string int_to_byte_string(int i)
{
      bitset<8> bs(i);
      return bs.to_string();
}

/* byte string to int */
int byte_string_to_int(const string& byte_port)
{
      int int_port = 0;
      for (size_t i = 0, j = byte_port.size(); i < byte_port.size(); ++i, --j) {
              if (byte_port.at(i) == '1'){
                      int_port += pow(2, j - 1);
                  }
          }
      return int_port;
}

//<Таймстемп захвата пакета> <Адрес назначения> <Порт назначения> <размер полезных данных в UDP пакете>

class Pcap_dump
{
    pair<long, long> timestamp;
    string DestAddr;
    uint DestPort;
    uint usefulDataSize;
public:
    Pcap_dump() : timestamp{make_pair(0,0)}, DestAddr{"0.0.0.0"},
                  DestPort{0}, usefulDataSize{0} {}
    Pcap_dump(pair<long, long> tmstp, string DestA, uint DestP, uint uDataSz);
    void show()
    {
         DestAddr.pop_back();
         cout << "TimeStamp: " << timestamp.first << "." << timestamp.second << ", "
              << "Destination: " << DestAddr << ", "
              << ", Port: " << DestPort << ", "
              << "Useful data size: " << usefulDataSize << " bytes" << endl;
     }
};

Pcap_dump::Pcap_dump(pair<long, long> tmstp, string DestA, uint DestP, uint uDataSz)
{
    timestamp = tmstp;
    DestAddr = DestA;
    DestPort = DestP;
    usefulDataSize = uDataSz;
}




int main(int argc, char* argv[])
{


      string file = "data2.pcap";
      char errbuff[PCAP_ERRBUF_SIZE]; // Create an char array to hold the error.
      pcap_t * pcap = pcap_open_offline(file.c_str(), errbuff); //Open the file and store result in pointer to pcap_t
      struct pcap_pkthdr *header; //Create a header and a data object
      const u_char *data;
      size_t packetCount = 0;
      string byte_port; /* binary performance */
      string DestAddress;
      uint DestPort = 0;
      vector<int> vec;
      //Pcap_dump object;


      //Loop through packets and print them to screen
      while (int returnValue = pcap_next_ex(pcap, &header, &data) >= 0) {
              for (u_int i=0; i < header->caplen; ++i) {
                      int dt = data[i];
                      vec.push_back(dt);
                  }
              int Protocol = vec.at(23); // this is the protocol byte
              // for UDP Protocol must be 17
              if (Protocol == 17) {
                     /* cout << dec << "No." << ++packetCount << ", ";
                      /*cout << "TimeStamp: "
                           << header->ts.tv_sec << "."
                           << header->ts.tv_usec  << " seconds, "; */
                     /* cout << "Destination: ";*/
                      for(size_t i = 30; i <= 33; ++i) {
                              //cout << dec << vec.at(i) << ".";
                              DestAddress += to_string(vec.at(i)) + ".";
                          }
                      byte_port =  int_to_byte_string(vec.at(36));
                      byte_port += int_to_byte_string(vec.at(37));
                      DestPort = byte_string_to_int(byte_port);
                      /*cout << "\b, Port: " << DestPort << ", ";
                      cout << "Useful data size: "
                           << header->len - 42 << " bytes" << endl;*/

                      Pcap_dump object(make_pair(header->ts.tv_sec, header->ts.tv_usec),
                                          DestAddress,
                                          DestPort,
                                          (header->len - 42));
                      object.show();
                    // Show a warning if the length captured is different
                      if (header->len != header->caplen) {
                              cout << "Warning! Capture size different than packet size: "
                                   << header->len << "bytes" << endl;
                          };

                      /*
                       * use for debuging ***
                       // loop through the packet and print it as hexidecimal representations  of octets
                      // We also have a function that does this similarly below: PrintData()
                      for (u_int i = 0; i < header->caplen; ++i) {
                            // Start printing on the next after every 16 octets
                            if ( (i % 16) == 0) {
                                    cout << "\n";
                                };
                            int dt = data[i];
                            cout << hex << dt << " ";
                            //cout.unsetf (ios::hex);
                        }
                      cout << "\n\n" << flush;*/

                      vec.clear();
                      vec.shrink_to_fit();
                  }
              else  {
                      ++packetCount;
                      vec.clear();
                      vec.shrink_to_fit();
                  }
              DestAddress = "";
          }


      return 0;
}
