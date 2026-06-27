#include<iostream>
#include<vector>
using namespace std;
class Heap{
    vector<int> hp;
    private:
        void heapify(int i){
            int largest = i;
            int left = 2*i +1;
            int right = 2*i +2;
            if(left < hp.size() && hp[left] > hp[largest]) largest = left;
            if(right < hp.size() && hp[right] > hp[largest]) largest = right;
            if(largest != i){
                swap(hp[i], hp[largest]);
                heapify(largest);
            }
        }
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
        int pop(){
            if(hp.empty()) return -1;
            int val = hp[0];
            hp[0] = hp.back();
            hp.pop_back();
            if(!hp.empty()) heapify(0);
            return val;
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
    obj.show();
    return 0;
}
