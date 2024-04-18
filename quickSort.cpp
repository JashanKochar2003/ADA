#include<iostream>
#include<fstream>
#include<cstdlib>
#include<chrono>
using namespace std;
using namespace std::chrono;
const int size = 100000;

int partition(int arr[], int start, int end)
{
    float pivot = arr[start];
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }
    // Giving pivot element its correct position
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);
    // Sorting left and right parts of the pivot element
    int i = start, j = end;
    while (i < pivotIndex && j > pivotIndex) {
        while (arr[i] <= pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    return pivotIndex;
}

void random_generator(int a[],int n){
 for(int i=0;i<n;i++){
    a[i]= rand()%100;
 } 
}

void print(int a[],int n){
    for(int i=0;i<n;i++){
            cout<<a[i]<<"\t";
        }
        cout<<endl;
    }


void qs(int a[],int low,int high){
    if(low<high){
        int j = partition(a,low,high);
        qs(a,low,j-1);
        qs(a,j+1,high);
    }
}


int main(){
 fstream file;
 file.open("quickSort.txt",ios::out);
 for(int i=10; i<=size;){
    int a[i];
    random_generator(a,i);
  // print(a,i);
    int avg_time =0;
    int total_time = 0;
    for (int m=0;m<10;m++){
    auto start = high_resolution_clock::now();
    qs(a,0,i-1);
    auto stop = high_resolution_clock::now();;
    auto duration = duration_cast<microseconds>(stop - start);
    total_time +=duration.count();
    }
    avg_time = total_time/10;
    cout<<"avg time taken for size of array = "<<i<<" is "<<avg_time<<" microseconds"<<endl;
     file<<i<<","<<avg_time<<endl;
    // print(a,i);
       if(i<1000)
     i *=10;
     else if(i>=1000 && i<5000)
     i=5000;
     else
     i +=5000;
 }
}