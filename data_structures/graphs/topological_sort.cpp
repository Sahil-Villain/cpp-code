#include<iostream>
#include<list>
#include<vector>
#include<stack>
using namespace std;

class Graph{
    int V;
    list<int> *l;

public:
    Graph(int v){
        V = v;
        l = new list<int>[V];
    }

    void addedge(int u,int v){
        l[u].push_back(v); 
    }
    void dfs(int src,vector<bool>&vis,stack<int>&s){
        vis[src] = true;
        for(int v:l[src]){
            if(!vis[v]){
                dfs(v, vis, s);
            }
        }
        s.push(src);
    }
    void topologica(){
        stack<int> s;
        vector<bool> vis(V, false);
        for (int i = 0; i < V;i++){
            if(!vis[i]){
                dfs(i, vis, s);
            }
        }
        while(s.size()>0){
            cout << s.top() << " ";
            s.pop();
        }
    }
};

int main(){
    Graph g(6);
    g.addedge(3, 1);
    g.addedge(2, 3);
    g.addedge(4, 0);
    g.addedge(4, 1);
    g.addedge(5, 0);
    g.addedge(5, 3);
    g.topologica();
    return 0;
}
