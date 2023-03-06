#include <iostream>
#include<string>
#include <string>
#include <bitset>
#include <sstream>
#include <bits/stdc++.h>
using namespace std;
string BinToHex(const string& s)
{
    string out;
    for (int i = 0; i < s.size(); i += 4)
    {
        int8_t n = 0;
        for (int j = i; j < i + 4; ++j)
        {
            n <<= 1;
            if (s[j] == '1')
                n |= 1;
        }

        if (n <= 9)
            out.push_back('0' + n);
        else
            out.push_back('A' + n - 10);
    }

    return out;
}
int binary_to_decimal(string binaryString)
{

    int value = 0;
    int indexCounter = 0;
    for (int i = binaryString.length() - 1; i >= 0; i--)
    {

        if (binaryString[i] == '1')
        {
            value += pow(2, indexCounter);
        }
        indexCounter++;
    }
    return value;
}
string HexToBin(string words)
{

    int   i = 0;
    string biwords = "";
    for (int i = 0; i < words.length(); i++)
    {
        switch (words[i])
        {
        case '0':
            biwords += "0000";
            break;
        case '1':
            biwords += "0001";
            break;
        case '2':
            biwords += "0010";
            break;
        case '3':
            biwords += "0011";
            break;
        case '4':
            biwords += "0100";
            break;
        case '5':
            biwords += "0101";
            break;
        case '6':
            biwords += "0110";
            break;
        case '7':
            biwords += "0111";
            break;
        case '8':
            biwords += "1000";
            break;
        case '9':
            biwords += "1001";
            break;
        case 'A':
        case 'a':
            biwords += "1010";
            break;
        case 'B':
        case 'b':
            biwords += "1011";
            break;
        case 'C':
        case 'c':
            biwords += "1100";
            break;
        case 'D':
        case 'd':
            biwords += "1101";
            break;
        case 'E':
        case 'e':
            biwords += "1110";
            break;
        case 'F':
        case 'f':
            biwords += "1111";
            break;

        }

    }
    return  biwords;

}

string shift_left(string k, int shifts)
{
    string s = "";
    for (int i = 0; i < shifts; i++)
    {
        for (int j = 1; j < 32; j++)
        {
            s += k[j];
        }
        s += k[0];
        k = s;
        s = "";
    }
    return k;
}

string xor_(string a, string b)
{
    string ans = "";
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == b[i])
        {
            ans += "0";
        }
        else
        {
            ans += "1";
        }
    }
    return ans;
}
static string DecimalToBinary(int dec)
{
    if (dec < 1)
        return "0";

    string binStr = "";

    while (dec > 0)
    {
        binStr = binStr.insert(0, string(1, (char)((dec % 2) + 48)));

        dec /= 2;
    }

    return binStr;
}
string BinaryToASCII(string binaryString)
{
    string text = "";
    stringstream sstream(binaryString);
    while (sstream.good())
    {
        bitset<8> bits;
        sstream >> bits;
        text += char(bits.to_ulong());
    }
    return text;
}

static string ASCIIToBinary(string str)
{
    string bin = "";
    int strLength = str.length();

    for (int i = 0; i < strLength; ++i)
    {
        string cBin = DecimalToBinary(str[i]);
        int cBinLength = cBin.length();

        if (cBinLength < 8)
        {
            for (size_t i = 0; i < (8 - cBinLength); i++)
                cBin = cBin.insert(0, "0");
        }

        bin += cBin;
    }

    return bin;
}

