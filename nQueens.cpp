#include<iostream>
#include<cmath>
using namespace std;

int place(int x[],int k ,int i){
    for(int j=0;j<k;j++){
            if((x[j]==i) || (abs(j-k)==abs(x[j]-i)))
            return 0;
    }
    return 1;
}

void print(int x[],int n){
    for(int i=0;i<n;i++){
        cout<<x[i]<<"\t";
    }
    cout<<endl;
}

void nQueens(int x[],int n, int k=0){
    for(int i=0;i<n;i++){
        if(place(x,k,i)==1){
            x[k]=i;
            if(k==n-1)
            print(x,n);
            else
            nQueens(x,n,k+1);
        }
    }
}

int main(){
    cout<<"enter number of queens to be placed : ";
    int n;
    cin>>n;
    int x[n];
    cout<<"queens can be placed in following orders : ";
    nQueens(x,n);
    return 0;
}