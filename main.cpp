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

class Dest_Address
{
    uint okt1, okt2, okt3, okt4;
    string strAddr;
public:
    Dest_Address() : okt1{0}, okt2{0}, okt3{0}, okt4{0}
    {
        strAddr = to_string(okt1) + "." + to_string(okt2) + "." +
                  to_string(okt3) + "." + to_string(okt4);
    }
    Dest_Address(uint ok1, uint ok2, uint ok3, uint ok4)
    {
        strAddr = to_string(ok1) + "." + to_string(ok2) + "." +
                  to_string(ok3) + "." + to_string(ok4);
        okt1 = ok1 , okt2 = ok2, okt3 = ok3, okt4 = ok4;
    }
    string getAddr() { return strAddr; }
    uint _okt1() const { return okt1; }
    uint _okt2() const { return okt2; }
    uint _okt3() const { return okt3; }
    uint _okt4() const { return okt4; }

};

class Pcap_dump
{
    pair<long, long> timestamp;
    Dest_Address dest_addres;
    string DestAddr;
    uint DestPort;
    uint usefulDataSize;
    string cmp_str(string a, string b);
public:
    Pcap_dump() : timestamp{make_pair(0,0)}, DestAddr{"0.0.0.0"},
                  DestPort{0}, usefulDataSize{0} {}
    Pcap_dump(pair<long, long> tmstp, Dest_Address dest_addr, uint DestP, uint uDataSz);
    void show()
    {
        cout << "TimeStamp: " << timestamp.first << "." << timestamp.second << ", "
             << "Destination: " << DestAddr
             << ", Port: " << DestPort << ", "
             << "Useful data size: " << usefulDataSize << " bytes" << endl;
     }
    friend bool Comparer(const Pcap_dump& a, const Pcap_dump& b);
};

bool Comparer(const Pcap_dump& a, const Pcap_dump& b)
{
    return ( a.dest_addres._okt1() <= b.dest_addres._okt1() ||
             a.dest_addres._okt1() == b.dest_addres._okt1() &&
             a.dest_addres._okt2() <= b.dest_addres._okt2() ||
             a.dest_addres._okt2() == b.dest_addres._okt2() &&
             a.dest_addres._okt3() <= b.dest_addres._okt3() ||
             a.dest_addres._okt3() == b.dest_addres._okt3() &&
             a.dest_addres._okt4() <= b.dest_addres._okt4());
}

Pcap_dump::Pcap_dump(pair<long, long> tmstp, Dest_Address dest_addr, uint DestP, uint uDataSz)
{
    timestamp = tmstp;
    dest_addres = dest_addr;
    DestAddr = dest_addr.getAddr();
    DestPort = DestP;
    usefulDataSize = uDataSz;
}

bool ip_addr_checker(string str_ip)
{

}




int main(int argc, char* argv[])
{
    string search_addr = "0.0.0.0";
    string file = "data2.pcap";
    string port_ = "0";

    if (argc == 1) {
            cout << "no arguments given or wrong arguments" << endl;
            cout << " -a        Address filter, Usage: /print_pcap -a 192.168.1.22 file.pcap" << endl;
            cout << " -p        Port filter ./print_pcap -a 192.168.1.22 -p 9991 file.pcap" << endl;
            exit(0);
        }
    if (argc == 2) {
        file = file = static_cast<string>(argv[1]);
    }
    else if (argc == 4) {
        if ((argv[1])[1] == 'a') {
                search_addr = static_cast<string>(argv[2]);
                file = static_cast<string>(argv[3]);
            }
        }
    else if (argc == 6) {
            if ((argv[3])[1] == 'p') {
                    search_addr = static_cast<string>(argv[2]);
                    port_ = static_cast<string>(argv[4]);
                    file = static_cast<string>(argv[5]);
                }
        }
    else {
            cout << "no arguments given or wrong arguments" << endl;
            cout << " -a        Address filter, Usage: /print_pcap -a 192.168.1.22 file.pcap" << endl;
            cout << " -p        Port filter ./print_pcap -a 192.168.1.22 -p 9991 file.pcap" << endl;
            return 0;
        }


    cout << argc << endl;
    cout << search_addr << endl;
    cout << file << endl;
    cout << port_ << endl;


      //string file = "data2.pcap";
      char errbuff[PCAP_ERRBUF_SIZE]; // Create an char array to hold the error.
      pcap_t * pcap = pcap_open_offline(file.c_str(), errbuff); //Open the file and store result in pointer to pcap_t
      struct pcap_pkthdr *header; //Create a header and a data object
      const u_char *data;
      string byte_port; /* binary performance */
      string DestAddress;
      uint DestPort = 0;
      vector<int> vec;
      vector<Pcap_dump> pcapvec;
      //DestAddress addr;

      //Loop through packets and print them to screen
      while (pcap_next_ex(pcap, &header, &data) >= 0) {
              for (u_int i = 0; i < header->caplen; ++i) {
                      int dt = data[i];
                      vec.push_back(dt);
                  }
              int Protocol = vec.at(23); // this is the protocol byte
              // for UDP Protocol must be 17
              if (Protocol == 17) {
                      Dest_Address addr(vec.at(30), vec.at(31), vec.at(32), vec.at(33));

                      for(size_t i = 30; i <= 33; ++i) {
                              DestAddress += to_string(vec.at(i)) + ".";
                          }
                      byte_port =  int_to_byte_string(vec.at(36));
                      byte_port += int_to_byte_string(vec.at(37));
                      DestPort = byte_string_to_int(byte_port);

                      pcapvec.push_back(Pcap_dump(make_pair(header->ts.tv_sec, header->ts.tv_usec),
                                       addr,
                                       DestPort,
                                       (header->len - 42)));
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
                      vec.clear();
                      vec.shrink_to_fit();
                  }
              DestAddress = "";
          }

      /*for (auto& elem : pcapvec)
          elem.show();*/

      return 0;
}
