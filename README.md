**README: Analysis and Design of Single Source Shortest Path Algorithm**

### Aim
The aim of this project is to implement and analyze the Single Source Shortest Path (SSSP) algorithm. Given a graph and a source vertex, the objective is to find the shortest distance from the source vertex to all other vertices in the graph.

### Algorithm
The Single Source Shortest Path algorithm follows the steps outlined below:
1. Initialize an array `dist[]` to store the shortest distance from the source vertex to each vertex in the graph.
2. Initialize an array `signal[]` to keep track of visited vertices.
3. Start with the source vertex. For each iteration:
   - Choose a vertex `u` such that `signal[u]` is false (not visited) and `dist[u]` is minimum.
   - Update the distance to neighboring vertices of `u` if the path through `u` offers a shorter distance.
4. Repeat until all vertices are visited.

### Source Code
The provided source code (`sssp.cpp`) includes the implementation of the SSSP algorithm using C++. The code utilizes a `graph` class to represent the graph and performs operations such as adding edges, computing distances, and updating distances based on the shortest path.

### Execution and Output
The program prompts the user to enter the number of nodes, edges, and the type of graph (directed or undirected). It then allows the user to input the edges and their weights. Afterward, it calculates and displays the shortest path length from the source vertex to all other vertices.

### Conclusion
- The Single Source Shortest Path algorithm efficiently computes the shortest path from a source vertex to all other vertices in a graph.
- The time complexity of the SSSP algorithm is O(n^2), where n is the number of vertices in the graph.
- The output provides the shortest path lengths from the source vertex to all other vertices, facilitating further analysis and understanding of the algorithm's performance.

Feel free to explore the source code and experiment with different graphs and inputs. If you have any questions or suggestions, please let me know!
