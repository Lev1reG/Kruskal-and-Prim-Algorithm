# DESCRIPTION

<b>Explanation</b>
Here's a brief explanation about Kruskal's Algorithm.
1. Kruskal's algorithm follows a greedy approach to find an MST.
2. It starts with an empty set of edges and considers all the edges in the graph in ascending order of their weights.
3. For each edge, it checks if adding it to the current set of edges forms a cycle. If not, the edge is added to the MST.
4. Kruskal's algorithm keeps adding edges until all the vertices are connected or until V-1 edges (where V is the number of vertices) are selected.
5. This algorithm guarantees that the MST will be found, and it works well for sparse graphs (where the number of edges is significantly less than the number of vertices).
