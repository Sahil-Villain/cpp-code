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
            l[u].push_back(v);
            l[v].push_back(u);
        }
        void print(){
            for (int i = 0; i < V; i++){
                cout << i << " ";
                for(int n:l[i]){
                    cout << n << " ";
                }
                cout << endl;
            }
        }
        bool iscycle(int src,int par,vector<bool>&vis){
            vis[src] = true;
            list<int> neighbour = l[src];
            for(int v:neighbour){
                if(!vis[v]){
                    if(iscycle(v,src,vis)){
                        return true;
                    }
                }else if(v!=par){
                    return true;
                }
            }
            return false;
        }
        bool checkcycle(){
            vector<bool> vis(V, false);
            for (int i = 0; i < V;i++){
                if((!vis[i])){
                    if(iscycle(i,-1,vis)){
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
    // g.print();
    if(g.checkcycle()){
        cout << "yes";
    }
    return 0;
}
