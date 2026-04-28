#include<iostream>
#include<list>
#include<vector>
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
        l[u].push_back(v);   // directed graph
    }

    bool check(int src, vector<bool>& vis, vector<bool>& path){
        vis[src] = true;
        path[src] = true;

        for(int v : l[src]){
            if(!vis[v]){
                if(check(v, vis, path))
                    return true;
            }
            else if(path[v]){
                return true; // back edge → cycle
            }
        }

        path[src] = false;  // ✅ correct place
        return false;
    }

    bool iscycle(int src){
        vector<bool> vis(V, false);
        vector<bool> path(V, false);
        return check(src, vis, path);
    }
};

int main(){
    Graph g(5);
    g.addedge(1, 0);
    g.addedge(0, 2);
    g.addedge(2, 3);
    g.addedge(3, 0);

    if(g.iscycle(0)){
        cout << "yes";
    }
    return 0;
}
