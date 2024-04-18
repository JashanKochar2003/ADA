**README: Analysis and Design of Sum of Subset Algorithm**

### AIM
The aim of this project is to implement and analyze the Sum of Subset algorithm. Given a set of numbers, the algorithm finds subsets whose sum is equal to a specified target sum.

### Algorithm
The Sum of Subset algorithm follows these steps:
1. Define a recursive function `sumOfSubset` to explore all possible subsets of the given set.
2. At each step, choose whether to include or exclude the current element in the subset.
3. If the sum of the current subset equals the target sum, print the subset.
4. If the current element can be included without exceeding the target sum, recursively call `sumOfSubset` to explore further subsets with the included element.
5. If excluding the current element does not violate the target sum condition, recursively call `sumOfSubset` without including the element.

### Source Code
The provided source code (`SumOfSubset.cpp`) implements the Sum of Subset algorithm using C++. It takes an array of integers and a target sum as input and finds all subsets whose sum equals the target sum.

### Execution and Output
1. The program prompts the user to enter the total number of elements and the target sum.
2. It then prompts the user to enter the numbers.
3. It finds and prints all subsets whose sum equals the target sum.
4. Each output line represents a subset where '1' indicates inclusion, and '0' indicates exclusion of the corresponding element.

### Conclusion
- The Sum of Subset algorithm efficiently finds all possible subsets whose sum matches a given target sum.
- It uses backtracking to explore all possible combinations of elements, pruning branches that lead to sums exceeding the target.
- The algorithm's time complexity depends on the size of the input set and the target sum, making it suitable for small to moderate-sized problems.

Feel free to explore the source code and experiment with different input values. If you have any questions or suggestions, please let me know!
