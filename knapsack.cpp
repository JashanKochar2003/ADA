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

void print(float a[],int n){
    cout<<"done4"<<endl;
    for(int i=0;i<n;i++){
            cout<<a[i]<<"\t";
        }
        cout<<endl;
    }

int partition(float arr[], int start, int end, float profit[], float weight[])
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


void q_sort(float a[], int p, int q, float profit[], float weight[]) {
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
void knapsack(float p[],float w[], int n ,int maxW,float x[], float &netP_PW, float &netP_profit, float &netP_weight){
    cout<<"start knapsack"<<endl;
    int m = maxW;
   float PW[n];
   for(int i=0;i<n;i++){
    PW[i] = p[i]/w[i];
   }

   //case 1 = profit/weight

   q_sort(PW,0,n-1,p,w);
  // print(PW,n);
  // print(p,n);
  // print(w,n);
  // cout<<"mid 1 knapsack"<<endl;
   for(int i=0;i<n;i++){
    x[i] = 0.0;
   }
   int j =0;
   for(j=n-1;j>=0;j--){
    if(w[j]<= m){
        x[j] = 1;
        m = m - w[j];
        netP_PW += p[j];
    }
    else{
        break;
    }
    
   
}
if(j>0){
        x[j]= m/w[j];
        netP_PW += p[j]*x[j];
    }
    // print(x,n);
//cout<<"done knapsack"<<endl;


//case 2 = profit

 q_sort(p,0,n-1,PW,w);
 //print(PW,n);
   //print(p,n);
   //print(w,n);
  // cout<<"mid 1 knapsack"<<endl;
   for(int i=0;i<n;i++){
    x[i] = 0.0;
   }
   j =0;
   m = maxW;
   for(j=n-1;j>=0;j--){
    if(w[j]<= m){
        x[j] = 1;
        m = m - w[j];
        netP_profit += p[j];
    }
    else{
        break;
    }
    
  
}
if(j>0){
        x[j]= m/w[j];
        netP_profit += p[j]*x[j];
    }
     // print(x,n);
//cout<<"done knapsack"<<endl;


//case 3 = weight

 q_sort(w,0,n-1,PW,p);
 //print(PW,n);
   //print(p,n);
   //print(w,n);
   //cout<<"mid 1 knapsack"<<endl;
   for(int i=0;i<n;i++){
    x[i] = 0.0;
   }
   j =0;
   m = maxW;
   for(j=n-1;j>=0;j--){
    if(w[j]<= m){
        x[j] = 1;
        m = m - w[j];
        netP_weight += p[j];
    }
    else{
        break;
    }
    
  
}
if(j>0){
        x[j]= m/w[j];
        netP_weight += p[j]*x[j];
    }
   //   print(x,n);
//cout<<"done knapsack"<<endl;
return;
   
}

void input_generator(float profit_list[],float weight_list[],int n){
    for(int i=0;i<n;i++){
        profit_list[i]=(rand()%1000)+1;
        weight_list[i]=(rand()%100)+1;
    }
}

int main(){
 fstream file1,file2,file3;
 file1.open("knapsack_pw.txt",ios::out);
 file2.open("knapsack_p.txt",ios::out);
 file3.open("knapsack_w.txt",ios::out);
 for(int i=10; i<=s;i=i+10){
    float x[i];
    float profit_list[i];
    float weight_list[i];
    input_generator(profit_list,weight_list,i);
    float netP_PW = 0;
    float netP_profit = 0;
    float netP_weight = 0;
    knapsack(profit_list,weight_list,i,200,x,netP_PW,netP_profit,netP_weight);
    cout<<"total profit :"<<endl;
    cout<<netP_PW<<endl;
    cout<<netP_profit<<endl;
    cout<<netP_weight<<endl;
   file1<<i<<","<<netP_PW<<endl;
    file2<<i<<","<<netP_profit<<endl;
   file3<<i<<","<<netP_weight<<endl;
 }
 file1.close();
 file2.close();
 file3.close();
 return 0;
 }
