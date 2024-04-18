**README: Analysis and Design of Tower of Hanoi Algorithm**

### Overview
This code provides an analysis and implementation of the Tower of Hanoi algorithm, a classic mathematical puzzle. The Tower of Hanoi puzzle involves moving a stack of disks from one rod to another, obeying certain rules, with the objective of transferring the entire stack to a different rod.

### Tower of Hanoi Puzzle
In the Tower of Hanoi puzzle:
- Three rods (A, B, and C) and N disks are used.
- Initially, all disks are stacked on rod A in decreasing order of size.
- Rules:
  - Only one disk can be moved at a time.
  - Each move involves taking the uppermost disk from one stack and placing it on top of another.
  - No disk can be placed on top of a smaller disk.

### Algorithm
The Tower of Hanoi algorithm follows a recursive pattern:
1. Move N-1 disks from source to spare, using destination as a helper.
2. Move the last disk from source to destination.
3. Move N-1 disks from spare to destination, using source as a helper.

### Source Code
The provided source code (`tower_of_hanoi.cpp`) contains the implementation of the Tower of Hanoi algorithm along with code for measuring the execution time for different numbers of disks.

### Execution
To execute the code:
1. Compile the source code.
2. Run the compiled executable.
3. The program will simulate the Tower of Hanoi puzzle for various numbers of disks and measure the average execution time.

### Output
The program output provides insights into the execution time for different numbers of disks. Here's a sample output:
```
avg time taken by disc 2 is 4177 nanoseconds
avg time taken by disc 4 is 224444 nanoseconds
avg time taken by disc 8 is 334993 nanoseconds
avg time taken by disc 16 is 70619047 nanoseconds
```

### Conclusion
Based on the observed execution times, it can be concluded that the time complexity of the Tower of Hanoi problem is O(2^n), where n is the number of disks. This exponential time complexity is a characteristic of the recursive nature of the algorithm.

### Graphical Representation
For a graphical representation of the execution times, you can refer to the time complexity folder.

### Files
- `tower_of_hanoi.cpp`: Contains the source code for the algorithm implementation and execution time analysis.
- `tower_of_hanoi.txt`: Output file containing recorded execution times for different numbers of disks.

Feel free to explore and analyze the provided code and results further. If you have any questions or suggestions, please don't hesitate to reach out.
