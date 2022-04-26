// FCAI – Programming 1 – 2022 - Assignment 2
// Program Name: All_Ciphers.cpp
// Last Modification Date: 27/3/2022
// Author1 and ID and Group: Maryam Osama Mohammed 20211090 A
// Author2 and ID and Group: Youssef Ahmed Zakaria 20210458 A
// Author3 and ID and Group: Saif El-Din Hazem Mohammed 20210165 A


#include <iostream>
#include <string>
#include<cstring>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;
void cipher(string message)
{
    int a =5,b=8;
    string alpha_upper="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string alpha_lower="abcdefghijklmnopqrstuvwxyz";
    for (int i=0; i< message.length(); ++i ) //find each char in message
    {
        if(isupper(message[i]))
        {
            for (int j = 0; j < alpha_upper.length(); ++j)
            {
                if (alpha_upper[j] == message[i]) {
                    cout << alpha_upper[(a * j + b) % 26]; //Printing char whose index fulfills the equation
                }
            }
        }
        else if(islower(message[i]))
        {
            for (int j = 0; alpha_lower.length(); ++j)
            {
                if (alpha_lower[j] == message[i]) {
                    cout << alpha_lower[(a * j + b) % 26]; //Printing char whose index fulfills the equation
                }
            }
        }
        if (message[i]==' ')
            cout<<message[i];
    }
}

void  decipher(string message)
{
    int x;
    int b=8,c=21;
    string alpha_upper="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string alpha_lower="abcdefghijklmnopqrstuvwxyz";
    for (int i=0; i< message.length(); ++i ) //find each char in message
    {
        if(isupper(message[i])) {
            for (int j = 0; j < alpha_upper.length(); ++j) {
                if (message[i] == alpha_upper[j]) {
                    x = c * (j - b);
                    if (x < 0) {
                        while (x < 0) {
                            x += 26;
                        }
                        cout << alpha_upper[x];
                    } else
                        cout << alpha_upper[x % 26];        //Printing char whose index fulfills the equation
                }
            }
        }
        else if(islower(message[i]))
        {
            for (int j = 0; j < alpha_lower.length(); ++j) {
                if (message[i] == alpha_lower[j]) {
                    x = c * (j - b);
                    if (x < 0) {
                        while (x < 0) {
                            x += 26;
                        }
                        cout << alpha_lower[x];
                    } else
                        cout << alpha_lower[x % 26];        //Printing char whose index fulfills the equation
                }
            }
        }
        if (message[i]==' ')
            cout<<message[i];
    }
}

int cipher0()
{
    cout<<"What do you like to do ?"<<endl<<"1- Cipher a message"<<endl<<"2- Decipher a message"<<endl<<"3- End"<<endl;
    int num;
    cin>>num;
    if(num==3)
        return 0;
    string mess="";
    cout<<"enter a message :"<<endl;
    while(mess.empty())
    {
        getline(cin,mess);
    }
    if(num==1)
        cipher(mess);
    else if(num==2)
        decipher(mess);
}
void cipher(string message,int shift)
{
    shift=(shift%26+26)%26;
    string alpha_upper="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string alpha_lower="abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i <message.length(); ++i)
    {
        if(isupper(message[i]))
        {
            for (int j = 0; j < alpha_upper.length(); ++j)
            {
                if (message[i] == alpha_upper[j])
                {
                    if (j + shift <= 25)
                        cout << alpha_upper[j + shift];
                    else if (j + shift > 25)
                        cout << alpha_upper[(j + shift) - 26];
                }
            }
        }
        else if(islower(message[i]))
        {
            for (int j = 0; j < alpha_lower.length(); ++j)
            {
                if (message[i] == alpha_lower[j])
                {
                    if (j + shift <= 25)
                        cout << alpha_lower[j + shift];
                    else if (j + shift > 25)
                        cout << alpha_lower[(j + shift) - 26];
                }
            }
        }
        if(message[i]==' ')
            cout<<' ';
    }
}
void decipher(string message,int shift)
{
    shift=(shift%26+26)%26;
    string alpha_upper="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string alpha_lower="abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i <message.length() ; ++i)
    {
        if(isupper(message[i]))
        {
            for (int j = 0; j < alpha_upper.length(); ++j)
            {
                if (message[i] == alpha_upper[j])
                {
                    if (j - shift >= 0)
                        cout << alpha_upper[j - shift];
                    else if (j - shift < 0)
                        cout << alpha_upper[(j - shift) + 26];
                }
            }
        }
        else if(islower(message[i]))
        {
            for (int j = 0; j < alpha_lower.length(); ++j)
            {
                if (message[i] == alpha_lower[j])
                {
                    if (j - shift >= 0)
                        cout << alpha_lower[j - shift];
                    else if (j - shift < 0)
                        cout << alpha_lower[(j - shift) + 26];
                }
            }
        }
        if(message[i]==' ')
            cout<<' ';
    }
}

