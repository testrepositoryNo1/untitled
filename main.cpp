#include <iostream>
#include <fstream>
#include <string>
#include <iostream>
#include <pcap.h>
#include <vector>

using namespace std;

int main()
{
    string file = "data.pcapng";
    char errbuff[PCAP_ERRBUF_SIZE]; // Create an char array to hold the error.

    pcap_t * pcap = pcap_open_offline(file.c_str(), errbuff); //Open the file and store result in pointer to pcap_t

    struct pcap_pkthdr *header; //Create a header and a data object

    // Create a character array using a u_char
    // u_char is defined here:
    // typedef unsigned char   u_char;
    const u_char *data;
    vector<int> vec;
    //Loop through packets and print them to screen
    u_int packetCount = 0;
    while (int returnValue = pcap_next_ex(pcap, &header, &data) >= 0) {
            for (u_int i=0; (i < header->caplen ) ; i++) {
                    int dt = data[i];
                    vec.push_back(dt);
                }
            int Protocol = vec.at(23); // this is thr protocol byte
            // Protocol = 17 for UDP
            if (Protocol == 17) {
                    cout << dec << "Packet # " << ++packetCount << endl;
                    // Show the size in bytes of the packet
                    cout << dec << "Packet size: " << header->len << " bytes" << endl;
                    printf("Epoch Time: %d:%d seconds\n", header->ts.tv_sec, header->ts.tv_usec);
                    // Show a warning if the length captured is different
                    if (header->len != header->caplen) {
                            cout << "Warning! Capture size different than packet size: " << header->len << "bytes" << endl;
                        };

                    // loop through the packet and print it as hexidecimal representations  of octets
                    // We also have a function that does this similarly below: PrintData()
                    for (u_int i = 0; i < header->caplen; ++i) {
                            // Start printing on the next after every 16 octets
                            if ( (i % 16) == 0) {
                                    cout << "\n";
                                };

                            // Print each octet as hex (x), make sure there is always two characters (.2).
                            //printf("%.2x ", data[i]);
                            int dt = data[i];
                            cout << hex << dt << " ";
                            //cout.unsetf (ios::hex);
                        }
                    cout << "\n\n" << flush;
                    vec.clear();
                    vec.shrink_to_fit();
                }
            else  {
                    ++packetCount;
                    vec.clear();
                    vec.shrink_to_fit();
                }
        }
}

