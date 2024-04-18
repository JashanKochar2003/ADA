**README: Analysis and Design of Knapsack Algorithm**

### Overview
The Knapsack Algorithm addresses the problem of selecting items from a set of available options to maximize profit while staying within a given weight capacity. This problem is often encountered in resource allocation scenarios, where the goal is to optimize the value of items selected for a limited resource (the knapsack). Three different approaches are explored in this implementation: selecting items based on higher profit, higher weight, and higher profit-to-weight ratio (profit/weight fraction). 

### Problem Definition
Given a set of items with associated weights and profits, along with a knapsack of limited capacity, the objective is to select a combination of items that maximizes the total profit while ensuring that the total weight does not exceed the capacity of the knapsack.

### Algorithm
The algorithm follows a greedy approach and explores three different strategies for item selection:
1. **Based on Higher Profit**: Select items with the highest profit first.
2. **Based on Higher Weight**: Select items with the highest weight first.
3. **Based on Higher Profit/Weight Ratio**: Select items with the highest profit-to-weight ratio first.

### Source Code
The provided source code (`knapsack.cpp`) implements the Knapsack Algorithm using a greedy approach and measures the total profit obtained using each of the three selection strategies. It employs the Quick Sort algorithm to sort the items based on different criteria before making the selections.

### Execution and Output
The code computes the total profit obtained using each selection strategy for different sizes of the item set. Here's a summary of the output:
- Total profit obtained using profit/weight selection: [List of values]
- Total profit obtained using profit selection: [List of values]
- Total profit obtained using weight selection: [List of values]

### Conclusion
- The Knapsack Algorithm efficiently selects items to maximize profit while staying within the weight capacity of the knapsack.
- By comparing the total profits obtained using different selection strategies, the optimal approach is identified.
- The time complexity of the Knapsack Algorithm is determined to be O(n log n), where n is the number of items in the set.
- The analysis reveals that selecting items based on the profit-to-weight ratio yields the highest total profit, making it the optimal strategy for the Knapsack problem.

Feel free to explore the source code and results further. If you have any questions or suggestions, please don't hesitate to reach out.
