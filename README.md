**README: Assignment 18 - Activity Selection Algorithm**

### Overview
The Activity Selection Algorithm addresses the problem of scheduling activities to maximize the number of tasks that can be completed without conflicting schedules. Given the start and finish times of each activity, the goal is to select a maximum number of non-overlapping activities. Three different approaches are explored in this implementation: selecting activities based on their starting time, finishing time, and duration. 

### Problem Definition
Given a set of activities with their corresponding start and finish times, the objective is to select a subset of activities such that no two activities overlap, and the maximum number of activities are scheduled.

### Algorithm
The algorithm follows a greedy approach and explores three different strategies for activity selection:
1. **Based on Starting Time**: Select activities with the earliest starting time first.
2. **Based on Finishing Time**: Select activities with the earliest finishing time first.
3. **Based on Duration**: Select activities with the shortest duration first.

### Source Code
The provided source code (`activity_selection.cpp`) implements the Activity Selection Algorithm using a greedy approach and measures the total number of activities selected using each of the three selection strategies. It employs Quick Sort algorithm to sort the activities based on different criteria before making the selections.

### Execution and Output
The code computes the total number of activities selected using each selection strategy for different sizes of the activity set. The output presents the total number of activities selected based on starting time, finishing time, and duration for each set size.

### Conclusion
- The Activity Selection Algorithm efficiently schedules non-overlapping activities to maximize the number of tasks completed.
- By comparing the total number of activities selected using different selection strategies, the optimal approach is identified.
- The analysis reveals that selecting activities based on their finishing time yields the highest number of activities selected, making it the optimal strategy for the Activity Selection problem.

Feel free to explore the source code and results further. If you have any questions or suggestions, please don't hesitate to reach out.