int cipher1()
{
    cout<<"What do you like to do ?"<<endl<<"1- Cipher a message"<<endl<<"2- Decipher a message"<<endl<<"3- End"<<endl;
    int num,shift;
    cin>>num;
    if(num==3)
        return 0;
    string mess="";
    cout<<"enter a message :"<<endl;
    while(mess.empty())
    {
        getline(cin,mess);
    }
    cout<<"enter the number of shifts :"<<endl;
    cin>>shift;
    if(num==1)
        cipher(mess,shift);
    else if(num==2)
        decipher(mess,shift);
}

void cipher2(string message)
{
    string upper_case="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string lower_case="abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < message.length(); ++i)
    {
        if(isupper(message[i]))
        {
            for (int j = 0; j < upper_case.length(); ++j) {
                if (message[i] == upper_case[j])
                    cout << upper_case[25 - j];
            }
        }
        else if(islower(message[i]))
        {
            for (int j = 0; j < lower_case.length(); ++j) {
                if (message[i] == lower_case[j])
                    cout << lower_case[25 - j];
            }
        }
        if (message[i]==' ')
            cout<<' ';
    }
}

void decipher2(string message)
{
    string upper_case="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string lower_case="abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < message.length(); ++i)
    {
        if(isupper(message[i]))
        {
            for (int j = 0; j < upper_case.length(); ++j) {
                if (message[i] == upper_case[j])
                    cout << upper_case[25 - j];
            }
        }
        else if(islower(message[i]))
        {
            for (int j = 0; j < lower_case.length(); ++j) {
                if (message[i] == lower_case[j])
                    cout << lower_case[25 - j];
            }
        }
        if (message[i]==' ')
            cout<<' ';
    }
}


int cipher2()
{
    cout<<"What do you like to do ?"<<endl<<"1- Cipher a message"<<endl<<"2- Decipher a message"<<endl<<"3- End"<<endl;
    int num;
    cin>>num;
    if(num==3)
        return 0;
    string mess="";
    cout<<"enter a message :"<<endl;
    while(mess.empty())
    {
        getline(cin,mess);
    }
    if(num==1)
        cipher2(mess);
    else if(num==2)
        decipher2(mess);
}
char userMsg[120];

//Taking Input From User
string checkMessage(){
    cout<<"Enter Message To Encrypt   : \n";
    cin.getline(userMsg,120);

    //All letters capital
    for(int i=0; i<strlen(userMsg); i++)
    {
        if(userMsg[i] >= 'a' && userMsg[i] <= 'z')
            userMsg[i] = char(userMsg[i] - 32);
    }

    return userMsg;
}


string checkKeyword()
{
    char keyWord[8];
    cout<<"Enter your keyword   : \n";
    cin.getline(keyWord,8);

    //All Letters Capital
    for(int i=0; i<strlen(keyWord); i++)
    {
        if(keyWord[i] >= 'a' && keyWord[i] <= 'z')
            keyWord[i] = char(keyWord[i] - 32);
    }
    return keyWord;
}

