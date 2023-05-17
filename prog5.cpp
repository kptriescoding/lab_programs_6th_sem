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
long long int gcd(long long int a,long long int b){
    if(b==0)return a;
    return gcd(b,a%b);
}
long long int modInverse(long long int e,long long int phi){
    int k=0;
    while((phi*k+1)%e!=0)k++;
    return (phi*k+1)/e;
}
int modExp(long long int base,long long int power,long long int n){
    int ans=1;
    while(power--)
        ans=(ans*base)%n;
    return ans;
}


int main(){
  long long int p,q,phi,e,d,n;
  int plainText,cipherText; 
  cout<<"Enter the prime number p\n";
  cin>>p;
  while(!isPrime(p)){
    cout<<p<<" is not prime\tTry Again!!\n";
    cin>>p;
  }
  cout<<"Enter the prime number q\n";
  cin>>q;
  while(!isPrime(q)){
    cout<<q<<" is not prime\tTry Again!!\n";
    cin>>q;
  }
  phi=(p-1)*(q-1);
  cout<<"The value of phi is: "<<phi<<"\nEnter e such that 1 < e < phi and gcd(e,phi) = 1\n";
  cin>>e;
  while(e<=1||e>=phi||gcd(e,phi)!=1){
    cout<<"Enter valid e\n";
    cin>>e;
  }
  d=modInverse(e,phi);
  n=p*q;
  cout<<"The public key (e,n): ("<<e<<","<<n<<")\n";
  cout<<"The public key (d,n): ("<<d<<","<<n<<")\n";
  cout<<"Enter the plain text (integer)\n";
  cin>>plainText;
  cipherText=modExp(plainText,e,n);
  cout<<"Encrypted Text is: "<<cipherText<<endl;
  plainText=modExp(cipherText,d,n);
  cout<<"Decrypted Text is: "<<plainText<<endl;
}