string g(string word,int round)
{

    word=shift_left(word,8);

    string SBox[16][16] =
    {
        "63", "7C", "77", "7B", "F2", "6B", "6F", "C5", "30", "01", "67", "2B", "FE", "D7", "AB", "76",
        "CA", "82", "C9", "7D", "FA", "59", "47", "F0", "AD", "D4", "A2", "AF", "9C", "A4", "72", "C0",
        "B7", "FD", "93", "26", "36", "3F", "F7", "CC", "34", "A5", "E5", "F1", "71", "D8", "31", "15",
        "04", "C7", "23", "C3", "18", "96", "05", "9A", "07", "12", "80", "E2", "EB", "27", "B2", "75",
        "09", "83", "2C", "1A", "1B", "6E", "5A", "A0", "52", "3B", "D6", "B3", "29", "E3", "2F", "84",
        "53", "D1", "00", "ED", "20", "FC", "B1", "5B", "6A", "CB", "BE", "39", "4A", "4C", "58", "CF",
        "D0", "EF", "AA", "FB", "43", "4D", "33", "85", "45", "F9", "02", "7F", "50", "3C", "9F", "A8",
        "51", "A3", "40", "8F", "92", "9D", "38", "F5", "BC", "B6", "DA", "21", "10", "FF", "F3", "D2",
        "CD", "0C", "13", "EC", "5F", "97", "44", "17", "C4", "A7", "7E", "3D", "64", "5D", "19", "73",
        "60", "81", "4F", "DC", "22", "2A", "90", "88", "46", "EE", "B8", "14", "DE", "5E", "0B", "DB",
        "E0", "32", "3A", "0A", "49", "06", "24", "5C", "C2", "D3", "AC", "62", "91", "95", "E4", "79",
        "E7", "C8", "37", "6D", "8D", "D5", "4E", "A9", "6C", "56", "F4", "EA", "65", "7A", "AE", "08",
        "BA", "78", "25", "2E", "1C", "A6", "B4 ", "C6", "E8", "DD", "74", "1F", "4B", "BD", "8B", "8A",
        "70", "3E", "B5", "66", "48", "03", "F6", "0E", "61", "35", "57", "B9", "86", "C1", "1D", "9E",
        "E1", "F8", "98", "11", "69", "D9", "8E", "94", "9B", "1E", "87", "E9", "CE", "55", "28", "DF",
        "8C", "A1", "89", "0D", "BF", "E6", "42", "68", "41", "99", "2D", "0F"," B0", "54", "BB", "16"
    };
    string RC[10]=
    {

        "00000001",
        "00000010",
        "00000100",
        "00001000",
        "00010000",
        "00100000",
        "01000000",
        "10000000",
        "00011011",
        "00110110"

    };
    string v1=word.substr(0,8);
    string v2=word.substr(8,8);
    string v3=word.substr(16,8);
    string v0=word.substr(24,8);

    v1=HexToBin(SBox[binary_to_decimal(v1.substr(0,4))][binary_to_decimal(v1.substr(4,4))]);
    v2=HexToBin(SBox[binary_to_decimal(v2.substr(0,4))][binary_to_decimal(v2.substr(4,4))]);
    v3=HexToBin(SBox[binary_to_decimal(v3.substr(0,4))][binary_to_decimal(v3.substr(4,4))]);
    v0=HexToBin(SBox[binary_to_decimal(v0.substr(0,4))][binary_to_decimal(v0.substr(4,4))]);
    v1=xor_(v1,RC[round-1]);
    string result=v1+v2+v3+v0;
    return result;


}
string* generatekey(string key )
{
    key=HexToBin(key);


    static string keys[11];
    string w[44];
    keys[0]=key;
    w[0]=key.substr(0,32);
    w[1]=key.substr(32,32);
    w[2]=key.substr(64,32);
    w[3]=key.substr(96,32);





int round=1;
    for(int i=4; i<=43; i++)
    {


        if(i%4==0)
        {

            w[i]=xor_(w[i-4],g(w[i-1],round));
            round=round+1;




        }
        else
        {
            w[i]=xor_(w[i-1],w[i-4]);
        }




    }
    for(int i=1; i<=10; i++)
    {
        keys[i]=w[i*4]+w[(i*4)+1]+w[(i*4)+2]+w[(i*4+3)];




    }





    return keys;



}


