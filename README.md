**README: Analysis and Design of Power of an Element Algorithm**

### Overview
This repository explores two algorithms for computing the power of an element efficiently. The first algorithm operates linearly, while the second algorithm utilizes a logarithmic approach. The goal is to compare their performance and determine which one is more optimal.

### Power of an Element Problem
Given a base element and its exponent, the objective is to calculate the result efficiently.

### Algorithms

**First Algorithm (Linear):**
```cpp
Power(number, n){
    x = 1;
    for(i = 1 to n){
        x = x * number;
    }
    return x;
}
```

**Second Algorithm (Logarithmic):**
```cpp
power(base, n, res, k = 1){
    if(n == 0){
        return 1;
    }
    else if(k == n){
        return res;
    }
    else if((k * 2 < n) || ((k * 2 > n) && (k * 2 - n) < (n - k))){
        return power(base, n, res * res, k * 2);
    }
    else if(k < n){
        return power(base, n, base * res, k + 1);
    }
    else{
        return power(base, n, res / base, k - 1);
    }
}
```

### Source Code
The provided source code (`power_ite.cpp`) and (`power_rec.cpp`) implements both algorithms and measures their execution time for computing powers of varying sizes.

### Execution and Output
The code computes powers for different sizes using both algorithms and records the average execution time. Here's a summary of the output:

**Linear Algorithm:**
- Average time taken for size of array = 10 is 0 microseconds
- Average time taken for size of array = 100 is 0 microseconds
- Average time taken for size of array = 1000 is 99 microseconds
- ...
- Average time taken for size of array = 100000 is 14873 microseconds

**Logarithmic Algorithm:**
- Average time taken for size of array = 10 is 0 microseconds
- Average time taken for size of array = 100 is 0 microseconds
- Average time taken for size of array = 1000 is 0 microseconds
- ...
- Average time taken for size of array = 100000 is 6310 microseconds

### Graphical representation
- The graphical comparison of time comolexity is in time complexity folder.

### Conclusion
- The linear algorithm has a time complexity of O(n), while the logarithmic algorithm has a time complexity of O(logn).
- The logarithmic algorithm demonstrates better performance for larger input sizes, making it more optimal for computing powers efficiently.

### Files
- `power_itw.cpp`: Contains the source code for linear alogorithm.
- `power_ite.txt`: Output file containing recorded execution times for the linear algorithm.
- `power_rec.cpp`: Contains the source code for logarithmic algorithm
- `power_rec.txt`: Output file containing recorded execution times for the logarithmic algorithm.

Feel free to explore the source code and results further. If you have any questions or suggestions, please don't hesitate to reach out.
