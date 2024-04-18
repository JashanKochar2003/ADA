#include<iostream>
#include<fstream>
#include<cstdlib>
#include<chrono>
using namespace std;
using namespace std::chrono;

const int size = 100000;

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


void merging(int a[], int low, int mid, int high) {
    int size1 = mid - low + 1;
    int size2 = high - mid;
    int arr1[size1];
    int arr2[size2];
    
    // Copy data to temp arrays arr1[] and arr2[]
    for (int i = 0; i < size1; i++) {
        arr1[i] = a[low + i];
    }
    for (int j = 0; j < size2; j++) {
        arr2[j] = a[mid + 1 + j];
    }

    int i = 0; // Initial index of first subarray
    int j = 0; // Initial index of second subarray
    int k = low; // Initial index of merged subarray

    while (i < size1 && j < size2) {
        if (arr1[i] <= arr2[j]) {
            a[k] = arr1[i];
            i++;
        } else {
            a[k] = arr2[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of arr1[], if there are any
    while (i < size1) {
        a[k] = arr1[i];
        i++;
        k++;
    }

    // Copy the remaining elements of arr2[], if there are any
    while (j < size2) {
        a[k] = arr2[j];
        j++;
        k++;
    }
}

void merge_sort(int a[],int low,int high){
    if(low<high){
        int mid = (low+high)/2;
        merge_sort(a,low,mid);
        merge_sort(a,mid+1,high);
        merging(a,low,mid,high);
    }
}

int main(){
 fstream file;
 file.open("mergeSort.txt",ios::out);
 for(int i=10; i<=size;){
    int a[i];
    random_generator(a,i);
   // print(a,i);
    int avg_time =0;
    int total_time = 0;
    for (int m=0;m<10;m++){
    auto start = high_resolution_clock::now();
    merge_sort(a,0,i-1);
    auto stop = high_resolution_clock::now();;
    auto duration = duration_cast<microseconds>(stop - start);
    total_time +=duration.count();
    }
    avg_time = total_time/10;
    cout<<"avg time taken for size of array = "<<i<<" is "<<avg_time<<" microseconds"<<endl;
     file<<i<<","<<avg_time<<endl;
     //print(a,i);
       if(i<1000)
     i *=10;
     else if(i>=1000 && i<5000)
     i=5000;
     else
     i +=5000;
 }
}
