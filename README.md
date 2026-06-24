# Urban Engine Flow

This project features implementations of core graph algorithms. This repository contains optimized implementations of fundamental graph traversal and shortest path algorithms, along with sample outputs and visualizations.

---

## Repository Structure

The project is structured into two main directories based on algorithm categories:

```text
C:\Urban-Engine-Flow
├── Graph traversal algorithms/
│   ├── BFS Sample output.png
│   ├── bfs.cpp                       # Breadth-First Search implementation
│   ├── DFS sample output.png
│   ├── dfs.cpp                       # Depth-First Search implementation
│   └── Sample graph for traversal.png # Graph topology used for tests
└── Shortest path algorithms/
    ├── Bellman Ford sample output.png
    ├── bellman_ford.cpp              # Bellman-Ford (supports negative weights)
    ├── Dijkstra sample output.png
    ├── dijkstra.cpp                  # Dijkstra's (min-priority queue optimized)
    ├── Floyd Warshall sample output.png
    └── floyd_warshall.cpp            # Floyd-Warshall (all-pairs shortest path)
```

---

## Algorithms Overview

### 1. Graph Traversal Algorithms

#### 🔹 Breadth-First Search (BFS)
- **File**: `Graph traversal algorithms/bfs.cpp`
- **Description**: Traverses the graph level by level starting from a specified source node. It uses a queue to track nodes to visit.
- **Time Complexity**: $\mathcal{O}(V + E)$ where $V$ is vertices and $E$ is edges.
- **Space Complexity**: $\mathcal{O}(V)$.

#### 🔹 Depth-First Search (DFS)
- **File**: `Graph traversal algorithms/dfs.cpp`
- **Description**: Explores as deep as possible along each branch before backtracking. It uses recursion (call stack) to traverse the nodes.
- **Time Complexity**: $\mathcal{O}(V + E)$.
- **Space Complexity**: $\mathcal{O}(V)$ auxiliary space.

---

### 2. Shortest Path Algorithms

#### 🔹 Dijkstra's Algorithm
- **File**: `Shortest path algorithms/dijkstra.cpp`
- **Description**: Finds the shortest paths from a single source node to all other nodes in a graph with non-negative edge weights. Optimized using a min-heap priority queue (`std::priority_queue`).
- **Time Complexity**: $\mathcal{O}((V + E) \log V)$.
- **Space Complexity**: $\mathcal{O}(V + E)$ for adjacency list.

#### 🔹 Bellman-Ford Algorithm
- **File**: `Shortest path algorithms/bellman_ford.cpp`
- **Description**: Computes shortest paths from a single source vertex to all of the other vertices in a weighted graph. Unlike Dijkstra, it can handle negative edge weights and detects negative weight cycles.
- **Time Complexity**: $\mathcal{O}(V \times E)$.
- **Space Complexity**: $\mathcal{O}(E)$ to store edges.

#### 🔹 Floyd-Warshall Algorithm
- **File**: `Shortest path algorithms/floyd_warshall.cpp`
- **Description**: A dynamic programming algorithm to find shortest paths between all pairs of vertices in a weighted graph. It also handles negative edge weights and detects negative cycles (indicated by negative values on the main diagonal of the distance matrix).
- **Time Complexity**: $\mathcal{O}(V^3)$.
- **Space Complexity**: $\mathcal{O}(V^2)$ matrix storage.

---

## Compilation and Execution

All source files are written in standard C++. You can compile them using any modern C++ compiler (such as `g++` or `clang++`).

### Compiling and Running a File
To compile a C++ file, run the following command in your terminal:

```bash
# Example for Dijkstra
g++ -std=c++17 "Shortest path algorithms/dijkstra.cpp" -o dijkstra

# Run the executable
./dijkstra
```

---

## Input / Output Format

All programs read from standard input (`stdin`) and write to standard output (`stdout`).

### Example: Running Dijkstra's Algorithm
1. **Input Requirements**:
   - Number of nodes.
   - Graph type: `1` for Directed, `2` for Undirected.
   - Number of edges.
   - For each edge: source node, destination node, and weight.
   - Source node.

2. **Sample Input**:
   ```text
   5
   1
   6
   1 2 4
   1 3 2
   2 3 3
   2 4 2
   3 5 3
   4 5 1
   1
   ```

3. **Sample Output**:
   ```text
   Shortest distances:
   1 -> 1 = 0
   1 -> 2 = 4
   1 -> 3 = 2
   1 -> 4 = 6
   1 -> 5 = 5
   ```

---

## Visualizations and Outputs

Sample outputs and graph topologies used in testing are captured in visual formats:

| Category | File / Visualization Link | Description |
|---|---|---|
| **Graph Traversal** | [Sample Graph](Graph%20traversal%20algorithms/Sample%20graph%20for%20traversal.png) | Visual representation of the topology used for BFS/DFS. |
| **Graph Traversal** | [BFS Traversal Output](Graph%20traversal%20algorithms/BFS%20Sample%20output.png) | Step-by-step console execution log for BFS. |
| **Graph Traversal** | [DFS Traversal Output](Graph%20traversal%20algorithms/DFS%20sample%20output.png) | Step-by-step console execution log for DFS. |
| **Shortest Path** | [Dijkstra Path Output](Shortest%20path%20algorithms/Dijkstra%20sample%20output.png) | Shortest distance results using Dijkstra's Algorithm. |
| **Shortest Path** | [Bellman Ford Output](Shortest%20path%20algorithms/Bellman%20Ford%20sample%20output.png) | Shortest distance results using Bellman-Ford. |
| **Shortest Path** | [Floyd Warshall Output](Shortest%20path%20algorithms/Floyd%20Warshall%20sample%20output.png) | Matrix output showing All-Pairs Shortest Paths. |

---

