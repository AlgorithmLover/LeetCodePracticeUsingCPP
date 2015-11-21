//
// Created by cheyulin on 11/21/15.
//
#include <string>
#include <vector>
#include <sstream>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) { }
};

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == nullptr)
            return vector<string>();
        if(root->left == nullptr && root->right == nullptr){
            vector<string> ret_vector;
            stringstream string_builder;
            string_builder.clear();
            string_builder << root->val;
            ret_vector.push_back(string_builder.str());
            return ret_vector;
        }

        vector<string> current_path;
        if(root->left != nullptr){
            vector<string> left_path = binaryTreePaths(root->left);
            for(string str: left_path){
                stringstream string_builder;
                string_builder.clear();
                string_builder << root->val <<"->"+str;
                current_path.push_back(string_builder.str());
            }
        }

        if(root->right!= nullptr){
            vector<string> right_path = binaryTreePaths(root->right);
            for(string str:right_path){
                stringstream string_builder;
                string_builder.clear();
                string_builder << root->val <<"->"+str;
                current_path.push_back(string_builder.str());
            }
        }
        return  current_path;
    }
};