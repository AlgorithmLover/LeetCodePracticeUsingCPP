//
// Created by cheyulin on 12/29/15.
//
#include "../my_header.h"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) { }
};

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode *root) {
        if (root == nullptr)
            return vector<string>();
        if (root->left == nullptr && root->right == nullptr) {
            vector<string> ret_vector;
            stringstream string_builder;
            string_builder.clear();
            string_builder << root->val;
            ret_vector.push_back(string_builder.str());
            return ret_vector;
        }

        vector<string> current_path;
        if (root->left != nullptr) {
            vector<string> left_path = binaryTreePaths(root->left);
            for (string str: left_path) {
                stringstream string_builder;
                string_builder.clear();
                string_builder << root->val << "->" + str;
                current_path.push_back(string_builder.str());
            }
        }

        if (root->right != nullptr) {
            vector<string> right_path = binaryTreePaths(root->right);
            for (string str:right_path) {
                stringstream string_builder;
                string_builder.clear();
                string_builder << root->val << "->" + str;
                current_path.push_back(string_builder.str());
            }
        }
        return current_path;
    }
};

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
