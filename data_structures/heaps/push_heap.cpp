#include<iostream>
#include<vector>
using namespace std;
class Heap{
    vector<int> hp;
    public:
        void push(int val){
            hp.push_back(val);
            int x=hp.size()-1;
            int par = (x - 1) / 2;
            while(par>=0 && hp[x]>hp[par]){
                swap(hp[x], hp[par]);
                x = par;
                par = (x - 1) / 2;
            }
        }
        void show(){
            for (int i = 0; i < hp.size();i++){
                cout << hp[i];
            }
        } 
};
int main(){
    Heap obj;
    obj.push(1);
    obj.push(2);
    obj.push(3);
    obj.push(4);
    obj.push(5);
    obj.push(7);
    obj.show();
    return 0;
}
