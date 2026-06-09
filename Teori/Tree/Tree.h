#ifndef _Tree_H
#define _Tree_H

#include <iostream>
#include <fstream>

using namespace std;

struct TreeNode {
    string name;
    TreeNode* firstChild;
    TreeNode* nextSibling;
};

struct Tree {
    TreeNode* root;
};

TreeNode* createNode(string inputName);
TreeNode* findName(TreeNode* root, string targetName);
void addChild (TreeNode* root, string targetName, string childName);
void printTree(TreeNode* root, int depth);
void loadFile(TreeNode* &root , string File);

#endif