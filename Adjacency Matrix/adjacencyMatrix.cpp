#include <iostream>
using namespace std;

int adjacencyMatrix[20][20];
void displayMatrix(int totalVertices)
{
    int i, j;
    for (i = 0; i < totalVertices; i++)
    {
        for (j = 0; j < totalVertices; j++)
        {
            cout << adjacencyMatrix[i][j] << "\t";
        }
        cout << endl;
    }
}
void add_edge(int baris, int kolom, int weight)
{ // Karena undirected jadi a ke b dengan b ke a itu sama
    adjacencyMatrix[baris - 1][kolom - 1] = weight;
    adjacencyMatrix[kolom - 1][baris - 1] = weight;
}
int main()
{
    int vertices, edges;
    cout << "Input number of vertices: ";
    cin >> vertices;
    cout << "Input number of edges: ";
    cin >> edges;

    cout << "Enter the edges in the format: (vertex1 vertex2 weight)\n";
    cout << "v1 | v2 | w\n";
    int startVertices, destinationVertices, cost;
    for (int i = 0; i < edges; i++)
    {
        cin >> startVertices >> destinationVertices >> cost;
        add_edge(startVertices, destinationVertices, cost);
    }

    cout << "------------------------------------------------------------------\n";
    cout << "Adjacency Matrix: \n";
    displayMatrix(vertices);
}
