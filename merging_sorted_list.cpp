#include<iostream>
#include<fstream>
#include<cstdlib>
#include<chrono>
using namespace std;
using namespace std::chrono;

const int size = 100000;


void sorted_generator(int a[],int n,int start){
 for(int i=0;i<n;i++){
    a[i]= start;
    start = start+2;
 } 
}

int* merging(int a[],int b[],int m,int n){
    int i=0;
    int j=0;
    int k=0;
    static int c[2*size];
    while(i<m || j<n){
    while(i<m && j<n){
        if(a[i]<b[j]){
            c[k]=a[i];
            k++;
            i++;
        }
        else if(b[j]<a[i]){
            c[k]=b[j];
            k++;
            j++;
        }
    }
    if(j<n){
         c[k]=b[j];
            k++;
            j++;
    }
    else if(i<m){
         c[k]=a[i];
            k++;
            i++;
    }
    }
    return c;
}

void print(int* a,int n){
    cout<<"done1"<<endl;
    for(int i=0;i<n;i++){
            cout<<a[i]<<endl;
        }
        cout<<endl;
    }

int main(){
 int a[size];
 int b[size];
 int *c;
 fstream file;
 file.open("merging.txt",ios::out);
 for(int i=10; i<=size;){
    int avg_time =0;
    int total_time = 0;
    sorted_generator(a,i,1);
    sorted_generator(b,i,2);
    for (int m=0;m<10;m++){
    auto start = high_resolution_clock::now();
    c=merging(a,b,i,i);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    total_time +=duration.count();
    }
    avg_time = total_time/10;
    cout<<"avg time taken for size of array = "<<i<<" is "<<avg_time<<" microseconds"<<endl;
     file<<i<<","<<avg_time<<endl;
     //print(c,i);
       if(i<1000)
     i *=10;
     else if(i>=1000 && i<5000)
     i=5000;
     else
     i +=5000;
 }
}
