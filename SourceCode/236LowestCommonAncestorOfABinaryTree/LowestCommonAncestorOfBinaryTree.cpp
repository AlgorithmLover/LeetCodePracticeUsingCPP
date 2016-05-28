//
// Created by cheyulin on 11/19/15.
//

#include "../my_header.h"
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
    ComputeNodeInfo(TreeNode *tree_node, NodeStatus node_status): tree_node(tree_node), node_status(node_status){
        contain_num = 0;
    }

    TreeNode * tree_node;
    NodeStatus node_status;
    int contain_num;
};
class Solution{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        stack<ComputeNodeInfo> post_order_stack;
        ComputeNodeInfo computeNodeInfo_first(root,kNeedLeftExpand);

        post_order_stack.push(computeNodeInfo_first);

        while(!post_order_stack.empty()){
            ComputeNodeInfo* current_node = &post_order_stack.top();
            switch (current_node->node_status){
                case kNeedLeftExpand:
                {
                    TreeNode * left_child_node;
                    left_child_node = current_node->tree_node->left;
                    NodeStatus nodeStatus;
                    if(left_child_node == nullptr)
                        nodeStatus = kDone;
                    else
                        nodeStatus = kNeedLeftExpand;
                    ComputeNodeInfo computeNodeInfo = ComputeNodeInfo(left_child_node,nodeStatus);
                    if(current_node->tree_node == p || current_node->tree_node ==q){
                        current_node->contain_num =1;
                    }

                    post_order_stack.push(computeNodeInfo);
                    current_node->node_status = kNeedRightExpand;
                    break;
                }

                case kNeedRightExpand:
                {
                    TreeNode * right_child_node;
                    right_child_node = current_node->tree_node->right;
                    NodeStatus nodeStatus;
                    if(right_child_node == nullptr)
                        nodeStatus = kDone;
                    else
                        nodeStatus = kNeedLeftExpand;
                    ComputeNodeInfo computeNodeInfo = ComputeNodeInfo(right_child_node,nodeStatus);

                    post_order_stack.push(computeNodeInfo);
                    current_node->node_status = kDone;
                    break;
                }

                case kDone:
                    if(current_node->contain_num ==2 && current_node->tree_node!= nullptr)
                        return current_node->tree_node;
                    else{
                        int contain_num_now = current_node->contain_num;
                        post_order_stack.pop();
                        post_order_stack.top().contain_num+=contain_num_now;

                    }
                    break;
                default:
                    break;
            }
        }

        return root;
    }
};


int test(){
    TreeNode tree_node_0(3);
    TreeNode tree_node_1(5);
    TreeNode tree_node_2(1);
    tree_node_0.left = & tree_node_1;
    tree_node_0.right = & tree_node_2;
    TreeNode tree_node_3(6);
    TreeNode tree_node_4(2);
    tree_node_1.left = & tree_node_3;
    tree_node_1.right = & tree_node_4;
    TreeNode tree_node_5(7);
    TreeNode tree_node_6(4);
    tree_node_4.left = & tree_node_5;
    tree_node_4.right = & tree_node_6;

    TreeNode tree_node_7(0);
    TreeNode tree_node_8(8);
    tree_node_2.left = &tree_node_7;
    tree_node_2.right =& tree_node_8;

    Solution solution;
    cout<<solution.lowestCommonAncestor(&tree_node_0, &tree_node_0, &tree_node_1)->val;
}

int main(){
    test();
}
