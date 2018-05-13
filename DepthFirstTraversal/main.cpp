#include <iostream>
# include <iostream>
#include <list>
# include <stack>
using namespace std;
class Graph
{
    int v;
    list<int>*adj;

    public:
    Graph(int v);
    void addEdge(int start , int end);
    void Iterative_DFS(int s);
    void Recursive_DFS(int s);
};
Graph::Graph(int v)
{
this->v = v;
adj = new list<int>[v];
}
void Graph::addEdge(int s , int e)
{
adj[s].push_back(e);
}

void Graph::Iterative_DFS(int s) {
    bool visited[v];
    for(int i=0;i<v;i++){
        visited[i]=false;
    }
    stack<int>Si;
    Si.push(s);
    visited[s]=true;
    list<int>::iterator i;

    while(!Si.empty())
    {
        int node = Si.top();
        cout<<node<<" ";
        Si.pop();
        for( i = adj[node].begin();i!=adj[node].end();++i)
        {
            if(!visited[*i])
            {
                Si.push(*i);
                visited[*i] = true;
            }
        }
    }
    cout<<endl;
}
int main() {

cout<<"This is an implementation of a Graph Depth First Traversal using adjacency list!";
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(2,0);
    g.addEdge(3,3);
    cout<<"Following order is due to the "
         <<"output of depth first traversal from starting node (2)\n";
    g.Iterative_DFS(2);
    return 0;
}