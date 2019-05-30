/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   tree_class.h
 * Author: Jason
 *
 * Created on May 29, 2019, 6:46 PM
 */

#ifndef TREE_CLASS_H
#define TREE_CLASS_H
#include "tree_node.h"
#include <cstdlib>
#include <iostream>
using namespace std; 
class tree_class {
public:
    treevalclass()
    {
        root_1 = NULL;
    }
    void Sreachtree_node(int, tree_node **, tree_node **);
    void Inserttree_node(tree_node*, tree_node*);
    void Delete_tree_node(int);
    void CaseA(tree_node *, tree_node *);
    void CaseB(tree_node *, tree_node *);
    void CaseC(tree_node *, tree_node *);
    void preordertraversal(tree_node *);
    void inordertraversal(tree_node *);
    void postordertraversal(tree_node *);
    void Display(tree_node *, int);
private:
tree_node *root_1;
};

#endif /* TREE_CLASS_H */

