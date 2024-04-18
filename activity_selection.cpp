#include<iostream>
#include "stack.cpp"
#include<fstream>
#include<cstdlib>
#include<chrono>
using namespace std;
using namespace std::chrono;

const int s = 100;

void swap(float &a, float &b) {
    float temp = a;
    a = b;
    b = temp;
}

void random_generator(int a[],int n){
 for(int i=0;i<n;i++){
    a[i]= rand()%100;
 } 
}

void print(int a[],int n){
    cout<<"done4"<<endl;
    for(int i=0;i<n;i++){
            cout<<a[i]<<"\t";
        }
        cout<<endl;
    }

int partition(int arr[], int start, int end, int profit[], int weight[])
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
    swap(profit[pivotIndex], profit[start]);
    swap(weight[pivotIndex], weight[start]);
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
            swap(profit[i], profit[j]);
            swap(weight[i], weight[j]);
            i++;
            j--;
        }
    }
    return pivotIndex;
}


void q_sort(int a[], int p, int q, int profit[], int weight[]) {
    stack s1;
    s1.push(q);
    s1.push(p);
    while (!s1.is_empty()) {
        p = s1.pop();
        q = s1.pop();
        if (p < q) {
            int j = partition(a, p, q, profit, weight);
            if ((j - p) < (q - j)) {
                s1.push(q);
                s1.push(j + 1);
                s1.push(j - 1);
                s1.push(p);
            } else {
                s1.push(j - 1);
                s1.push(p);
                s1.push(q);
                s1.push(j + 1);
            }
        }
    }
}
void activity(int s[],int f[], int d[],int n ,int maxW,float x[], float &netP_d, float &netP_s, float &netP_f){
   q_sort(s,0,n-1,f,d);
  int count = 1;
     int i=0;
   for(int j=1;j<n;j++){
    if(f[j]<=s[i]){
        x[j] = 1;
       i=j;
       count++;
    }
    }
  netP_s =count;
  count =1;

   q_sort(f,0,n-1,s,d);
    i=0;
   for(int j=1;j<n;j++){
    if(f[j]<=s[i]){
        x[j] = 1;
       i=j;
       count++;
    }
    }
  netP_f =count;
  count =1;

     q_sort(d,0,n-1,s,f);
      i=0;
   for(int j=1;j<n;j++){
    if(f[j]<=s[i]){
        x[j] = 1;
       i=j;
       count++;
    }
    }
  netP_s =count;
  count =0;
return;
   
}

void input_generator(int s[],int f[],int duration_time[],int n){
    for(int i=0;i<n;i++){
        s[i]=(rand()%12);
        f[i]=(rand()%12);
        if(f[i]-s[i] > 0)
        duration_time[i] = f[i]-s[i];
        else{
             duration_time[i] = f[i]-s[i]+12;
        }
    }
}

int main(){
 fstream file1,file2,file3;
 file1.open("activity_duration.txt",ios::out);
 file2.open("activity_s.txt",ios::out);
 file3.open("activity_f.txt",ios::out);
 for(int i=10; i<=s;i=i+10){
    float x[i];
    int starting_time[i];
    int finish_time[i];
    int duration_time[i];
    input_generator(starting_time,finish_time,duration_time,i);
    print(starting_time,i);
     print(finish_time,i);
      print(duration_time,i);
    float netP_s = 0;
    float netP_f = 0;
    float netP_d = 0;
    activity(starting_time,finish_time,duration_time,i,200,x,netP_d,netP_s,netP_f);
    cout<<"on the basis of duration total activities : "<<netP_d<<endl;
    cout<<"on the basis of finish time , total activities : "<<netP_f<<endl;
    cout<<"on the basis of starting time , total activities : "<<netP_s<<endl;
   file1<<i<<","<<netP_d<<endl;
    file2<<i<<","<<netP_s<<endl;
   file3<<i<<","<<netP_f<<endl;
 }
 file1.close();
 file2.close();
 file3.close();
 return 0;
 }
