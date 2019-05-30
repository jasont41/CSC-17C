/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   tree_class.cpp
 * Author: Jason
 * 
 * Created on May 29, 2019, 6:46 PM
 */

#include "tree_class.h"
void tree_class::Sreachtree_node(int itemvalue, tree_node **l_pointer_1, tree_node **l_child_1)
 {
    tree_node *lpointer, *prsve;
    if (root_1 == NULL)
 {
        *l_child_1 = NULL;
        *l_pointer_1 = NULL;
        return;
    }
    if (itemvalue == root_1->ndoe_information)
 {
        *l_child_1 = root_1;
        *l_pointer_1 = NULL;
        return;
    }
    if (itemvalue < root_1->ndoe_information)
        lpointer = root_1->lettree_node1;
    else
        lpointer = root_1->righttree_node1;
    prsve = root_1;
    while (lpointer != NULL)
 {
        if (itemvalue == lpointer->ndoe_information)
 {
            *l_child_1 = lpointer;
            *l_pointer_1 = prsve;
            return;
        }
        prsve = lpointer;
        if (itemvalue < lpointer->ndoe_information)
            lpointer = lpointer->lettree_node1;
        else
            lpointer = lpointer->righttree_node1;
    }
    *l_child_1 = NULL;
    *l_pointer_1 = prsve;
}



//Define method

void tree_class::Inserttree_node(tree_node *treeval, tree_node *nwnde)
 {
    if (root_1 == NULL)
 {
        root_1 = new tree_node;
        root_1->ndoe_information = nwnde->ndoe_information;
        root_1->lettree_node1 = NULL;
        root_1->righttree_node1 = NULL;
        cout << "Root element is Added" << endl;
        return;
    }
    if (treeval->ndoe_information == nwnde->ndoe_information)
 {
        cout << "value present in treeval" << endl;
        return;
    }
    if (treeval->ndoe_information > nwnde->ndoe_information)
 {
        if (treeval->lettree_node1 != NULL)
 {
            Inserttree_node(treeval->lettree_node1, nwnde);
        }
        else
 {
            treeval->lettree_node1 = nwnde;
            (treeval->lettree_node1)->lettree_node1 = NULL;
            (treeval->lettree_node1)->righttree_node1 = NULL;
            cout << "tree_node is inserted To Left" << endl;
            return;
        }
    }
    else
 {
        if (treeval->righttree_node1 != NULL)
 {
            Inserttree_node(treeval->righttree_node1, nwnde);
        }
        else
 {
            treeval->righttree_node1 = nwnde;
            (treeval->righttree_node1)->lettree_node1 = NULL;
            (treeval->righttree_node1)->righttree_node1 = NULL;
            cout << "tree_node is inserted to Right" << endl;
            return;

        }
    }
}

//Define method

void tree_class::Delete_tree_node(int itemvalue)
 {
    tree_node *prnt, *lctn;
    if (root_1 == NULL)
 {
        cout << "empty value" << endl;
        return;
    }
    Sreachtree_node(itemvalue, &prnt, &lctn);
    if (lctn == NULL)
 {
        cout << "Item could not found " << endl;
        return;
    }

    if (lctn->lettree_node1 == NULL && lctn->righttree_node1 == NULL)
        CaseA(prnt, lctn);
    if (lctn->lettree_node1 != NULL && lctn->righttree_node1 == NULL)
        CaseB(prnt, lctn);
    if (lctn->lettree_node1 == NULL && lctn->righttree_node1 != NULL)
        CaseB(prnt, lctn);
    if (lctn->lettree_node1 != NULL && lctn->righttree_node1 != NULL)
        CaseC(prnt, lctn);
    free(lctn);
}



//Define method

void tree_class::CaseA(tree_node *l_pointer_1, tree_node *l_child_1)
 {
    if (l_pointer_1 == NULL)
 {
        root_1 = NULL;
    }
    else
 {
        if (l_child_1 == l_pointer_1->lettree_node1)
            l_pointer_1->lettree_node1 = NULL;
        else
            l_pointer_1->righttree_node1 = NULL;
    }

}



//Define method

void tree_class::CaseB(tree_node *l_pointer_1, tree_node *l_child_1)
 {
    tree_node *child;
    if (l_child_1->lettree_node1 != NULL)
        child = l_child_1->lettree_node1;
    else
        child = l_child_1->righttree_node1;
    if (l_pointer_1 == NULL)
 {
        root_1 = child;
    }
    else
 {
        if (l_child_1 == l_pointer_1->lettree_node1)
            l_pointer_1->lettree_node1 = child;
        else
            l_pointer_1->righttree_node1 = child;
    }
}

//Define method

void tree_class::CaseC(tree_node *l_pointer_1, tree_node *l_child_1)
 {
    tree_node *lpointer, *prsve, *sc1, *parsuc;
    prsve = l_child_1;
    lpointer = l_child_1->righttree_node1;
    while (lpointer->lettree_node1 != NULL)
 {
        prsve = lpointer;
        lpointer = lpointer->lettree_node1;
    }
    sc1 = lpointer;
    parsuc = prsve;
    if (sc1->lettree_node1 == NULL && sc1->righttree_node1 == NULL)
        CaseA(parsuc, sc1);
    else
        CaseB(parsuc, sc1);
    if (l_pointer_1 == NULL)
 {
        root_1 = sc1;
    }
    else
 {
        if (l_child_1 == l_pointer_1->lettree_node1)
            l_pointer_1->lettree_node1 = sc1;
        else
            l_pointer_1->righttree_node1 = sc1;
    }
    sc1->lettree_node1 = l_child_1->lettree_node1;
    sc1->righttree_node1 = l_child_1->righttree_node1;

}



//Define method

void tree_class::preordertraversal(tree_node *lpointer)
 {

    if (root_1 == NULL)
 {
        cout << "Empty treeval" << endl;
        return;
    }
    if (lpointer != NULL)
 {
        cout << lpointer->ndoe_information << " ";
        preordertraversal(lpointer->lettree_node1);
        preordertraversal(lpointer->righttree_node1);
    }
}
//Define method

void tree_class::inordertraversal(tree_node *lpointer)
 {
    if (root_1 == NULL)
 {
        cout << "empty" << endl;
        return;
    }
    if (lpointer != NULL)
 {
        inordertraversal(lpointer->lettree_node1);
        cout << lpointer->ndoe_information << " ";
        inordertraversal(lpointer->righttree_node1);
    }

}


void tree_class::postordertraversal(tree_node *lpointer)
 {
    if (root_1 == NULL){
        cout << "empty" << endl;
        return;
    }
    if (lpointer != NULL)
 {
        postordertraversal(lpointer->lettree_node1);
        postordertraversal(lpointer->righttree_node1);
        cout << lpointer->ndoe_information << " ";
    }
}



//Define method

void tree_class::Display(tree_node *lpointer, int lvl)
 {

    int li;
    if (lpointer != NULL)
 {
        Display(lpointer->righttree_node1, lvl + 1);
        cout << endl;
        if (lpointer == root_1)
            cout << "Root->: ";
        else
 {
            for (li = 0; li < lvl; li++)
                cout << "       ";
        }
        cout << lpointer->ndoe_information;
        Display(lpointer->lettree_node1, lvl + 1);
    }
}

