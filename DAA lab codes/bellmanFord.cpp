#include <iostream>
#include <climits>
using namespace std;
struct Edge
{
    int source, destination;
    float weight;
};
int main()
{
    int numVertices, numEdges, startVertex;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;
    cout<<"-------------------------------------------------------------"<<endl;
    cout << "Enter the number of edges: ";
    cin >> numEdges;
    cout<<"-------------------------------------------------------------"<<endl;
    cout << "Enter the starting vertex: ";
    cin >> startVertex;
    cout<<"-------------------------------------------------------------"<<endl;
    float distances[numVertices];
    Edge edgeList[numEdges];
    for (int i = 0; i < numVertices; i++)
    {
        distances[i] = (i == startVertex - 1) ? 0 : INT_MAX;
    }
    for (int i = 0; i < numEdges; i++)
    {
        cout << "Enter source, destination, and weight for edge " << i + 1 << ": ";
        cin >> edgeList[i].source >> edgeList[i].destination >> edgeList[i].weight;
    }
    for (int i = 0; i < numVertices - 1; i++)
    {
        for (int j = 0; j < numEdges; j++)
        {
            int u = edgeList[j].source;
            int v = edgeList[j].destination;
            float w = edgeList[j].weight;
            if (distances[u - 1] != INT_MAX && distances[v - 1] > distances[u - 1] + w)
                distances[v - 1] = distances[u - 1] + w;
        }
    }
    bool hasNegativeCycle = false;
    for (int j = 0; j < numEdges; j++)
    {
        int u = edgeList[j].source;
        int v = edgeList[j].destination;
        float w = edgeList[j].weight;
        if (distances[u - 1] != INT_MAX && distances[v - 1] > distances[u - 1] + w)
        {
            hasNegativeCycle = true;
            break;
        }
    }
    if (hasNegativeCycle){
        cout << "Graph contains negative edge cycle";
        cout<<"-------------------------------------------------------------"<<endl;
        }
    else
    {
        cout << "Shortest distances from vertex " << startVertex << ":\n";
        for (int i = 0; i < numVertices; i++)
            cout << "Vertex " << i + 1 << ": " << distances[i] << endl;
    }
    return 0;
}