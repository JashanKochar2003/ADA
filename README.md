File: AIM - Analysis and Design of Horner’s Rule Algorithm

---

**Horner’s Rule:**

Horner’s Rule for polynomial division is an algorithm employed to simplify the process of evaluating a polynomial \( f(x) \) at a certain value \( x = x_0 \) by breaking down the polynomial into monomials (polynomials of the 1st degree). Each monomial involves at most one multiplication and one addition process. This method, also known as synthetic division, accumulates results from each monomial through addition.

To illustrate the process, let's rewrite the polynomial in its expanded form:

\[ f(x_0) = a_0 + a_1x_0 + a_2x_0^2 + \ldots + a_nx_0^n \]

This can also be represented as:

\[ f(x_0) = a_0 + x_0(a_1 + x_0(a_2 + x_0(a_3 + \ldots + (a_{n-1} + a_nx_0) \ldots) \]

The algorithm proposed by this rule involves evaluating the monomials formed above, starting from the innermost parenthesis and moving outwards to evaluate the monomials in the outer parenthesis.

**Algorithm:**

```plaintext
Horner_rule(x, m, ,n=0) {
    If(n == m)
        Return a[m];
    Else 
        Return (a[n] + x(horner_rule(n+1, m, x))
}
```

**Source Code:**

```cpp
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<chrono>
using namespace std;
using namespace std::chrono;

const int size = 100000;

void random_generator(int a[],int n){
    for(int i=0;i<n;i++){
        a[i]= rand();
        cout<<a[i]<<endl;
    } 
}

int horner_rule(int a[],int n , int k,int x){
    if(k==n-1){
        return a[k] ;
    }
    else{
        return a[k] + (x*(horner_rule(a,n,k+1,x)));
    }
}

int main(){
    int a[size];
    fstream file;
    int avg_time =0;
    int total_time = 0;

    file.open("horner_rule_result.txt",ios::out);
    
    for(int i=10;i<=size;){
        avg_time =0;
        total_time = 0;
        int k = 0;
        int x =1;
        cout<<endl;
        random_generator(a,i);
        
        for (int m=0;m<10;m++){
            auto start = high_resolution_clock::now();
            int h = horner_rule(a,i,k,x);
            cout<<h<<endl;
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            total_time +=duration.count();
        }
        
        avg_time = total_time/10;
        cout<<"avg time taken for size of array = "<<i<<" is "<<avg_time<<" microseconds"<<endl;
        file<<"("<<i<<","<<avg_time<<")"<<endl;
        
        if(i<1000)
            i *=10;
        else if(i>=1000 && i<5000)
            i=5000;
        else
            i +=5000;
    }
    return 0;
}
```



**Conclusion:**

Using simple multiplication, the time complexity is \( O(a^n) \), but with Horner's rule algorithm, the complexity reduces to \( O(n) \).

--- 

This file provides a comprehensive overview of Horner's Rule algorithm along with its implementation in C++ and corresponding output analysis.
