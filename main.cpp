#include "main.h"

using namespace std;

string encrypt(const string& str_in, const string& key)
{
    string str_out;
    CryptoPP::ECB_Mode<CryptoPP::AES>::Encryption encryption((byte*)key.c_str(), key.length());

    CryptoPP::StringSource encryptor(str_in, true,
            new CryptoPP::StreamTransformationFilter(encryption,
                new CryptoPP::Base64Encoder(
                    new CryptoPP::StringSink(str_out),
                    false // do not append a newline
                )
            )
    );
    return str_out;
}

string decrypt(const string& str_in, const string& key)
{
    string str_out;

    CryptoPP::ECB_Mode<CryptoPP::AES>::Decryption decryption((byte*)key.c_str(), key.length());

    CryptoPP::StringSource decryptor(str_in, true,
        new CryptoPP::Base64Decoder(
                new CryptoPP::StreamTransformationFilter(decryption,
                    new CryptoPP::StringSink(str_out)
                )
        )
    );
    return str_out;
}


int main ()
{
      Srand();
      ostream_iterator<int> out(cout, "\n");
      boost::chrono::milliseconds start(clock());
//----------------------------------------------------------------

      /*termios oldt;
      tcgetattr(STDIN_FILENO, &oldt);
      termios newt = oldt;
      newt.c_lflag &= ~ECHO;
      tcsetattr(STDIN_FILENO, TCSANOW, &newt);

      string s;
      cout << "password: ";
      getline(cin, s);
      */


      string str;
      string key = "1234567890123456";

      string str_encrypted,
             str_decrypted;

      ifstream fin("t1.zip", ios_base::binary | ios_base::in);
      ofstream fout("t1.zip.cr", ios_base::binary | ios_base::out);

      while (fin) {
              getline(fin, str);

              try {
                  str_encrypted = encrypt(str, key);
              }
              catch (const CryptoPP::Exception& e) {
                  cerr << e.what() << endl;
              }

              fout << str_encrypted << endl;
              str.clear();
              str_encrypted.clear();
          }

      fin.close();
      fout.close();


      fin.open("t1.zip.cr", ios_base::binary | ios_base::in);
      fout.open("t2.zip", ios_base::binary | ios_base::out);


      while (fin) {
              getline(fin, str);
              try {
                  str_decrypted = decrypt(str, key);
              }
              catch (const CryptoPP::Exception& e) {
                  cerr << e.what() << endl;
              }
              fout << str_decrypted << endl;
          }
      fin.close();
      fout.close();




      cout << CryptoPP::AES::MIN_KEYLENGTH << endl;

//---------------------------------------------------------------
      boost::chrono::milliseconds end(clock());
      using ms = boost::chrono::milliseconds;
      ms dur = boost::chrono::duration_cast<ms>(end - start);
      double dd = dur.count();
      cout << dd / 1000.0 << " sec. = " << end - start << endl;
        return 0;
}