string Encryption(string key,string Plaintext)
{

    string* keys = generatekey(key);

    Plaintext=ASCIIToBinary(Plaintext);
    Plaintext=xor_(Plaintext,keys[0]);

    string rows[4];
    string a[16];
    string b[4][4];
    string c[4][4];
    for(int round=1;round<=10;round++){
    a[0]=Plaintext.substr(0,8);
    a[1]=Plaintext.substr(8,8);
    a[2]=Plaintext.substr(16,8);
    a[3]=Plaintext.substr(24,8);
    a[4]=Plaintext.substr(32,8);
    a[5]=Plaintext.substr(40,8);
    a[6]=Plaintext.substr(48,8);
    a[7]=Plaintext.substr(56,8);
    a[8]=Plaintext.substr(64,8);
    a[9]=Plaintext.substr(72,8);
    a[10]=Plaintext.substr(80,8);
    a[11]=Plaintext.substr(88,8);
    a[12]=Plaintext.substr(96,8);
    a[13]=Plaintext.substr(104,8);
    a[14]=Plaintext.substr(112,8);
    a[15]=Plaintext.substr(120,8);

    string SBox[16][16] =
    {
        "63", "7C", "77", "7B", "F2", "6B", "6F", "C5", "30", "01", "67", "2B", "FE", "D7", "AB", "76",
        "CA", "82", "C9", "7D", "FA", "59", "47", "F0", "AD", "D4", "A2", "AF", "9C", "A4", "72", "C0",
        "B7", "FD", "93", "26", "36", "3F", "F7", "CC", "34", "A5", "E5", "F1", "71", "D8", "31", "15",
        "04", "C7", "23", "C3", "18", "96", "05", "9A", "07", "12", "80", "E2", "EB", "27", "B2", "75",
        "09", "83", "2C", "1A", "1B", "6E", "5A", "A0", "52", "3B", "D6", "B3", "29", "E3", "2F", "84",
        "53", "D1", "00", "ED", "20", "FC", "B1", "5B", "6A", "CB", "BE", "39", "4A", "4C", "58", "CF",
        "D0", "EF", "AA", "FB", "43", "4D", "33", "85", "45", "F9", "02", "7F", "50", "3C", "9F", "A8",
        "51", "A3", "40", "8F", "92", "9D", "38", "F5", "BC", "B6", "DA", "21", "10", "FF", "F3", "D2",
        "CD", "0C", "13", "EC", "5F", "97", "44", "17", "C4", "A7", "7E", "3D", "64", "5D", "19", "73",
        "60", "81", "4F", "DC", "22", "2A", "90", "88", "46", "EE", "B8", "14", "DE", "5E", "0B", "DB",
        "E0", "32", "3A", "0A", "49", "06", "24", "5C", "C2", "D3", "AC", "62", "91", "95", "E4", "79",
        "E7", "C8", "37", "6D", "8D", "D5", "4E", "A9", "6C", "56", "F4", "EA", "65", "7A", "AE", "08",
        "BA", "78", "25", "2E", "1C", "A6", "B4 ", "C6", "E8", "DD", "74", "1F", "4B", "BD", "8B", "8A",
        "70", "3E", "B5", "66", "48", "03", "F6", "0E", "61", "35", "57", "B9", "86", "C1", "1D", "9E",
        "E1", "F8", "98", "11", "69", "D9", "8E", "94", "9B", "1E", "87", "E9", "CE", "55", "28", "DF",
        "8C", "A1", "89", "0D", "BF", "E6", "42", "68", "41", "99", "2D", "0F"," B0", "54", "BB", "16"
    };




    for(int i=0; i<16; i++)
    {

        a[i]=HexToBin(SBox[binary_to_decimal(a[i].substr(0,4))][binary_to_decimal(a[i].substr(4,4))]);

    }
    b[0][0]=a[0];
    b[1][0]=a[5];
    b[2][0]=a[10];
    b[3][0]=a[15];
    b[0][1]=a[4];
    b[1][1]=a[9];
    b[2][1]=a[14];
    b[3][1]=a[3];
    b[0][2]=a[8];
    b[1][2]=a[13];
    b[2][2]=a[2];
    b[3][2]=a[7];
    b[0][3]=a[12];
    b[1][3]=a[1];
    b[2][3]=a[6];
    b[3][3]=a[11];

    int Mix[4][4] = { {2, 3, 1, 1 }, { 1, 2, 3, 1 },{ 1, 1, 2, 3}, {3, 1, 1, 2 } };
    string temp[4];
    string temp1;
    string txt;

    if(round!=10){
    for(int i=0; i<4; i++)
    {
        for(int t=0; t<4; t++)
        {

            for(int j=0; j<4; j++)
            {
                if(Mix[i][j]==1)
                {
                    temp[j]=b[j][t];

                }
                else if(Mix[i][j]==2)
                {
                    temp[j]=b[j][t]+"0";
                    if(temp[j][0]=='1')
                    {

                        temp[j]=xor_(temp[j],"100011011");
                    }
                    temp[j]=temp[j].substr(1,8);
                    //cout<<temp[j]<<endl;

                }
                else if(Mix[i][j]==3)
                {
                    temp[j]=b[j][t]+"0";
                    if(temp[j][0]=='1')
                    {

                        temp[j]=xor_(temp[j],"100011011");


                    }
                    temp[j]=temp[j].substr(1,8);

                    temp[j]=xor_(b[j][t],temp[j]);

                }

            }

            //cout<<temp[1]<<endl;
            temp[0]=xor_(temp[0],temp[1]);
            temp[0]=xor_(temp[0],temp[2]);
            c[t][i]=xor_(temp[0],temp[3]);


        }
    }

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
                txt+=c[i][j];


        }

    }
    }
    else{
        for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
                txt+=b[j][i];


        }
    }
    }
    Plaintext=xor_(txt,keys[round]);

}

