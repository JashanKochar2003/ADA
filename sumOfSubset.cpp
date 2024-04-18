#include<iostream>
using namespace std;

void print(int x[],int n){
    for(int i=0;i<n;i++){
        cout<<x[i]<<"\t";
    }
    cout<<endl;
}

void sumOfSubset(int sum,int rem,int target,int w[],int x[],int n,int k=0){
    for(int j=k;j<n;j++){
        x[j]=0;
    }
    x[k]=1;
    if((sum+w[k])==target){
        cout<<"done1"<<endl;
        print(w,n);
        print(x,n);
    }
    else if((sum + w[k] + w[k+1]) <= target ){
        cout<<"done2"<<endl;
    sumOfSubset(sum+w[k],rem-w[k],target,w,x,n,k+1);
    }

    if((sum+rem-w[k])>=target && (sum+w[k+1])<=target && (k+1)<n){
        cout<<"done3"<<endl;
        x[k]=0;
        sumOfSubset(sum,rem-w[k],target,w,x,n,k+1);
    }
}

int main(){
    int n;
    cout<<"enter total numbers : ";
    cin>>n;
    int x[n],w[n],target,sum;
    cout<<"enter sum target : ";
    cin>>target;
    sum=0;
    cout<<"enter numbers : ";
    for(int i=0;i<n;i++){
        cin>>w[i];
        x[i]=0;
        sum += w[i];
    }
    cout<<sum<<endl;
    sumOfSubset(0,sum,target,w,x,n);
    return 0;
}