#include<iostream>
#include<list>
#include<vector>
#include<queue>
using namespace std;
class Graph{
    int V;
    list<int> *l;
    public:
        Graph(int V){
            V = V;
            l = new list<int>[V];
        }
        void addedge(int u,int v){
            l[u].push_back(v);
            l[v].push_back(u);
        }
        void print(){
            for (int i = 0; i < V; i++){
                for(int n:l[i]){
                }
                cout << endl;
            }
        }
        void bfs(int src){
            queue<int> q;
            vector<bool> vis(V, false);
            q.push(src);
            vis[src] = true;
            while(q.size()>0){
                int u = q.front();
                q.pop();
                cout << u << " ";
                for(int v:l[u]){
                    if(!vis[v]){
                        vis[v] = true;
                        q.push(v);
                    }
                }
            }
        }
};
int main(){
    Graph g(6);
    g.addedge(0, 1);
    g.addedge(0, 2);
    g.addedge(1, 3);
    g.addedge(1, 4);
    g.addedge(2, 5);
    g.bfs(0);
    return 0;
}
