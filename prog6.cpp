#include<iostream>
#include<cmath>
using namespace std;
bool isPrime(long long int p){
    if(p<=1)return false;
    for(int i=2;i<sqrt(p);i++){
        if(p%i==0)return false;
    }
    return true;
}
int modExp(long long int base,long long int power,long long int n){
    int ans=1;
    while(power--)
        ans=(ans*base)%n;
    return ans;
}
int main(){
    int p,g,pers1PrivateKey,pers2PrivateKey,pers1PublicKey,pers2PublicKey,pers1SharedSecret,pers2SharedSecret;
    cout<<"Enter the prime number P\n";
    cin>>p;
    while(!isPrime(p)){
        cout<<"p should be prime\n";
        cin>>p;
    }
    cout<<"Enter the value of G (primitive root of P)\n";
    cin>>g;
    cout<<"Enter Person1 Private Key\n";
    cin>>pers1PrivateKey;
    cout<<"Enter Person2 Private Key\n";
    cin>>pers2PrivateKey;
    pers1PublicKey=modExp(g,pers1PrivateKey,p);
    pers2PublicKey=modExp(g,pers2PrivateKey,p);
    cout<<"Person1's public key: "<<pers1PublicKey<<endl;
    cout<<"Person2's public key: "<<pers2PublicKey<<endl;
    pers1SharedSecret=modExp(pers2PublicKey,pers1PrivateKey,p);
    pers2SharedSecret=modExp(pers1PublicKey,pers2PrivateKey,p);
    cout<<"Person1's shared secret: "<<pers1SharedSecret<<endl;
    cout<<"Person2's shared secret: "<<pers2SharedSecret<<endl;
}