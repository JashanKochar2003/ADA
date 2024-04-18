#include<iostream>
#include<fstream>
#include<cstdlib>
#include<chrono>
#include "stack.cpp"
using namespace std;
using namespace std::chrono;

//const int size = 100000;

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

int partition(int arr[], int start, int end)
{
    int pivot = arr[start];
    int count1 = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count1++;
    }
    // Giving pivot element its correct position
    int pivotIndex = start + count1;
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

int q_sort(int a[], int p, int q){
    int steps = 0;
    int maxSteps = steps;
    stack s1;
    s1.push(q);
    s1.push(p);
    steps +=2;
    if(maxSteps<steps){
        maxSteps = steps;
    }
    while (!s1.is_empty()) {
        p = s1.pop();
        q = s1.pop();
        steps -=2;
        if (p < q) {
            int j = partition(a, p, q);
            if ((j - p) < (q - j)) {
                s1.push(q);
                s1.push(j + 1);
                s1.push(j - 1);
                s1.push(p);
                steps +=4;
                if(maxSteps<steps){
                    maxSteps = steps;
                                    }
            } else {
                s1.push(j - 1);
                s1.push(p);
                s1.push(q);
                s1.push(j + 1);
                steps +=4;
                if(maxSteps<steps){
                    maxSteps = steps;
                                    }
            }
        }
    }
    return maxSteps;
}

int main(){
 fstream file;
 int steps ;
 file.open("space_comp_quickSort_ite.txt",ios::out);
 for(int i=10; i<=100000;){
    steps = 0;
    int a[i];
    random_generator(a,i);
    //print(a,i);
    int avg_time =0;
    int total_time = 0;
    for (int m=0;m<10;m++){
    auto start = high_resolution_clock::now();
    steps = q_sort(a,0,i-1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    total_time +=duration.count();
    }
   //print(a,i);
    avg_time = total_time/10;
    cout<<"avg steps taken for size of array = "<<i<<" is "<<steps<<endl;
     file<<i<<","<<steps<<endl;
       if(i<1000)
     i *=10;
     else if(i>=1000 && i<5000)
     i=5000;
     else
     i +=5000;
 }
}
