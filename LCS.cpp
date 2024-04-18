#include<iostream>
#include<vector>
using namespace std;

int LCS(vector<char> x,vector<char> y){
    int m = x.size();
    int n = y.size();
    vector<char> subseq;
    char b[m+1][n+1],c[m+1][n+1];
    for(int i=0;i<=m;i++){
        c[i][0]=0;
    }
    for(int i=0;i<=n;i++){
        c[0][i]=0;
    }
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            b[i][j]='-';
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(x[i-1]==y[j-1]){
                c[i][j]=c[i-1][j-1]+1;
                b[i][j]='D';

            }
            else if(c[i-1][j]>=c[i][j-1]){
                c[i][j]=c[i-1][j];
                b[i][j]='U';
            }
            else{
                c[i][j]=c[i][j-1];
                b[i][j]='L';
            }

        }
    }
          for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
           cout<<b[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<"common subsequence is : ";
    for(int i=0;i<subseq.size();i++)
    cout<<subseq[i];
    cout<<endl;

    return c[m][n];
}

int main(){
    string s1,s2;
    cout<<"enter string 1 : ";
    cin>>s1;
    cout<<"enter string s2 : ";
    cin>>s2;
    vector<char> x,y;
    for(int i=0;i<s1.size();i++){
        x.push_back(s1[i]);
    }
    for(int i=0;i<s2.size();i++){
        y.push_back(s2[i]);
    }
    int length = LCS(x,y);
    cout<<"length of common subsequence is : "<<length<<endl;
    return 0;
}