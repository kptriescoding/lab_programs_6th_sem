#include<iostream>
#include<vector>
using namespace std;
const string ALPHABET_WITHOUT_J="abcdefghiklmnopqrstuvwxyz";
string convertToLowerCase(string text){
    string lowerText="";
    for(int i=0;i<text.length();i++)
        if(isalpha(text[i])){
            if(text[i]!='j')
            lowerText+=tolower(text[i]);
            else
            lowerText+='i';
            
        }

    return lowerText;
}
vector<vector<char>> buildMatrix(string keyword){
    keyword=convertToLowerCase(keyword);
vector<vector<char>> matrix(5,vector<char>(5));
string uniqueChar="";
int row=0,col=0;
for(char c:keyword)
    if(islower(c)&&uniqueChar.find(c)==string::npos)
        uniqueChar+=c;

for(char c:uniqueChar){
    matrix[row][col]=c;
    col++;
    if(col==5){
        row++;
        col=0;
    }
}
for(char c:ALPHABET_WITHOUT_J){
    if(uniqueChar.find(c)==string::npos){
        matrix[row][col]=c;
    col++;
    if(col==5){
        row++;
        col=0;
    }
    }
}
return matrix;

}
void findInMatrix(char ch,int &r,int &c,vector<vector<char>> matrix){
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            if(matrix[i][j]==ch){
                r=i;
                c=j;
                return;
            }
return;
}
string encrypt(string plainText,vector<vector<char>> matrix){
    plainText=convertToLowerCase(plainText);
     char ch1,ch2;
    int r1,r2,c1,c2;
    if(plainText.length()%2==1)
        plainText+='z';
    for (int i=0;i<plainText.length();i+=2){
        ch1=plainText[i];
        ch2=plainText[i+1];
        findInMatrix(ch1,r1,c1,matrix);
        findInMatrix(ch2,r2,c2,matrix);
        if(r1==r2){
            c1=(c1+1)%5;
            c2=(c2+1)%5;
        }
        else if(c1==c2){
            r1=(r1+1)%5;
            r2=(r2+1)%5;
        }
        else{
            swap(c1,c2);
        }
        plainText[i]=matrix[r1][c1];
        plainText[i+1]=matrix[r2][c2];
    }
    return plainText;
}
string decrypt(string cipherText,vector<vector<char>> matrix){
    char ch1,ch2;
    int r1,r2,c1,c2;
    for (int i=0;i<cipherText.length();i+=2){
        ch1=cipherText[i];
        ch2=cipherText[i+1];
        findInMatrix(ch1,r1,c1,matrix);
        findInMatrix(ch2,r2,c2,matrix);
        if(r1==r2){
            c1=(c1+4)%5;
            c2=(c2+4)%5;
        }
        else if(c1==c2){
            r1=(r1+4)%5;
            r2=(r2+4)%5;
        }
        else{
            swap(c1,c2);
        }
        cipherText[i]=matrix[r1][c1];
        cipherText[i+1]=matrix[r2][c2];
    
    }
    return cipherText;
}
int main(){
    string plainText;
    string keyword;
    cout<<"Enter the plain text\n";
    getline(cin,plainText);
    cout<<"Enter the keyword\n";
    getline(cin,keyword);
    vector<vector<char>> matrix=buildMatrix(keyword);
    string cipherText=encrypt(plainText,matrix);
    cout<<"Cipher Text: \n"<<cipherText<<endl;
    cout<<"Decrypted Text: \n"<<decrypt(cipherText,matrix)<<endl;
}