//Making the keyword .
string repeated_kw(string n_message,string kw){

    if (kw.length()>= n_message.length())
        return kw;
    else{
        int k = n_message.length();

        for(int i = 0;  ;i++)
        {
            if(k == i)
                i = 0;
            if(kw.length() == n_message.length())
                break;
            kw.push_back(kw[i]);
        }
        return kw;
    }
}

string encryption(string msg,string rep_kw )
{
    string encryptedMessage;
    int encode;
    for (int i=0;i <=msg.length(); i++){

        //Checking char is alpha or not.
        if (isalpha(msg[i])) {

            encode = ((char(msg[i]) + char(rep_kw[i])) % 26) +65;
            encryptedMessage += char(encode);
            if(encryptedMessage.length() == msg.length())
                break; }
        else
            encryptedMessage += msg[i];
    }

    return encryptedMessage;
}

string decryption(string msg, string rep_kw)
{
    string decreptedMessage;
    int decode;
    for (int i=0; i<=msg.length(); i++)
    {
        if(isalpha(msg[i]))
        {

            decode = (((char(msg[i]) - char(rep_kw[i]) + 26) % 26) + 65);
            decreptedMessage += char(decode);

            if (decreptedMessage.length() == msg.length())
                break;
        }
        else
            decreptedMessage += msg[i];
    }

    return decreptedMessage;
}
int cipher3()
{
    string Message, keyWord,repeatedkeyword, encryptedmessage, deccreptedMessage;
    int n;
    bool is_ok = true;

    while(is_ok){
        cout<<"1- Encrypt!\n";
        cout<<"2- Decrypt!\n";
        cout<<"3- Exit!\n";
        cin>>n;
        cin.ignore();
        switch(n)
        {
            case 1:
                Message = checkMessage();
                keyWord = checkKeyword();
                cout<<"----------------------------------------------------"<<endl;
                cout<<"The Message : "<<userMsg<< endl;

                repeatedkeyword = repeated_kw(Message,keyWord);
                cout<<"The Repeated Keyword : "<< repeatedkeyword<<"\n";

                encryptedmessage = encryption(Message, repeatedkeyword);
                cout<<"The Encrypted Message : "<<encryptedmessage<<"\n";
                cout<<"--------------------------------------------------------\n";
                break;
            case 2:
                Message = checkMessage();
                keyWord = checkKeyword();
                cout<<"----------------------------------------------------"<<endl;
                cout<<"The Message :"<<userMsg<< endl;

                repeatedkeyword = repeated_kw(Message,keyWord);
                cout<<"The Repeated Keyword : "<< repeatedkeyword<<"\n";

                deccreptedMessage = decryption(Message, repeatedkeyword);
                cout<<"The Decrypted Message : "<<deccreptedMessage<<"\n";
                cout<<"--------------------------------------------------------\n";
                break;
            default:
                is_ok = false;
                break;
        }
    }
}
int cipher4() {
    int choice;
    string message;
    bool isDone = false;
    while (isDone == false) {
        cout << "what do you like to do? \n";
        cout << "\n 1-ciphering \n 2-deciphering \n 3-end program\n";
        cin >> choice;
        switch (choice) {
            case 1: {
                map <string, string> Baconian;
                Baconian["a"] = "aaaaa", Baconian["b"] = "aaaab", Baconian["c"] = "aaaba", Baconian["d"] = "aaabb", Baconian["e"] = "aabaa", Baconian["f"] = "aabab",
                Baconian["g"] = "aabba", Baconian["h"] = "aabbb", Baconian["i"] = "abaaa", Baconian["j"] = "abaab", Baconian["k"] = "ababa", Baconian["l"] = "ababb",
                Baconian["m"] = "abbaa", Baconian["n"] = "abbab", Baconian["o"] = "abbba", Baconian["p"] = "abbbb", Baconian["q"] = "baaaa", Baconian["r"] = "baaab",
                Baconian["s"] = "baaba", Baconian["t"] = "baabb", Baconian["u"] = "babaa", Baconian["v"] = "babab", Baconian["w"] = "babba", Baconian["x"] = "babbb",
                Baconian["y"] = "bbaaa", Baconian["z"] = "bbaab", Baconian["A"] = "aaaaa", Baconian["B"] = "aaaab", Baconian["C"] = "aaaba", Baconian["D"] = "aaabb",
                Baconian["E"] = "aabaa", Baconian["F"] = "aabab", Baconian["G"] = "aabba", Baconian["H"] = "aabbb", Baconian["I"] = "abaaa", Baconian["J"] = "abaab",
                Baconian["K"] = "ababa", Baconian["L"] = "ababb",
                Baconian["M"] = "abbaa", Baconian["N"] = "abbab", Baconian["O"] = "abbba", Baconian["P"] = "abbbb", Baconian["Q"] = "baaaa", Baconian["R"] = "baaab",
                Baconian["S"] = "baaba", Baconian["T"] = "baabb", Baconian["U"] = "babaa", Baconian["V"] = "babab", Baconian["W"] = "babba", Baconian["X"] = "babbb",
                Baconian["Y"] = "bbaaa", Baconian["Z"] = "bbaab", Baconian[" "] = " ";
                string word, temp;
                cout << "Please enter a string to cipher" << endl;
                cin.ignore();
                getline(cin, word);
                for (int x = 0; x < word.length(); x++) {
                    temp = word[x];
                    cout << Baconian[temp];
                }
                cout << endl;
                break;

            }
            case 2: {
                map <string, string> Baconian;
                Baconian["aaaaa"] = "a", Baconian["aaaab"] = "b", Baconian["aaaba"] = "c", Baconian["aaabb"] = "d", Baconian["aabaa"] = "e", Baconian["aabab"] = "f",
                Baconian["aabba"] = "g", Baconian["aabbb"] = "h", Baconian["abaaa"] = "i", Baconian["abaab"] = "j", Baconian["ababa"] = "k", Baconian["ababb"] = "l",
                Baconian["abbaa"] = "m", Baconian["abbab"] = "n", Baconian["abbba"] = "o", Baconian["abbbb"] = "p", Baconian["baaaa"] = "q", Baconian["baaab"] = "r",
                Baconian["baaba"] = "s", Baconian["baabb"] = "t", Baconian["babaa"] = "u", Baconian["babab"] = "v", Baconian["babba"] = "w", Baconian["babbb"] = "x",
                Baconian["bbaaa"] = "y", Baconian["bbaab"] = "z", Baconian[" "] = " ";
                string word, temp;
                cout << "Please enter a string to decipher" << endl;
                cin.ignore();
                getline(cin, word);
                temp = word[0];
                for (int x = 1; x < word.length(); x++) {
                    temp += word[x];
                    if (temp[temp.length() - 1] == ' ') {
                        cout << Baconian[temp];
                        temp = "";
                    }
                }
                temp += " ";
                cout << Baconian[temp] << endl;
                break;
            }
            case 3: {
                cout << "thank you for using this program tare2 elsalama \n";
                isDone = true;
                break;
            }
            default: {
                cout << "wrong input \n";
                isDone = true;
                break;
            }}}}
