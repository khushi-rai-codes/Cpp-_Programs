#include <iostream>
using namespace std;
#define V 4
bool isSafe(
    int vertex,
    int graph[V][V],
    int colors[],
    int color
)
{
    for (int i = 0; i < V; i++)
    {
        if (graph[vertex][i] &&
            colors[i] == color)
        {
            return false;
        }
    }
    return true;
}
bool colorGraph(
    int graph[V][V],
    int colors[],
    int vertex,
    int numberOfColors
)
{
    if (vertex == V)
        return true;
    for (int color = 1;
         color <= numberOfColors;
         color++)
    {
        if (isSafe(
                vertex,
                graph,
                colors,
                color))
        {
            colors[vertex] = color;
            if (colorGraph(
                    graph,
                    colors,
                    vertex + 1,
                    numberOfColors))
            {
                return true;
            }
            colors[vertex] = 0;
        }
    }
    return false;
}
int main()
{
    int graph[V][V] =
    {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };
    int numberOfColors = 3;
    int colors[V] = {0};
    if (colorGraph(
            graph,
            colors,
            0,
            numberOfColors))
    {
        cout << "Graph Coloring:\n";

        for (int i = 0; i < V; i++)
        {
            cout << "Vertex " << i
                 << " -> Color "
                 << colors[i] << endl;
        }
    }
    else
    {
        cout << "Coloring is not possible.\n";
    }

    return 0;
}
