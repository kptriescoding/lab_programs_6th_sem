#include<iostream>
using namespace std;
string encrypt(string plainText,string keyword){
    int j=0;
    for (int i=0;i<plainText.length();i++){
        if(j==keyword.length())j=0;
        if(isupper(plainText[i]))
        plainText[i]=(plainText[i]-2*'A'+toupper(keyword[j++]))%26+'A';
        else if(islower(plainText[i]))
        plainText[i]=(plainText[i]-2*'a'+tolower(keyword[j++]))%26+'a';
    }
    return plainText;
}
string decrypt(string cipherText,string keyword){
    int j=0;
    for (int i=0;i<cipherText.length();i++){
        if(j==keyword.length())j=0;
        if(isupper(cipherText[i]))
        cipherText[i]=(cipherText[i]-toupper(keyword[j++])+26)%26+'A';
        else if(islower(cipherText[i]))
        cipherText[i]=(cipherText[i]-tolower(keyword[j++])+26)%26+'a';
    }
    return cipherText;
}
int main(){
    string plainText;
    string keyword;
    cout<<"Enter the plain text\n";
    getline(cin,plainText);
    cout<<"Enter the keyword\n";
    cin>>keyword;
    string cipherText=encrypt(plainText,keyword);
    cout<<"Cipher Text: \n"<<cipherText<<endl;
    cout<<"Decrypted Text: \n"<<decrypt(cipherText,keyword)<<endl;
}