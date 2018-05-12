#include <iostream>
#include <list>
using namespace std;
class Graph
{
 int V;
 list<int> *adj;
 public:
 Graph(int v);
 void addEdge(int start, int end);
 void BFS(int source);
};
Graph::Graph(int V)
{
this->V = V;
adj = new list<int>[V];
}
void Graph::addEdge(int start, int end)
{
    adj[start].push_back(end);
}
void Graph::BFS(int s)
{
    bool visited[V];
    for (int i =0 ;i<V;i++)
    {
        visited[i]=false;
    }

    list<int>Qi;
    Qi.push_back(s);
    visited[s]=true;
list<int>::iterator i;
    while(!Qi.empty())
    {
        int node = Qi.front();
        cout<<node<<" ";
        Qi.pop_front();

        for( i = adj[node].begin(); i!=adj[node].end();i++)
        {
            if(!visited[*i])
            {
                visited[*i]=true;
                Qi.push_back(*i);
            }

        }
    }
    cout<<endl;
}
int main() {
    cout<<"This is an implementation of a Graph BFS traversal using adjacency list! "<<endl;
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);
    return 0;
}