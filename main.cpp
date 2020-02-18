#include <iostream>

#include<cstdlib>

#include<fstream>

#include<ctime>

#include <map>

#include <iterator>


using namespace std;

void CheckThis (string document, int t, int ex [] ) {

            if (document.size() < 2) {
               cout << "FORMATING ERROR " << document << endl;
               exit(1);
            }
            if (t != char(document[0])) {
               cout << "MISSING LETTER " << char(t) << endl;
               exit(1);
            }
            if (ex[document[1] - 'a'] != 0) {
               cout << "DUPLICATE CIPHERTEXT " << document[1] << endl;
               exit(1);
            }
            if (document[0] == document[1]) {
               cout << "MAPPING ERROR " << document[0] << endl;
               exit(1);
            }
}
/*************** Encryption using Caesar Cipher******************/
void EncryptionCaesarCipher(string phrase, map < char, char > & enCryption){
    for(int i = 0; i < phrase.size(); i++)
        {
            for(std:: map<char, char>::iterator it = enCryption.begin(); it != enCryption.end(); it++)
            {
                if(phrase[i] == it->first)
                {
                    cout << it -> second;
                }
                else if(phrase[i] == toupper(it->first))
                {
                    cout << char(toupper(it -> second));
                }
            }
            if(!isalpha(phrase[i]))
            {
                cout << phrase[i];
            }
        }
}

/*************** Decryption using Caesar Cipher******************/

void DecryptionCaesarCipher(string phrase, map < char, char > & deCryption){
    for(int i = 0; i < phrase.size(); i++)
    {
        for(std:: map<char, char>::iterator it = deCryption.begin(); it != deCryption.end(); it++)
        {
            if(phrase[i] == it->first)
            {
                cout << it -> second;
            }
            else if(phrase[i] == toupper(it->first))
            {
                cout << char(toupper(it -> second));
            }
        }
        if(!isalpha(phrase[i]))
        {
            cout << phrase[i];
        }
    }
}

void ARGUEMENT4 (int argc, char*argv[]){
  map<char, char> enCryption;
  map<char, char> deCryption;

 
   if (string(argv[1]) == "-e" && argc == 4)     {
        string document;
        string sent;
        ifstream myFile(argv[2]);
        ifstream sentFile(argv[3]);
        int temp = 'a';
        int ex[26];

        for(int i = 0; i < 26; i++)
        {
            ex[i] = 0;
        }

        if(myFile.is_open() == false)
        {
            cout << argv[2] << " DICTIONARY COULD NOT BE OPENED" << endl;
            exit(1);
        }
        else
        {
            while(getline(myFile, document))
            {
                if(document.size() < 2)
                {
                    cerr << "FORMATTING ERROR " << document << endl;
                    exit(1);
                }
                if(temp != char(document[0]))
                {
                    cerr << "MISSING LETTER " << char(temp) << endl;
                    exit(1);
                }
                if(ex[document[1] - 'a'] != 0)
                {
                    cout << "DUPLICATE CIPHERTEXT " << document[1] << endl;
                    exit(1);
                }
                if(document[0] == document[1])
                {
                    cerr << "MAPPING ERROR " << document[0] << endl;
                    exit(1);
                }
                enCryption[document[0]] = document[1];
                ex[document[1] - 'a'] = 1;
                temp++;
            }
            myFile.close();
        }
        if(sentFile.is_open() == false)
        {
            cout << argv[3] << " FILE COULD NOT BE OPENED" << endl;
            exit(1);
        }

        sent.assign( (istreambuf_iterator<char>(sentFile) ), (istreambuf_iterator<char>()) );

        EncryptionCaesarCipher(sent, enCryption);
    }
else if (string(argv[1]) == "-d" && argc == 4) {

      map < char, char > deCryption;
      string document;
      string syn;
      ifstream infile(argv[2]);
      ifstream phraseFile(argv[3]);
      int t = 'a';
      int ex[26];

      for (int i = 0; i < 26; i++) {
         ex[i] = 0;
      }
    if (infile.is_open() == false) {
         cout << string(argv[1]) << " DICTIONARY COULD NOT BE OPENED" <<
            endl;
      }
    else
    {
      while (getline(infile, document)) {
         if (document.size() < 2) {
            cerr << "FORMATING ERROR " << document << endl;
            exit(1);
         }
         if (t != char(document[0])) {
            cerr << "MISSING LETTER " << char(t) << endl;
            exit(1);
         }
         if (ex[document[1] - 'a'] != 0) {
            cerr << "DUPLICATE CIPHERTEXT " << document[1] << endl;
            exit(1);
         }
         if (document[0] == document[1]) {
            cerr << "MAPPING ERROR " << document[0] << endl;
            exit(1);
         }
            deCryption[document[1]] = document[0];
            ex[document[1] - 'a'] = 1;
            t++;
      }
         infile.close();
    }
         if(phraseFile.is_open() == false){

            cout << argv[3] << " THE FILE COULD NOT BE OPENED" << endl;
            exit (1);
         }

         syn.assign((istreambuf_iterator < char > (phraseFile)), (istreambuf_iterator < char > ()));
         DecryptionCaesarCipher(syn, deCryption);


   }
 
}


