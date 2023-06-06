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
    adjacencyMatrix[baris][kolom] = weight;
    adjacencyMatrix[kolom][baris] = weight;
}
int main()
{
    int vertices = 7;
    add_edge(0, 1, 2);
    add_edge(0, 3, 1);
    add_edge(0, 2, 4);
    add_edge(1, 3, 3);
    add_edge(1, 4, 10);
    add_edge(2, 3, 2);
    add_edge(2, 5, 5);
    add_edge(3, 4, 7);
    add_edge(3, 5, 8);
    add_edge(3, 6, 4);
    add_edge(4, 6, 6);
    add_edge(5, 6, 1);

    displayMatrix(vertices);
}