return BinaryToASCII(Plaintext);
}
string Decryption(string Plaintext,string key){
        string ISBox[16][16] =
{
    "52", "09", "6A", "D5", "30", "36", "A5", "38", "BF", "40", "A3", "9E", "81", "F3", "D7", "FB",
    "7C", "E3", "39", "82", "9B", "2F", "FF", "87", "34", "8E", "43", "44", "C4", "DE", "E9", "CB",
    "54", "7B", "94", "32", "A6", "C2", "23", "3D", "EE", "4C", "95", "0B", "42", "FA", "C3", "4E",
    "08", "2E", "A1", "66", "28", "D9", "24", "B2", "76", "5B", "A2", "49", "6D", "8B", "D1", "25",
    "72", "F8", "F6", "64", "86", "68", "98", "16", "D4", "A4", "5C", "CC", "5D", "65", "B6", "92",
    "6C", "70", "48", "50", "FD", "ED", "B9", "DA", "5E", "15", "46", "57", "A7", "8D", "9D", "84",
    "90", "D8", "AB", "00", "8C", "BC", "D3", "0A", "F7", "E4", "58", "05", "B8", "B3", "45", "06",
    "D0", "2C", "1E", "8F", "CA", "3F", "0F", "02", "C1", "AF", "BD", "03", "01", "13", "8A", "6B",
    "3A", "91", "11", "41", "4F", "67", "DC", "EA", "97", "F2", "CF", "CE", "F0", "B4", "E6", "73",
    "96", "AC", "74", "22", "E7", "AD", "35", "85", "E2", "F9", "37", "E8", "1C", "75", "DF", "6E",
    "47", "F1", "1A", "71", "1D", "29", "C5", "89", "6F", "B7", "62", "0E", "AA", "18", "BE", "1B",
    "FC", "56", "3E", "4B", "C6", "D2", "79", "20", "9A", "DB", "C0", "FE", "78", "CD", "5A", "F4",
    "1F", "DD", "A8", "33", "88", "07", "C7", "31", "B1", "12", "10", "59", "27", "80", "EC", "5F",
    "60", "51", "7F", "A9", "19", "B5", "4A", "0D", "2D", "E5", "7A", "9F", "93", "C9", "9C", "eF",
    "A0", "E0", "3B", "4D", "AE", "2A", "F5", "B0", "C8", "EB", "BB", "3C", "83", "53", "99", "61",
    "17", "2B", "04", "7E", "BA", "77", "D6", "26", "E1", "69", "14", "63", "55", "21", "0C", "7D"
};


    string* keys = generatekey(key);
    Plaintext=HexToBin(Plaintext);
    int  InverseMixColumn[4][4] = { 14 ,  11 ,   13 ,  9 , 9 ,14, 11 , 13 ,13 ,9 ,14, 11 ,11, 13 , 9 , 14 };
    string a[16];
     string b[4][4];
     string temp[4];



    Plaintext=xor_(Plaintext,keys[10]);
    a[0]=Plaintext.substr(0,8);
    a[1]=Plaintext.substr(8,8);
    a[2]=Plaintext.substr(16,8);
    a[3]=Plaintext.substr(24,8);
    a[4]=Plaintext.substr(32,8);
    a[5]=Plaintext.substr(40,8);
    a[6]=Plaintext.substr(48,8);
    a[7]=Plaintext.substr(56,8);
    a[8]=Plaintext.substr(64,8);
    a[9]=Plaintext.substr(72,8);
    a[10]=Plaintext.substr(80,8);
    a[11]=Plaintext.substr(88,8);
    a[12]=Plaintext.substr(96,8);
    a[13]=Plaintext.substr(104,8);
    a[14]=Plaintext.substr(112,8);
    a[15]=Plaintext.substr(120,8);


    b[0][0]=a[0];
    b[1][0]=a[13];
    b[2][0]=a[10];
    b[3][0]=a[7];
    b[0][1]=a[4];
    b[1][1]=a[1];
    b[2][1]=a[14];
    b[3][1]=a[11];
    b[0][2]=a[8];
    b[1][2]=a[5];
    b[2][2]=a[2];
    b[3][2]=a[15];
    b[0][3]=a[12];
    b[1][3]=a[9];
    b[2][3]=a[6];
    b[3][3]=a[3];
    Plaintext="";
    for(int i=0; i<4; i++)

    {
        for(int j=0;j<4;j++){

        b[j][i]=HexToBin(ISBox[binary_to_decimal(b[j][i].substr(0,4))][binary_to_decimal(b[j][i].substr(4,4))]);
    Plaintext+=b[j][i];


    }
    }




cout<<BinToHex(Plaintext)<<endl;
    }




  int main()
{
    string plaintext;
    string key;
    string ciphertxt;
    string decrypt="29C3505F571420F6402299B31A02D73A";
    cout<<"Enter the plaintxt:"<<endl;
    cin>>plaintext;
    cout<<"Enter the Key:"<<endl;
    cin>>key;
    while(true){
            string new_p = "";
        int sub=0 ;//number of padding
        if(plaintext.size() %16 == 0 )
        {
            new_p = plaintext;
            //cout<<new_p<<endl;
        }
        else if(plaintext.size() < 16 )
        {
            sub = 16 - plaintext.size();
            for(int j = 0 ; j<sub ; j++)
            {
                new_p += "#";
            }
            new_p = new_p + plaintext;
            //cout<new_p<<endl;
        }
        else if(plaintext.size() > 16)

        {


            if (plaintext.size() % 16 != 0)
            {
                for (int i = 0; i < (16 - plaintext.size() % 16); i++)
                {
                    new_p += "";
                }

                new_p = new_p + plaintext ;


            }


        }
                        //cout<<new_p<<endl;


    if(key.length()==32){
    ciphertxt=Encryption(key,new_p);


    cout<<"The ciphertxt:"<<endl;
    cout<<ciphertxt<<endl;
    cout<<BinToHex(ASCIIToBinary(ciphertxt))<<endl;

    break;





    }

    else {
             cout<<"Enter the Key With Lenght 32 hexdecimal:"<<endl;
             cin>>key;

    }

    }
    cout<<"The Cipher text Afrer First Round of Decryption:"<<endl;
    Decryption(decrypt,key);

return 0 ;

}
