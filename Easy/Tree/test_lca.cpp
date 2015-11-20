//
// Created by cheyulin on 11/19/15.
//
#include <iostream>
#include "lowest_common_ancestor.h"

int main(){
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
