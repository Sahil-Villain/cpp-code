#include <bits/stdc++.h>
using namespace std; 
void swap(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
}
int sort(vector<int>val,int kth){
    for (int i = 0; i < val.size()-1;i++){
        for (int j = i + 1; j < val.size(); j++){  
            if(val[i]==val[j]){
                continue;
            }
            if(val[i]<val[j]){
                swap(val[i], val[j]);
            }
        }
    }
    return val[kth - 1];
}
int main()
{
    vector<int> num = {1, 2, 3, 4, 5, 6, 7}; 
    cout << sort(num,5 );
    return 0;
}