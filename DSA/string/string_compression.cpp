#include <bits/stdc++.h>
using namespace std;
int comp(vector<char>&chars){
    int n = chars.size();
    int index=0;
    for (int i = 0; i < n;i++){
        int ch=chars[i];
        int key = 0;
        while (i < n && chars[i]==ch){
            key++;
            i++;
        }
        if(key==1){
            chars[index++] = ch;
        }else{
            chars[index++] = ch;
            string str = to_string(key);
            for(char dig:str){
                chars[index++] = dig;
            }
        }
        i--;
    }
    chars.resize(index);
    return index;

}
int main(){
    vector<char> ch = {'a', 'a', 'a', 'b', 'a', 'a'};
    cout<<comp(ch);
    return 0;
}