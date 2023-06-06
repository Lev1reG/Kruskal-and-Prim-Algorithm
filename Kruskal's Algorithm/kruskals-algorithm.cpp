#include <bits/stdc++.h>
#include <sys/time.h>
#include <iomanip>
#include <cmath>
using namespace std;

// Create struct for time stamp
struct timeval start, stop;

// Create class for Union-Find
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
	    	if (parent[i] == -1) {
	    		return i;
			}
			else {
	    		return parent[i] = find(parent[i]);
			}
	    }

	    // Function to do the union
        // If the vertices belongs to the same set,
        // then we should not take the vertices
	    void unite(int vert1, int vert2) {
	    	int set1 = find(vert1);
	    	int set2 = find(vert2);

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

        // Function to implement the Kruskal's Algorithm
	    void kruskalMST() {
            // Start measuring the time
            gettimeofday(&start, 0);
	    	// Sort all edges ascendingly
	    	sort(edgelist.begin(), edgelist.end());

	    	// Initialize the Union-Find
	    	UF set(E);
	    	int total = 0;
	    	cout << "\nFollowing are the edges in the constructed MST\n";
            cout << "\nv1  " << "v2  " << "weight\n";
            cout << "--------------\n";
	    	for (auto edge : edgelist) {
	    		int weight = edge[0];
	    		int vert1 = edge[1];
	    		int vert2 = edge[2];

	    		// Take the edge into the MST
				// if it does not form a cycle
	    		if (set.find(vert1) != set.find(vert2)) {
	    			set.unite(vert1, vert2);
	    			total += weight;
	    			cout << vert1 << " -- " << vert2 << " == " << weight << "\n";
	    		}
	    	}
			// Display the minimum cost of the MST
	    	cout << "Minimum Cost Spanning Tree: " << total << "\n\n";

			// Stop measuring the time
			gettimeofday(&stop, 0);
            cout << "\n";

            for (auto edge : edgelist) {
	    		int weight = edge[0];
	    		int vert1 = edge[1];
	    		int vert2 = edge[2];

	    		// Show which vertices make a cycle
	    		if (set.find(vert1) == set.find(vert2)) {
	    			cout << "There is a cycle at " << vert1 << " -- " << vert2 << " == " << weight << "\n";
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
	cout << "v1 | v2 | w\n";
    int vert1, vert2, weight;
    for(int i = 0; i < numEdges; i++) {
        cin >> vert1 >> vert2 >> weight;
        g.addEdge(vert1, vert2, weight);
    }

	// Function call
	g.kruskalMST();

    // Calculating the execution time
    long long seconds = start.tv_sec - stop.tv_sec;
    long long microseconds = start.tv_usec - stop.tv_usec;
    long double elapsed = seconds*1000 + microseconds*1e-3;
	cout << "The execution time is " << setprecision(10) << abs(elapsed) << " milliseconds";

	return 0;
}

// tes