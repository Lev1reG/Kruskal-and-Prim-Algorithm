#include <bits/stdc++.h>
using namespace std;

// Create Union-Find class
class UF{
	int *parent;
	int *rank;

    public:
	    UF(int n) {
	    	parent = new int[n];
	    	rank = new int[n];

	    	for (int i = 0; i < n; i++) {
	    		parent[i] = -1;
	    		rank[i] = 1;
	    	}
	    }

	    // Function to find the representative element
	    int find(int i) {
	    	if (parent[i] == -1)
	    		return i;

	    	return parent[i] = find(parent[i]);
	    }

	    // Union function
        // If the vertices belongs to the same set,
        // then we should not take the vertices
	    void unite(int x, int y) {
	    	int set1 = find(x);
	    	int set2 = find(y);

	    	if (set1 != set2) {
	    		if (rank[set1] < rank[set2]) {
	    			parent[set1] = set2;
	    		}
	    		else if (rank[set1] > rank[set2]) {
	    			parent[set2] = set1;
	    		}
	    		else {
	    			parent[set2] = set1;
	    			rank[set1] += 1;
	    		}
	    	}
	    }
};

class Graph {
	vector<vector<int>> edgelist;
	int V;
    int E;

    public:
	    Graph(int numVertices, int numEdges) {
            this->V = numVertices;
            this->E = numEdges;
        }

	    // Function to add an edge into the graph
	    void addEdge(int vert1, int vert2, int weight) {
	    	edgelist.push_back({weight, vert1, vert2});
	    }

        // Function to implement Kruskal's Algorithm
	    void kruskalMST() {
	    	// Sort all edges
	    	sort(edgelist.begin(), edgelist.end());

	    	// Initialize the Union-Find
	    	UF set(V);
	    	int total = 0;
	    	cout << "Following are the edges in the constructed MST" << "\n";
	    	for (auto edge : edgelist) {
	    		int weight = edge[0];
	    		int vert1 = edge[1];
	    		int vert2 = edge[2];

	    		// Take this edge in MST if it does not forms a cycle
	    		if (set.find(vert1) != set.find(vert2)) {
	    			set.unite(vert1, vert2);
	    			total += weight;
	    			cout << vert1 << " -- " << vert2 << " == " << weight << endl;
	    		}
	    	}
	    	cout << "Minimum Cost Spanning Tree: " << total << endl;

            cout << "\n";

            for (auto edge : edgelist) {
	    		int weight = edge[0];
	    		int vert1 = edge[1];
	    		int vert2 = edge[2];

	    		// Take this edge in MST if it does not forms a cycle
	    		if (set.find(vert1) == set.find(vert2)) {
	    			cout << "There is a cycle at " << vert1 << " -- " << vert2 << " == " << weight << endl;
	    		}
	    	}
	    }
};

// Driver code
int main() {
    int numVertices, numEdges;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;
    cout << "Enter the number of edges: ";
    cin >> numEdges;

    Graph g(numVertices, numEdges);

    cout << "Enter the edges in the format: (vertex1 vertex2 weight)\n";
    int vert1, vert2, weight;
    for(int i = 0; i < numEdges; i++) {
        cin >> vert1 >> vert2 >> weight;
        g.addEdge(vert1, vert2, weight);
    }

	// Function call
	g.kruskalMST();

	return 0;
}
