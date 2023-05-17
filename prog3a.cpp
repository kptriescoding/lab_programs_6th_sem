#include<iostream>
using namespace std;
string encrypt(string plainText,int shiftLength){
    for (int i=0;i<plainText.length();i++){
        if(isupper(plainText[i]))
        plainText[i]=(plainText[i]-'A'+shiftLength)%26+'A';
        else if(islower(plainText[i]))
        plainText[i]=(plainText[i]-'a'+shiftLength)%26+'a';
    }
    return plainText;
}
string decrypt(string cipherText,int shiftLength){
    for (int i=0;i<cipherText.length();i++){
        if(isupper(cipherText[i]))
        cipherText[i]=(cipherText[i]-'A'-shiftLength+26)%26+'A';
        else if(islower(cipherText[i]))
        cipherText[i]=(cipherText[i]-'a'-shiftLength+26)%26+'a';
    }
    return cipherText;
}
int main(){
    string plainText;
    int shiftLength;
    cout<<"Enter the plain text\n";
    getline(cin,plainText);
    cout<<"Enter the shift length\n";
    cin>>shiftLength;
    string cipherText=encrypt(plainText,shiftLength);
    cout<<"Cipher Text: \n"<<cipherText<<endl;
    cout<<"Decrypted Text: \n"<<decrypt(cipherText,shiftLength)<<endl;
}