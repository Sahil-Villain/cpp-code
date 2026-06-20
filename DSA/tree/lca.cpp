#include <bits/stdc++.h>
using namespace std;
class Tree{
    int data;
    Tree*left;
    Tree*right;
    public:
        Tree(int val){
            data=val;
            left=right=nullptr;
        }
        Tree* buildtree(vector<int>&pre){
            Tree*root=new Tree(pre[0]);
            queue<Tree*>q;
            q.push(root);
            int i=1;
            while(q.size()>0&&i<pre.size()){
                Tree*curr=q.front();
                q.pop();
                if(i<pre.size()&&pre[i]!=-1){
                    curr->left=new Tree(pre[i]);
                    q.push(curr->left);
                }
                i++;
                if(i<pre.size()&&pre[i]!=-1){
                    curr->right=new Tree(pre[i]);
                    q.push(curr->right);
                }
                i++;
            }
            return root;
        }
        void print(Tree*root){
            if(root==nullptr){
                return ;
            }
            cout<<root->data;
            print(root->left);
            print(root->right);
        }
        Tree*lca(Tree*root,int n1,int n2){
            if(!root){
                return nullptr;
            }
            if(root->data==n1 || root->data==n2){
                return root;
            }
            Tree *lt = lca(root->left, n1, n2);
            Tree *rt = lca(root->right, n1, n2);
            if(lt&&rt){
                return root;
            }
            return lt ? lt : rt;
        }
        int getdata(){
            return data;
        }
};
int main(){
    vector<int>v={1,2,3,-1,4,-1,5};
    Tree obj(v[0]);
    Tree*root=obj.buildtree(v);
    Tree *ans = obj.lca(root, 2, 4);
    if (ans)
        cout << ans->getdata();
    else
        cout << "LCA not found";

    return 0;
}