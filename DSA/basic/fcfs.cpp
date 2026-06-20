#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    // unordered_map<int,vector<int>>m;
    // for (int i = 0; i < 4;i++){
    //     // cout<<"Enter AT"<<i+1<<": ";
    //     cout<<"P"<<i+1<<" ";
    //     for (int i = 0;i<2;i++){
    //         int x;
    //         cin>>x;
    //         m[i].push_back(x);
    //     }
    // }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    for (int i = 0; i < n;i++){
        int at,bt;
        cin>>at>>bt;
        pq.push({at,bt});
    }
    int time = 0;
    while(!pq.empty()){
        auto p = pq.top();
        pq.pop();
        if(p.first>time){
            time = p.first;
        }
        time+=p.second;
        cout<<"Process with AT: "<<p.first<<" and BT: "<<p.second<<" completed at time: "<<time<<endl;
    }
        return 0;
}