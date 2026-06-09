#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Tree.h"

using namespace std;


TreeNode* createNode(string inputName){
    TreeNode* New = new TreeNode;
    New->name = inputName;
    New->firstChild = nullptr;
    New->nextSibling = nullptr;
    return New;
};

TreeNode* findName(TreeNode* root, string targetName){
    if (root ==  nullptr) {
        return nullptr;
    };

    if (root->name == targetName) {
        return root;
    };

    TreeNode* Found = findName(root->firstChild, targetName);
    if (Found != nullptr){
        return Found;
    };

    return findName(root->nextSibling, targetName);
};


void addChild (TreeNode* root, string targetName, string childName){
    TreeNode *parent = findName(root, targetName);
    if (parent != nullptr){
        TreeNode *New = createNode(childName);

        if (parent->firstChild == nullptr){
            parent->firstChild = New;
        } else {
            TreeNode* temp = parent->firstChild;

            while(temp->nextSibling != nullptr){
                temp = temp->nextSibling;
            };
            temp->nextSibling = New;
        
        };

    } else {
        cout << "Error: Parent '" << targetName << "' tidak ditemukan di tree!\n";
    }
};

void printTree(TreeNode* root, int depth) {
    if (root == nullptr) return;

    for (int i = 0; i < depth; i++) {
        cout << "    "; 
    }
    
    cout << "|-- " << root->name << " (Generasi " << depth + 1 << ")\n";

    printTree(root->firstChild, depth + 1);
    printTree(root->nextSibling, depth);
}

void loadFile(TreeNode* &root , string File){
    ifstream file(File);

    if(!file.is_open()){
        cout << "File Tidak Ditemukan" << endl;
        return;
    };

    string line;
    while(getline(file, line)){
        string parentName, childName;
        stringstream ss(line);

        getline(ss, parentName, ',');
        getline(ss, childName);

        if (childName == "NULL"){
            root = createNode(parentName);
        }else{
            addChild(root, parentName, childName);
        };

    };

    file.close();
};