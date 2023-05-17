#include<vector>
#include<iostream>
#include<queue>
#define max 10000
typedef long long ll;
using namespace std;
struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int value){
        val =value;
        Node* left =NULL;
        Node* right=NULL;
    }
};
Node *change_postorder_to_levle(vector<int>&array,int start,int end){
    if(start>end)return 0;
    Node*root= new Node(array[end]);    
    int meo =root->val; 
    int i=0;
    for(i=end;i>=start;i--){
        if(meo>array[i])break;
    }
    root->right =change_postorder_to_levle(array,i+1,end-1);
    root->left =change_postorder_to_levle(array,start,i);
    return root;
}
void print_levelorder(Node*root){
    if(!root)return ;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        int len = q.size();
        for(int i=0;i<=len;i++){
            Node *now =q.front();
            q.pop();
            cout<<now->val<<" ";
            if(now->right){
                q.push(now->right);
            }
            if(now->left){
                q.push(now->left);
            }
        }
        cout <<endl;
    }
}



int main(){
    int num;
    cin >> num;
    vector <int> postorder(num);
    for(int i=0;i<num;i++)cin>>postorder.at(i);
    Node*root = change_postorder_to_levle(postorder,0,num-1);
    print_levelorder(root);
    return 0;
}