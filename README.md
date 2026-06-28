# Urban Engine Flow

This project features implementations of core graph algorithms. This repository contains optimized implementations of fundamental graph traversal and shortest path algorithms, along with sample outputs.

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
│   └── Sample graph for traversal.png # Graph topology diagram used for tests
├── Network flow/
<<<<<<< HEAD
│   ├── Edmonds Karp sample output.png 
│   ├── edmonds_karp.cpp              # Edmonds-Karp maximum flow implementation
│   ├── Ford Fulkerson sample output.png
=======
│   ├── Ford Fulkerson sample output.png
>>>>>>> 0dbf1cf92cb8a282194619cca8889fb2eabdd47b
│   ├── ford_fulkerson.cpp            # Ford-Fulkerson maximum flow implementation
│   ├── Sample graph for Edmonds Karp.png # Flow network topology diagram
│   └── Sample graph for Ford Fulkerson.png # Flow network topology diagram
└── Shortest path algorithms/
    ├── Bellman Ford sample output.png
    ├── bellman_ford.cpp              # Bellman-Ford (supports negative weights)
    ├── Dijkstra sample output.png
    ├── dijkstra.cpp                  # Dijkstra's (min-priority queue optimized)
    ├── Floyd Warshall sample output.png
    ├── floyd_warshall.cpp            # Floyd-Warshall (all-pairs shortest path)
    ├── Sample graph for Bellman Ford.png # Graph topology diagram
    ├── Sample graph for Dijkstra.png     # Graph topology diagram
    └── Sample graph for Floyd Warshall.png # Graph topology diagram
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

### 3. Network Flow Algorithms

#### 🔹 Ford-Fulkerson Algorithm
- **File**: `Network flow/ford_fulkerson.cpp`
- **Description**: Computes the maximum flow in a flow network from a single source to a single sink. It uses Depth-First Search (DFS) to find augmenting paths in the residual graph.
- **Time Complexity**: $\mathcal{O}(E \times f)$ where $E$ is the number of edges and $f$ is the maximum flow of the network.
- **Space Complexity**: $\mathcal{O}(V^2)$ to store capacity and flow matrices.

#### 🔹 Edmonds-Karp Algorithm
- **File**: `Network flow/edmonds_karp.cpp`
- **Description**: Computes the maximum flow in a flow network from a single source to a single sink. It is a variation of the Ford-Fulkerson method that uses Breadth-First Search (BFS) to find augmenting paths (shortest path in terms of the number of edges).
- **Time Complexity**: $\mathcal{O}(V \times E^2)$ where $V$ is the number of vertices and $E$ is the number of edges.
- **Space Complexity**: $\mathcal{O}(V^2)$ to store capacity and flow matrices.