//Function to cipher the given string.
void cipher(string msg,string key){

    string alpha="abcdefghijklmnopqrstuvwxyz";
    string a="abcdefghijklmnopqrstuvwxyz";

    for (int i= 0; i < key.length(); i++){
        a.erase(remove(a.begin(), a.end(), key[i]), a.end());
    }

    string cipher_alpha = key+a ;

    for (int i = 0; i < msg.length() ; i++){
        for (int j = 0; j < alpha.length(); j++){

            if(msg[i]==alpha[j])
                cout<<cipher_alpha[j];
        }
        if(msg[i]==' ')
            cout<<' ';
    }
}


//Function to decipher the given string.
void decipher(string msg,string key){

    string alpha="abcdefghijklmnopqrstuvwxyz";
    string a="abcdefghijklmnopqrstuvwxyz";

    for (int i= 0; i < key.length(); i++){

        a.erase(remove(a.begin(), a.end(), key[i]), a.end());
    }

    string cipher_alpha= key+a ;

    for (int i = 0; i < msg.length() ; i++){

        for (int j = 0; j < alpha.length(); j++){

            if(msg[i]==cipher_alpha[j])
                cout<<alpha[j];
        }
        if(msg[i]==' ')
            cout<<' ';
    }
}

int cipher5()
{
    cout<<"What do you like to do ?"<<endl<<"1- Cipher a message"<<endl<<"2- Decipher a message"<<endl<<"3- End"<<endl;
    int num;
    string key;
    cin>>num;

    if(num==3)
        return 0;

    cout<<"Enter a key"<<endl;
    cin>>key;

    string userMsg="";
    cout<<"Enter a message :"<<endl;
    while(userMsg.empty())
    {
        getline(cin,userMsg);
    }

    //Transforming the input to lowercase string.
    transform(userMsg.begin(), userMsg.end(), userMsg.begin(), ::tolower);


    if(num==1){
        cout<<"Ciphered Message Is:- ";
        cipher(userMsg,key);}

    else if(num==2){
        cout<<"The Message Was:-";
        decipher(userMsg,key);}
}
/*assigning the character from the alphapebt
to its opposite character in morse*/
string morseEncode(char x)
{

    switch (x) {
        case 'a':
            return " .-";
        case 'b':
            return " -...";
        case 'c':
            return " -.-.";
        case 'd':
            return " -..";
        case 'e':
            return " .";
        case 'f':
            return " ..-.";
        case 'g':
            return " --.";
        case 'h':
            return " ....";
        case 'i':
            return " ..";
        case 'j':
            return " .---";
        case 'k':
            return " -.-";
        case 'l':
            return " .-..";
        case 'm':
            return " --";
        case 'n':
            return " -.";
        case 'o':
            return " ---";
        case 'p':
            return " .--.";
        case 'q':
            return " --.-";
        case 'r':
            return " .-.";
        case 's':
            return " ...";
        case 't':
            return " -";
        case 'u':
            return " ..-";
        case 'v':
            return " ...-";
        case 'w':
            return " .--";
        case 'x':
            return " -..-";
        case 'y':
            return " -.--";
        case 'z':
            return " --..";
        case 'A':
            return " .-";
        case 'B':
            return " -...";
        case 'C':
            return " -.-.";
        case 'D':
            return " -..";
        case 'E':
            return " .";
        case 'F':
            return " ..-.";
        case 'G':
            return " --.";
        case 'H':
            return " ....";
        case 'I':
            return " ..";
        case 'J':
            return " .---";
        case 'K':
            return " -.-";
        case 'L':
            return " .-..";
        case 'M':
            return " --";
        case 'N':
            return " -.";
        case 'O':
            return " ---";
        case 'P':
            return " .--.";
        case 'Q':
            return " --.-";
        case 'R':
            return " .-.";
        case 'S':
            return " ...";
        case 'T':
            return " -";
        case 'U':
            return " ..-";
        case 'V':
            return " ...-";
        case 'W':
            return " .--";
        case 'X':
            return " -..-";
        case 'Y':
            return " -.--";
        case 'Z':
            return " --..";
        case '1':
            return " .----";
        case '2':
            return " ..---";
        case '3':
            return " ...--";
        case '4':
            return " ....-";
        case '5':
            return " .....";
        case '6':
            return " -....";
        case '7':
            return " --...";
        case '8':
            return " ---..";
        case '9':
            return " ----.";
        case '0':
            return " -----";
        case ' ':
            return "   ";
        default:
            cerr << "Found invalid character: " << x << ' '
                 << std::endl;
            exit(0);
    }
}

