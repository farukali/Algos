#include <iostream>
#include <list>
#include <stack>
using namespace std;
/*
 * Debanka Basu
 * Topological Sort
 * Dated:13th may 2018
 *
 * Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering
 * of vertices such that for every directed edge uv, vertex u comes before v
 * in the ordering. Topological Sorting for a graph is not possible if the
 * graph is not a DAG.
 * --- For example, a topological sorting of the following graph is “5 4 2 3 1 0”.
 * Please Note:  ø symbol points to the end node of the edge.
 *
 *       5            4
 *     .    .       .   .
 *    ø       ø   ø       ø
 *   2         0          1
 *    .                ø
 *      .            .
 *        .        .
 *          ø 3  .
 *
 *           */

class Graph
{
    int v;
    list<int> *adj;

public:
    Graph(int v);
    void addEdge(int s, int e);
    void TopologicalSort();
    void TopologicalSortUtil(int node,bool *visited,stack<int>&Si);
};

Graph::Graph(int v)
{
    this->v=v;
    adj = new list<int>[v];
}
void Graph::addEdge(int s, int e)
{
    adj[s].push_back(e);
}
void Graph:: TopologicalSortUtil(int node,bool *visited,stack<int>&Si)
{

    visited[node]=true;
    list<int>::iterator i;
    for(i=adj[node].begin();i!=adj[node].end();i++)
    {
        if(!visited[*i])
        {
            TopologicalSortUtil(*i,visited,Si);
        }
    }
    Si.push(node);
}
void Graph::TopologicalSort()
{
     stack<int>Si;
    bool *visited= new bool[v];
    for(int i=0;i<v;i++)
    {
       visited[i]= false;
    }
    for(int i=0;i<v;i++)
    {
        if(visited[i]==false)
        {
            TopologicalSortUtil(i,visited,Si);
        }
    }

    while(!Si.empty()){
        cout<<Si.top()<<" ";
        Si.pop();
    }
    cout<<endl;
}

int main() {
    Graph g (6);
    g.addEdge(5,2);
    g.addEdge(5,0);
    g.addEdge(2,3);
    g.addEdge(3,1);
    g.addEdge(4,0);
    g.addEdge(4,1);
    g.TopologicalSort();
    return 0;
}