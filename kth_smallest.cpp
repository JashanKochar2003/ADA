#include<iostream>
#include<fstream>
#include<cstdlib>
#include<chrono>
using namespace std;
using namespace std::chrono;
void random_generator(int a[],int n){
 for(int i=0;i<n;i++){
    a[i]= rand();
 } 
}

 

int partition(int arr[], int start, int end)
{
 

    int pivot = arr[start];
 

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

            swap(arr[i++], arr[j--]);

        }

    }
 

    return pivotIndex;
}

int kth_smallest(int a[],int start, int n,int k){
    int p = partition(a,start,n);
    if(p<k){
        kth_smallest(a,p+1,n,k);
    }
    else if(p==k){
        return p;
    }
    else{
        kth_smallest(a,start,p-1,k);
    }
}
void print(int a[],int n){
    cout<<"done4"<<endl;
    for(int i=0;i<n;i++){
            cout<<a[i]<<"\t";
        }
        cout<<endl;
    }

int main(){
 fstream file;
 file.open("kth_smallest.txt",ios::out);
 for(int i=10; i<=100000;){
    int a[i];
    int avg_time =0;
    int total_time = 0;
    for (int m=0;m<10;m++){
    random_generator(a,i);
    //print(a,i);
    auto start = high_resolution_clock::now();
    int k=partition(a,0,i-1);
    //cout<<k<<endl;
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    total_time +=duration.count();
    }
    //print(a,i);
    avg_time = total_time/10;
    cout<<"avg time taken for size of array = "<<i<<" is "<<avg_time<<" microseconds"<<endl;
     file<<i<<","<<avg_time<<endl;
    if(i<1000)
     i *=10;
     else if(i>=1000 && i<5000)
     i=5000;
     else
     i +=5000;
 }
 file.close();
 return 0;
}
