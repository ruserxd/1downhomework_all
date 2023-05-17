//Week03hw_01
#include <iostream>
#include <vector>
#include <queue>
typedef long long ll;
using namespace std;

// 定義樹的節點結構
struct TreeNode {
    int val;           // 該節點的數值
    TreeNode* left;    // 左子樹節點指標
    TreeNode* right;   // 右子樹節點指標
    TreeNode(int x){   // 構造函數，初始化節點數值，左右指標為 NULL
        val =x;
        left = NULL;
        right = NULL;
    }
};

// 以後序遍歷序列和邊界值構建二叉樹，返回樹的根節點指標
TreeNode* buildTree(vector<int>& postorder, int start, int end) {
    if (start > end) return NULL;   // 邊界值無效，返回 NULL
    // 將最後一個數字作為節點
    TreeNode* root = new TreeNode(postorder[end]);
    int ct;
    for (ct = end - 1; ct >= start; ct--) {   // 從後往前找到左右子樹的分界點
        if (postorder[ct] < root->val) {   // 如果找到了分界點
            break;
        }
    }
    // 遞迴構建左右子樹
    root->right = buildTree(postorder, ct + 1, end - 1);
    root->left = buildTree(postorder, start, ct);

    return root;    // 返回樹的根節點指標
}

// 按層序遍歷印出二叉樹的數值，節點間用空格隔開，每層換行
void printByLevel(TreeNode* root) {
    if (!root) {   // 如果樹為空，直接返回
        return;
    }

    queue<TreeNode*> q;   // 定義一個隊列，用於層序遍歷
    q.push(root);         // 先將根節點加入隊列

    while (!q.empty()) {  // 隊列不為空，繼續遍歷
        int n = q.size();
        for (int i = 0; i < n; i++) {    // 對該層的所有節點進行遍歷
            //3 , 1 ,4 ,2
            TreeNode* node = q.front();
            q.pop();
            //
            cout << node->val << (i == n - 1 ? "" : " ");   // 輸出節點數值，並根據位置決定是否加入空格
            if (node->left) {   // 如果有左子樹，將其加入隊列
                q.push(node->left);
            }
            if (node->right) {  //如果有右子樹，將其加入隊列
                q.push(node->right);
            }
        }
        cout<<endl;
    }
}
int main() {
    int num;
    cin >> num;

    vector<int> postorder(num);
    for (int i = 0; i < num; i++)  cin >> postorder.at(i);
    
    TreeNode* root = buildTree(postorder, 0, num - 1);

    printByLevel(root);

    return 0;
}
//end