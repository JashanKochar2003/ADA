**README: Analysis and Design of Magic Square Algorithm**

### Overview
This repository explores the Magic Square problem, which involves arranging numbers in a square grid such that the sum of numbers in each row, column, and diagonal is the same. The algorithm aims to generate such magic squares of varying orders.

### Magic Square Problem
A magic square of order n is an arrangement of n^2 numbers in a square grid, where the sum of numbers in each row, column, and diagonal is the same. The integers from 1 to n^2 are usually used to fill the square.

### Algorithm
The algorithm for generating a magic square can be described as follows:
```cpp
MagicSquare(n){
    i = n/2;
    j = n-1;
    for(int k=1 to n*n){
        if(a[i][j]==0){
            a[i][j]=k;
            k++;
            i--;
            j++;
        }
        if(i<0 && j<n)
            i=n-1;
        else if(i>=0 && j==n)
            j = 0;
        else if(i<0 && j==n){
            i = 0;
            j = n-2;
        }
        if(a[i][j] !=0){
            i++;
            j = j-2;
        }
   }
}
```
Where `n` is the order of the magic square, and `a` is the square grid.

### Source Code
The provided source code (`magic_square.cpp`) contains the implementation of the Magic Square algorithm along with code for measuring the execution time for different sizes of the magic square.

### Execution
To execute the code:
1. Compile the source code.
2. Run the compiled executable.
3. The program will generate magic squares for various sizes and measure the average execution time.

### Output
The program output provides insights into the execution time for different sizes of the magic square. Here's a sample output:
```
avg time taken for size of array = 3 is 0 microseconds
avg time taken for size of array = 13 is 0 microseconds
avg time taken for size of array = 23 is 0 microseconds
...
avg time taken for size of array = 693 is 6478 microseconds
```

### Conclusion
Based on the observed execution times, it can be concluded that the time complexity of the Magic Square algorithm is O(n^2), where n is the order of the magic square. This quadratic time complexity arises from the nested loops used to fill the square grid.

### Files
- `magic_square.cpp`: Contains the source code for the algorithm implementation and execution time analysis.
- `magic_square_result.txt`: Output file containing recorded execution times for different sizes of the magic square.

Feel free to explore and analyze the provided code and results further. If you have any questions or suggestions, please don't hesitate to reach out.

