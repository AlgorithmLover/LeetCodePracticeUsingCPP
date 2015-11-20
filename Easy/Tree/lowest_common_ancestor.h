//
// Created by cheyulin on 11/19/15.
//


#include <stack>
using namespace std;

enum NodeStatus{
    kNeedLeftExpand =0,
    kNeedRightExpand =1,
    kDone=2
};



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) { }
};

struct ComputeNodeInfo{
    ComputeNodeInfo(TreeNode* tree_node, NodeStatus node_status);
    TreeNode * tree_node;
    NodeStatus node_status;
    int contain_num;
};

class Solution{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q);
};