void ARGUEMENT3 (int argc, char*argv[]){
 if (string(argv[1]) == "-e" && argc == 3) {
      map < char, char > enCryption;
      ifstream infile;
      string document;
      string syn;
      int t = 'a';
      int ex[26];

      infile.open(argv[2]);
      for (int i = 0; i < 26; i++) {
         ex[i] = 0;
      }

      if (infile.is_open() == false) {
         cout << argv[2] << " DICTIONARY COULD NOT BE OPENED" << endl;
         exit(1);
      } else {
         while (getline(infile, document)) {

            if (document.size() < 2) {
               cout << "FORMATING ERROR " << document << endl;
               exit(1);
            }
            if (t != char(document[0])) {
               cout << "MISSING LETTER " << char(t) << endl;
               exit(1);
            }
            if (ex[document[1] - 'a'] != 0) {
               cout << "DUPLICATE CIPHERTEXT " << document[1] << endl;
               exit(1);
            }
            if (document[0] == document[1]) {
               cout << "MAPPING ERROR " << document[0] << endl;
               exit(1);
            }

            enCryption[document[0]] = document[1];
            ex[document[1] - 'a'] = 1;
            t++;
         }
         infile.close();
      }
      getline(cin, syn);
      EncryptionCaesarCipher(syn, enCryption);

   }
 
 if (string(argv[1]) == "-d" && argc == 3) {
      string document;
      string syn;
      ifstream infile;
      int t = 'a';
      int ex[26];

      map < char, char > deCryption;

      infile.open(argv[2]);

      for (int i = 0; i < 26; i++) {
         ex[i] = 0;
      }

      if (infile.is_open() == false) {
         cout << argv[2] << " DICTIONARY COULD NOT BE OPENED" << endl;
         exit(1);
      }

      else {
         while (getline(infile, document)) {
            if (document.size() < 2) {
               cout << "FORMATING ERROR " << document << endl;
               exit(1);
            }
            if (t != char(document[0])) {
               cout << "MISSING LETTER " << char(t) << endl;
               exit(1);
            }
            if (ex[document[1] - 'a'] != 0) {
               cout << "DUPLICATE CIPHERTEXT " << document[1] << endl;
               exit(1);
            }
            if (document[0] == document[1]) {
               cout << "MAPPING ERROR " << document[0] << endl;
               exit(1);
            }
            deCryption[document[1]] = document[0];
            ex[document[1] - 'a'] = 1;
            t++;
         }
         infile.close();
      }

      while (getline(cin, syn)) {
         DecryptionCaesarCipher(syn, deCryption);
         cout << endl;
      }
   }

   else if (string(argv[1]) == "-d" && argc < 3) {
      cout << "NO DICTIONARY GIVEN" << endl;
      exit(1);
   }

   else {
      cout << string(argv[1]) << " NOT A VALID COMMAND" << endl;
   }

}
/********ROT13 Configuration***********/
void rot13(string document) {

   string phrase = document;

   int length;
   length = phrase.size();

   for (int i = 0; i < length; i++) {

      if (isalpha(phrase[i])) {

         for (int change = 0; change < 13; change++) {

            if (islower(phrase[i])) {

               if (phrase[i] == 'z') {

                  phrase[i] = 'a';

               } else

                  phrase[i]++;
            } else {
               if (phrase[i] == 'Z') {

                  phrase[i] = 'A';
               } else

                  phrase[i]++;

            }
         }
      }
   }

   cout << phrase << endl;
}

/************ -g Dictionary function *********/
void cipherDic() {

   int used[26];
   int ranNum;
   char ranChar;
   char newNum;

   for (int i = 0; i < 26; i++) {
      used[i] = 0;
   }

   for (int i = 0; i < 26; i++) {
      ranNum = rand() % 26;
      while (used[ranNum] != 0 || ranNum == i) {
         ranNum = rand() % 26;
      }
      used[ranNum] = 1;
      newNum = 'a' + i;
      ranChar = 'a' + ranNum;
      cout << newNum << ranChar << endl;
      if (newNum == ranChar) {
         cout << "error" << endl;
      }

   }
}

/****** MAIN METHOD **********/
int main(int argc, char * argv[]) {

   string document = "";
 //  int ex[26];
   ifstream infile;

   string encryptText = "";

   /*******IF A COMMAND IS MISSING***********/

   if (argc == 1) {

      cout << "MISSING COMMAND" << endl;

      exit(1);

   }
   if (string(argv[1]) == "-r" && argc < 3) { //OTHERWISE ex FOR -r

      string document;

      while (getline(cin, document)) {
            rot13(document);
      }

   } else if (string(argv[1]) == "-r" && argc == 3) { //OTHERWISE ex FOR -r with a input file.

      string document;

      infile.open(argv[2]);

      if (infile.is_open() == false) {

         cout << argv[2] << " FILE COULD NOT BE OPENED" << endl;

      } else {

         while (getline(infile, document)) {
            rot13(document);
         }
         infile.close();
      }
   } else if (string(argv[1]) == "-g") { //OTHERWISE ex FOR -g
      cipherDic();
   } 
 
 else if (string(argv[1]) == "-e" && argc == 4)     {

        ARGUEMENT4(argc, argv);
    }
    
 
 else if (string(argv[1]) == "-e" && argc == 3) {
      ARGUEMENT3(argc, argv);

   } 
  
 else if (string(argv[1]) == "-d" && argc == 4) {
        ARGUEMENT4(argc, argv);
}

   
 else if (string(argv[1]) == "-d" && argc == 3) {
      ARGUEMENT3(argc, argv);
   }

   
 else if ((string(argv[1]) == "-d" || string(argv[1]) == "-e") && argc < 3) {
      cout << "NO DICTIONARY GIVEN" << endl;
      exit(1);
   }

   
 else {
      cout << string(argv[1]) << " NOT A VALID COMMAND" << endl;
   }
}