/*function to take the character from morse and
show it as an array*/
void morseCode(string s)
{
    for (int i = 0; s[i]; i++)
        cout << morseEncode(s[i]);
    cout << endl;
}

int cipher6(){
    //Taking Input From User

    cout<<"What do you like to do ?"<<endl<<"1- Cipher a message"<<endl<<"2- Decipher a message"<<endl<<"3- End"<<endl;
    int num;
    cin>>num;




    //Taking String From User & Uppercase All Its Characters & Key
    cout <<"Please enter the key :- \n";
    char n1,n2,n3,n4,n5;
    cin >>n1>>n2>>n3>>n4>>n5;

    string userMsg="";
    cout<<"Enter a message : "<<endl;
    while(userMsg.empty())
    {
        getline(cin,userMsg);
    }
    transform(userMsg.begin(), userMsg.end(), userMsg.begin(), ::toupper);



    //Making The 2D Array Using The Taken Key
    char arr[6][6];
    arr[1][1]=' '; arr[1][2] = n1; arr[1][3] = n2; arr[1][4] = n3; arr[1][5] = n4; arr[1][6]= n5;
    arr[2][1]=n1; arr[2][2] = 'A'; arr[2][3] = 'B'; arr[2][4] = 'C'; arr[2][5] = 'D'; arr[2][6]= 'E';
    arr[3][1]=n2; arr[3][2] = 'F'; arr[3][3] = 'G'; arr[3][4] = 'H'; arr[3][5] = 'J'; arr[3][6]= 'K';
    arr[4][1]=n3; arr[4][2] = 'L'; arr[4][3] = 'M'; arr[4][4] = 'N'; arr[4][5] = 'O'; arr[4][6]= 'P';
    arr[5][1]=n4; arr[5][2] = 'Q'; arr[5][3] = 'R'; arr[5][4] = 'S'; arr[5][5] = 'T'; arr[5][6]= 'U';
    arr[6][1]=n5; arr[6][2] = 'V'; arr[6][3] = 'W'; arr[6][4] = 'X'; arr[6][5] = 'Y'; arr[6][6]= 'Z';


    if(num==3)
        return 0;

    else if (num==1){
        string cipher="";
        for (int i=0; i<userMsg.length(); i++){
            for (int j=1; j<7; j++){
                for (int k=1; k<7; k++){
                    if (char(userMsg[i]) == char(arr[j][k])){
                        cipher += arr[k][1];
                        cipher += arr[1][j];

                    }
                }
            }
        }

        cout<<"Ciphered Message Is:- "<<cipher; }

    else if (num ==2){
        string decipher="";

        for (int i=0; i<userMsg.length(); i+=2){
            for (int j=1;j<=6;j++){
                for (int k = 1; k<=6; k++){
                    if(userMsg[i] ==arr[j][1]){
                        int row =j;
                        if(userMsg[i+1]==arr[1][k]){
                            int column = k;
                            decipher +=arr[row][column];
                        }
                    }
                }
            }
        }

        cout<<"Deciphered Message Is :- "<<decipher;}

}

