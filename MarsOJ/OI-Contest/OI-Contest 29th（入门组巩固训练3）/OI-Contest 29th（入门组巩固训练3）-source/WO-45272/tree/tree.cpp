#include <iostream>
#include <vector>
 
using namespace std;
 
int countSubTrees(const vector<int>& preorder, const vector<int>& postorder) {
    if (preorder.empty() || postorder.empty()) return 0;
 
    int rootValue = preorder[0];
    auto rootPostEnd = find(postorder.begin(), postorder.end(), rootValue);
    int leftSize = distance(postorder.begin(), rootPostEnd);
    int leftSubTrees = countSubTrees(vector<int>(preorder.begin() + 1, preorder.begin() + 1 + leftSize),
                                     vector<int>(postorder.begin(), rootPostEnd));
    int rightSubTrees = countSubTrees(vector<int>(preorder.begin() + 1 + leftSize, preorder.end()),
                                      vector<int>(rootPostEnd + 1, postorder.end() - 1));

    return (leftSubTrees + 1) * (rightSubTrees + 1);
}
 
int buildTree(vector<char>& in, vector<char>& pre, vector<char>& post, int inStart, int inEnd, int& postIndex) {
    if (inStart > inEnd) return -1;
    
    char currentValue = pre[0]; // 前序遍历的第一个节点是根节点
    int indexInInorder = inStart;
    while (in[indexInInorder] != currentValue) indexInInorder++;
    
    int numLeftNodes = indexInInorder - inStart;
    TreeNode* current = new TreeNode(currentValue);
    if (numLeftNodes > 0) {
        current->left = buildTree(in, vector<char>(pre.begin() + 1, pre.begin() + numLeftNodes + 1), 
                                  vector<char>(post.begin() + inStart, post.begin() + indexInInorder), 
                                  inStart, indexInInorder - 1, postIndex);
    }
    if (numLeftNodes < inEnd - inStart) {
        current->right = buildTree(in, vector<char>(pre.begin() + numLeftNodes + 1, pre.end()), 
                                   vector<char>(post.begin() + indexInInorder, post.end() - numLeftNodes), 
                                   indexInInorder + 1, inEnd, postIndex);
    }
    postIndex--;
    if (postIndex < 0) return -1; // Error: postorder does not match preorder
    return indexInInorder;
}

int main() {
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    vector<int> preorder;
    vector<int> postorder;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        preorder.push_back(x);
    }
    for (int i = 1; i <+ n; i++)
    {
        int x;
        cin >> x;
        postorder.push_back(x);
    }
    cout << countSubTrees(preorder, postorder) << endl;
    vector<char> inorder;
    int postIndex = postorder.size() - 1;
    TreeNode* root = buildTree(preorder, postorder, 0, postIndex, postIndex);
    inorderTraversal(root, inorder);
    
    for (char c : inorder) {
        cout << c << " ";
    return 0;
}