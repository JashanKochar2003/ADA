**README: Analysis and Design of Multi-Stage Graph Algorithm**

### Aim
The objective of this project is to implement and analyze the Multi-Stage Graph Algorithm. This algorithm is used to find the shortest path from a source vertex to a sink vertex in a directed graph where vertices are arranged in multiple stages, and edges exist only between adjacent stages.

### Algorithm
The Multi-Stage Graph Algorithm follows these steps:
1. Initialize the final cost array (`fcost`) with zeros and the decision array (`d`) with -1.
2. Starting from the penultimate stage, find the minimum cost path to the next stage and update the `fcost` and `d` arrays accordingly.
3. Calculate the path from the source to the sink vertex using the decision array.
4. Output the shortest path.

### Source Code
The provided source code (`multiStageGraph.cpp`) implements the Multi-Stage Graph Algorithm using C++. It utilizes a `graph` class to represent the graph and performs operations such as adding edges and computing the shortest path.

### Execution and Output
1. The program prompts the user to enter the number of nodes and edges in the graph and whether it's directed or undirected.
2. It then generates the graph based on user input and calculates the number of stages in the graph.
3. The algorithm computes the shortest path from the source to the sink vertex using the final cost array and decision array.
4. The program outputs the number of stages and the shortest path from the source to the sink vertex.

### Conclusion
- The Multi-Stage Graph Algorithm efficiently finds the shortest path in a directed graph with multiple stages.
- It reduces the problem complexity by breaking it into smaller subproblems, making it suitable for large graphs.
- The algorithm's time complexity depends on the number of vertices and edges in the graph, making it suitable for real-world applications with varying graph sizes.

Feel free to explore the source code and experiment with different graph configurations. If you have any questions or suggestions, please let me know!
