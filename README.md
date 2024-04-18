**README: Analysis and Design of Scalar Matrix Multiplication Algorithm (Dynamic Programming)**

### AIM
The aim of this project is to implement and analyze the Scalar Matrix Multiplication algorithm using dynamic programming. Given a sequence of matrices, the algorithm finds the optimal way to multiply them together to minimize the total number of scalar multiplications.

### Algorithm
The Scalar Matrix Multiplication algorithm follows these steps:
1. Define a function `MatrixChainOrder` that takes a vector `p` representing the dimensions of the matrices as input.
2. Create two 2D arrays `m` and `s` to store the minimum number of scalar multiplications and the split points, respectively.
3. Iterate through the chain lengths `l` from 2 to `n`, where `n` is the number of matrices.
4. For each chain length, iterate through all possible splits and calculate the minimum number of scalar multiplications required for that split.
5. Update `m` and `s` accordingly.
6. Print the minimum number of scalar multiplications and the optimal parenthesization using the split points stored in `s`.

### Source Code
The provided source code (`ScalarMatrixMultiplication.cpp`) implements the Scalar Matrix Multiplication algorithm using C++. It takes a vector representing the dimensions of the matrices as input and prints the minimum number of scalar multiplications along with the optimal parenthesization.

### Execution and Output
1. The program defines the dimensions of the matrices and calls the `MatrixChainOrder` function with the vector `p`.
2. The function calculates and prints the minimum number of scalar multiplications required and the optimal parenthesization.

### Conclusion
- The Scalar Matrix Multiplication algorithm efficiently finds the optimal way to multiply a sequence of matrices to minimize the total number of scalar multiplications.
- It uses dynamic programming to avoid redundant calculations and optimize the solution.
- The algorithm's time complexity depends on the number of matrices and their dimensions, making it suitable for moderate to large-sized matrix chains.

Feel free to explore the source code and experiment with different matrix dimensions. If you have any questions or suggestions, please let me know!
