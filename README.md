**README: Analysis and Design of Prim's Algorithm**

### Aim
The aim of this project is to implement and analyze Prim's Algorithm, a greedy algorithm used to find the minimum spanning tree (MST) from a graph. Prim's algorithm selects the subset of edges that includes every vertex of the graph while minimizing the sum of edge weights.

### Algorithm
Prim's Algorithm follows these steps:
1. Start with a single node and explore all adjacent nodes with connecting edges at each step.
2. Select the edges with the minimum weights that do not create cycles in the graph.
3. Repeat until all vertices are included in the minimum spanning tree.

### Source Code
The provided source code (`prims2.cpp`) implements Prim's Algorithm using C++. It utilizes a `graph` class to represent the graph and performs operations such as adding edges and computing the minimum spanning tree.

### Execution and Output
1. The program prompts the user to enter 1 for a directed graph or 0 for an undirected graph.
2. It then generates random edges and weights for the graph and calculates the minimum spanning tree using Prim's algorithm.
3. The execution time for different numbers of vertices is recorded and averaged over multiple runs.
4. The average execution time for each number of vertices is printed, and the data is saved to a file for further analysis.

### Conclusion
- Prim's Algorithm efficiently finds the minimum spanning tree of a graph by selecting edges with minimum weights.
- The time complexity of Prim's Algorithm is O(n^2), where n is the number of vertices in the graph.
- The output provides insights into the performance of Prim's Algorithm for different sizes of graphs, facilitating further analysis and understanding of its efficiency.

Feel free to explore the source code and experiment with different graph sizes and configurations. If you have any questions or suggestions, please let me know!
