//
// Created by cheyulin on 11/21/15.
//


#include <iostream>
#include "binary_tree_path.h"

int main(){
    TreeNode treeNode1(1);
    TreeNode treeNode2(2);
    TreeNode treeNode3(3);
    treeNode1.left = &treeNode2;
    treeNode1.right = &treeNode3;
    TreeNode treeNode4(5);
    treeNode2.right = & treeNode4;

    Solution solution;
    vector<string> strings= solution.binaryTreePaths(&treeNode1);
    for(string str :strings){
        cout << str << endl;
    }
}