# DESCRIPTION

## Introduction ##
Kruskal's algorithm is a greedy algorithm used to find the minimum spanning tree (MST) of a connected, weighted graph. An MST is a tree that spans all the vertices of the graph with the minimum possible total edge weight. </br>

## Algorithm ##
The algorithm works as follows:

1. Sort all the edges of the graph in non-decreasing order of their weights.
2. Initialize an empty set to store the MST.
3. Iterate through the sorted edges in increasing order of weights.
4. For each edge, check if adding it to the MST creates a cycle. If not, add the edge to the MST.
    - This cycle check is typically performed using a disjoint set data structure, such as Union-Find.
    - The Union-Find data structure helps to determine whether two vertices are in the same connected component (set) or not.
5. Repeat step 4 until all the vertices are included in the MST or there are no more edges left.
6. The resulting set of edges forms the minimum spanning tree of the graph.

</br>
Kruskal's algorithm guarantees that the MST obtained will have the minimum possible total weight. It works on both weighted and unweighted graphs and can handle disconnected graphs as well.
</br>

## Time Complexity ##
The time complexity of Kruskal's algorithm is ``O(E log E)``, where E is the number of edges in the graph. Sorting the edges takes ``O(E log E)`` time, and the disjoint set operations take nearly constant time on average using heuristics like union by rank and path compression.

## Summary ##
Overall, Kruskal's algorithm provides an efficient approach to find the minimum spanning tree in a graph, making it useful in various applications such as network design, clustering, and scheduling.

### Read More ###
For further explanation, click on [this](https://docs.google.com/document/d/12n9dBXBuOVubDQPRqd-jFxwX-ysVpSQKPoMmCeSDW0Y/edit?usp=sharing)





