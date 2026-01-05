#include<iostream>
#include<list>
#include<vector>
using namespace std;
class Graph{
    int V;
    list<int> *l;
    void helper(int node,vector<bool>&visited){
        visited[node] = true;
        cout << node << " ";
        for(int v:l[node]){
            if(!visited[v]){
                helper(v, visited);
            }
        }
    }

public:
    Graph(int v)
    {
        V = v;
        l = new list<int>[V];
    }
        void addedge(int u,int v){
            l[u].push_back(v);
            l[v].push_back(u);
        }
        void print(){
            for (int i = 0; i < V; i++){
                cout << i << " ";
                for(int n:l[i]){
                    cout << n << "->";
                }
                cout << endl;
            }
        }
        void dfs(int src){
            vector<bool> vis(V, false);
            helper(src, vis);
        }
};
int main(){
    Graph g(5);
    g.addedge(0, 1);
    g.addedge(2, 1);
    g.addedge(1, 3);
    g.addedge(2, 3);
    g.addedge(2, 4);
    g.dfs(0);
    return 0;
}
