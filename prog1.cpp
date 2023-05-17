#include<iostream>
#include<string>

using namespace std;
string divisionOperator(string divid,string divis,int mode){
	string remain="";
       string dividcpy=divid;
       int n=divis.length();
       for (int i=0;i<n-1;i++)
           divid+="0";
       for (int i=0;i<divid.length()-n+1;i++){
           if(divid[i]=='0')continue;
           for(int j=0;j<n;j++){
               if(divid[i+j]==divis[j])divid[i+j]='0';
               else divid[i+j]='1';
           }
       }
       for( int i=divid.length()-n+1;i<divid.length();i++)
      		remain+=divid[i];
      if(mode==0)
       return dividcpy+remain;
       else
       return remain;
    }
     int main() {
     string divid,divis,recv;
	cout<< "Enter the input\n";
	cin>>divid;
	cout<<"Enter the generator polynomial\n";
	cin>>divis;
	string send=divisionOperator(divid,divis,0);
	cout<<"The message to be sent is "<<send<<endl;
	cout<<"Input the message recieved\n";
	cin>>recv;
	string remain=divisionOperator(recv,divis,1);
	if(remain.find("1")==string::npos)
		cout<<"There was no error in transmission\n";
	else
		cout<<"There was error in transmission\n";
	return 0;
    }
