#include<iostream>
#include<fstream>
#include<cstdlib>
#include<chrono>
using namespace std;
using namespace std::chrono;

const int size = 100000;

void random_generator(int a[],int n){
 for(int i=0;i<n;i++){
    a[i]= rand()%1000;
 } 
}

void print(int a[],int n){
    for(int i=0;i<n;i++){
            cout<<a[i]<<"\t";
        }
        cout<<endl;
    }


void maxMin(int a[], int low, int high, int& max, int& min) {
    int max1 = -1, min1 = INT16_MAX;
    if (low == high) {
        max = a[low];
        min = a[low];
    } else if (high == low + 1) {
        if (a[high] > a[low]) {
            max = a[high];
            min = a[low];
        } else {
            max = a[low];
            min = a[high];
        }
    } else {
        int mid = (low + high) / 2;
        maxMin(a, low, mid, max, min);
        maxMin(a, mid + 1, high, max1, min1);
        if (max < max1)
            max = max1;
        if (min > min1)
            min = min1;
    }
}

int main(){
 fstream file;
 int max ,min;
 file.open("maxMin.txt",ios::out);
 for(int i=10; i<=size;){
    int a[i];
    random_generator(a,i);
   //print(a,i);
    int avg_time =0;
    int total_time = 0;
    for (int m=0;m<10;m++){
    auto start = high_resolution_clock::now();
    maxMin(a,0,i-1,max,min);
    auto stop = high_resolution_clock::now();;
    auto duration = duration_cast<microseconds>(stop - start);
    total_time +=duration.count();
    }
    avg_time = total_time/10;
    cout<<"avg time taken for size of array = "<<i<<" is "<<avg_time<<" microseconds"<<endl;
     file<<i<<","<<avg_time<<endl;
     //cout<<max<<"\t"<<min<<endl;
       if(i<1000)
     i *=10;
     else if(i>=1000 && i<5000)
     i=5000;
     else
     i +=5000;
 }
}
