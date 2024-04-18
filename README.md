**README: Analysis and Design of Merging Sorted List Algorithm**

### Overview
This repository focuses on the Merging Sorted List problem, which involves merging two sorted lists into a single sorted list. The algorithm efficiently combines two lists of different sizes while maintaining the order.

### Merging Sorted List Problem
Given two lists `a` and `b` of sizes `m` and `n` respectively, both sorted in non-decreasing order, the goal is to generate a single sorted list containing all the elements from both lists.

### Algorithm
The algorithm for merging two sorted lists can be summarized as follows:
```cpp
Merging(a, b, m, n){
    i = 0;
    j = 0;
    k = 0;
    while(i < m && j < n){
        if(a[i] < b[j]){
            c[k] = a[i];
            k++;
            i++;
        }
        else{
            c[k] = b[j];
            k++;
            j++;
        }
    }
    // Copy remaining elements from a and b, if any
    while(i < m){
        c[k] = a[i];
        k++;
        i++;
    }
    while(j < n){
        c[k] = b[j];
        k++;
        j++;
    }
    return c;
}
```
Where `a` and `b` are the input lists, `m` and `n` are their respective sizes, and `c` is the merged list.

### Source Code
The provided source code (`merging_sorted_list.cpp`) contains the implementation of the Merging Sorted List algorithm and measures the execution time for merging lists of varying sizes.

### Execution
To execute the code:
1. Compile the source code.
2. Run the compiled executable.
3. The program will merge sorted lists of different sizes and measure the average execution time.

### Output
The program output displays the average time taken for merging sorted lists of different sizes. Here's a sample output:
```
avg time taken for size of array = 10 is 0 microseconds
avg time taken for size of array = 100 is 0 microseconds
avg time taken for size of array = 1000 is 0 microseconds
...
avg time taken for size of array = 70000 is 623 microseconds
avg time taken for size of array = 75000 is 1205 microseconds
avg time taken for size of array = 90000 is 1671 microseconds
```

### Conclusion
Based on the observed execution times, it can be concluded that the time complexity of the Merging Sorted List algorithm is O(n), where n is the size of the merged list. This linear time complexity arises from the algorithm's simple comparison-based approach.

### Files
- `merging_sorted_list.cpp`: Contains the source code for the algorithm implementation and execution time analysis.
- `merging.txt`: Output file containing recorded execution times for merging lists of different sizes.

Feel free to explore and analyze the provided code and results further. If you have any questions or suggestions, please don't hesitate to reach out.
