#include<iostream>
#include<vector>
#include<list>
#include<queue>
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
        l[v].push_back(u);
    }
    bool check(int src,vector<bool>&vis){
        queue<pair<int, int>> q;
        vis[src] = true;
        q.push({src, -1});
        while(q.size()>0){
            int node = q.front().first;
            int par = q.front().second;
            q.pop();
            for(int ngh:l[node]){
                if(!vis[ngh]){
                    vis[ngh] = true;
                    q.push({ngh, node});
                }else if(ngh!=par){
                    return true;
                }
            }
        }
        return false;
    }
    bool iscycle(){
        vector<bool> vis(V, false);
        for (int i = 0; i < V;i++){
            if(!vis[i]){
                if (check(i, vis)) {
                    return true;
                }
            }
        }
        return false;
    }
};
int main(){
    Graph g(5);
    g.addedge(0, 1);
    g.addedge(0, 2);
    g.addedge(0, 3);
    g.addedge(1, 2);
    g.addedge(3, 4);
    if(g.iscycle()){
        cout << "yes";
    }
    return 0;
}
