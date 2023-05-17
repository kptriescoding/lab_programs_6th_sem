#include<iostream>
#include<cstdlib>
#include<ctime>
#include<unistd.h>
using namespace std;
void startBucket(int bucketSize,int outputRate){
int curInput,bucketContent=0;
int cont=5;
while(cont--){
curInput=(rand()%bucketSize)*1.5+1;
cout<<"Input size: "<<curInput<<endl;
if(curInput>outputRate){
	cout<<"Input Overflow!!\n";
	bucketContent+=curInput-outputRate;
	curInput=outputRate;
	}
cout<<"Outputting "<<curInput<<" flow of water\n";
cout<<"Bucket Content : "<<bucketContent<<endl;
if(bucketContent>bucketSize){
cout<<"Bucket Overflow!! Thrown out "<<bucketContent-bucketSize<<" amount of water\n";
 bucketContent=bucketSize;
}
sleep(1);
}
}
int main(){
     srand(time(NULL));
int bucketSize,outputRate;
cout<<"Enter the bucket size: ";
cin>>bucketSize;
cout<<"Enter the output rate: ";
cin>>outputRate;
startBucket(bucketSize,outputRate);
}