int cipher7()
{
    string decrypted;
    cout << "please enter the message you want to decrypt: \n";
    cin.ignore();
    getline(cin, decrypted);
    morseCode(decrypted);
    return 0;
}
int cipher8()
{
    int decryptorencrypt;
    char XORkey;
    string message;
    bool isDone = false;
    while (isDone == false) {
        cout << "What do you like to do ? \n";
        cout << "\n 1-ciphering \n 2-deciphering \n 3-end program\n";
        cin >> decryptorencrypt;
        switch (decryptorencrypt) {
            case 1: {

                cout << "please enter the message you want to encrypt:\n";
                cin.ignore();
                getline(cin, message);
                cout << "enter the secret key\n";
                cin >> XORkey;
                for (int i = 0; i <= message.length(); i++) {

                    cout << (char(message[i] ^ XORkey));
                }
                cout << endl;
                for (int j = 0; j <= message.length(); j++) {
                    cout << hex << (int)(char(message[j] ^ XORkey));
                }
                cout << endl;

                break;
            }
            case 2: {

                cout << "\nplease enter the message you want to decrypt:\n";
                cin.ignore();
                getline(cin, message);
                cout << "enter the secret key\n";
                cin >> XORkey;
                for (int i = 0; i <= message.length(); i++) {

                    cout << (char(message[i] ^ XORkey));
                }
                cout << endl;
                for (int j = 0; j <= message.length(); j++) {
                    cout << hex << (int)(char(message[j] ^ XORkey));
                }
                cout << endl;
                break;
            }
            case 3: {
                cout << "thanks for using our program , Good bye.\n";
                isDone = true;
                break;
            }
            default: {
                cout << "wrong choice \n";
                isDone = true;
                break;
            }

        }
    }
    return 0;
}
int cipher9()
{
    bool cond = true;
    while (cond) {
        int y;
        cout << "Ahlan ya user ya habibi " << endl;
        cout << "What do you want to do today ?" << endl;
        cout << "1-Cipher " << endl;
        cout << "2-decipher" << endl;
        cout << "3-End" << endl;
        cin >> y;
        if (y == 1)
        {
            string word;
            int key;
            cout << "Enter plan text: " << endl;
            cin >> word;
            cout << "Enter the number of rails: " << endl;
            cin >> key;

            vector<char> lines[key];
            bool flag = true;
            for (int i = 0, j = 0;i < word.length();i++) {
                lines[j].push_back(word[i]);
                if (j == key - 1) flag = false;
                if (flag == false && j == 0) flag = true;
                if (flag == true) j++;
                else j--;
            }
            for (int i = 0;i < key;i++) {
                for (int j = 0;j < lines[i].size();j++) {
                    cout << lines[i][j];
                }

            }
            cout << endl;
        }
        if (y == 2)
            cout << endl;
        string word;
        int key ;

        cout << "Enter the ciphered text: " << endl;
        cin >> word;
        cout << "Enter the key: " << endl;
        bool flag = true;
        int lineSize[key] ;
        for (int i = 0, j = 0;i < word.length();i++) {
            lineSize[j]++;
            if (j == key - 1) flag = false;
            if (flag == false && j == 0) flag = true;
            if (flag == true) j++;
            else j--;
        }
        int k = 0;
        vector<char> lines2[key];
        for (int i = 0;i < key;i++) {
            for (int j = 0;j < lineSize[i];j++) {
                lines2[i].push_back(word[k]);
                k++;
            }
        }

        int arr[key] ;
        for (int i = 0, j = 0;i < word.length();i++) {
            cout << lines2[j][arr[j]];
            arr[j]++;
            if (j == key - 1) flag = false;
            if (flag == false && j == 0) flag = true;
            if (flag == true) j++;
            else j--;
        }
        cout << endl;
        if (y == 3) {
            cout << endl;
            cond = false;
        }
    }
    return 0;
}

int main()
{
    int cipher;
    cout<< "Please choose the cipher you need to use :-\n";
    cout<<"0. Affine Cipher"<<endl<<"1. Caesar Cipher"<<endl<<"2. Atbash Cipher"<<endl<<"3. Vignere Cipher"<<endl;
    cout<<"4. Baconian Cipher"<<endl<<"5. Simple Substitution Cipher"<<endl<<"6. Polybius Square Cipher"<<endl<<"7. Morse Code"<<endl<<"8. XOR Cipher"<<endl<<"9. Rail-fence Cipher"<<endl;
    cout<<"enter number of cipher: "<<endl;
    cin>>cipher;
    if(cipher==0)
        cipher0();
    else if(cipher==1)
        cipher1();
    else if(cipher==2)
        cipher2();
    else if(cipher==3)
        cipher3();
    else if(cipher==4)
        cipher4();
    else if(cipher==5)
        cipher5();
    else if(cipher==6)
        cipher6();
    else if(cipher==7)
        cipher7();
    else if(cipher==8)
        cipher8();
    else if(cipher==9)
        cipher9();
    else
        cout<<"Error, enter another number : ";
}
