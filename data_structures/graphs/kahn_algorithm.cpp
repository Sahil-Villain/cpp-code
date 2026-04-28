#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;
class Graph{
    int V;
    list<int> *l;
    public:
    Graph(int V){
        this->V = V;
        l = new list<int>[V];
    }
    void addedge(int u,int v){
        l[u].push_back(v);
    }
    void kann(){
        vector<int> res;
        vector<int> deg(V, 0);
        for (int u = 0; u < V;u++){
            for(int v:l[u]){
                deg[v]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < V;i++){
            if(deg[i]==0){
                q.push(i);
            }
        }
        while(q.size()>0){
            int curr = q.front();
            res.push_back(curr);
            q.pop();
            for(int v:l[curr]){
                deg[v]--;
                if(deg[v]==0){
                    q.push(v);
                }
            }
        }
        for(int i:res){
            cout << i << " ";
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
    g.kann();
    return 0;
}
