#include <iostream>
#include <vector>
using namespace std;
vector<int> selection(vector<int>&val){
    for (int i = 0; i < val.size() - 1; i++){
        int min_index = i;
        for (int j = i + 1; j < val.size(); j++){
            if(val[j]<val[min_index]){
                min_index = j;
            }

        }
        swap(val[i], val[min_index]);
    }
    return val;
}
int main(){
    vector <int> num= {64, 25, 12, 22, 11};
    for(int i:selection(num)){
        cout << i<<" ";
    }
    return 0;
}