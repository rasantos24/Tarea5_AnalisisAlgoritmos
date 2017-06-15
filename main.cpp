#include "Test.h"
#include <iostream>
#include "Edge.h"

using namespace std;

map<int,bool> visited;

int **graph(int size)
{
    int **salida = new int* [size];

    for(int i=0; i<size; i++)
    {
        salida[i] = new int[size];
        for(int j=0; j<size; j++)
            salida[i][j]=-1;
    }

    return salida;
}

int** resultado(vector<Edge*> edges, int size)
{
    int** result = graph(size);

    for(int i=0; i<(int)edges.size(); ++i)
    {
        result[edges[i]->source][edges[i]->destination] = edges[i]->weight;
        result[edges[i]->destination][edges[i]->source] = edges[i]->weight;
    }

    return result;
}

bool ciclos(Edge* edge, vector<Edge *> edges)
{
    return visited[edge->source] && visited[edge->destination];
}

int** getKruskalMST(int** graph, int size, vector<Edge*> edges)
{
    vector<Edge *> newE;
    visited.clear();
    for(int i=0; i<(int)edges.size(); i++)
    {
        if(!ciclos(edges[i], newE))
        {
            visited[edges[i]->source] = true;
            visited[edges[i]->destination] = true;
            newE.push_back(edges[i]);
        }
    }

    return resultado(newE,size);
}

int main ()
{
    test();
    return 0;
}
