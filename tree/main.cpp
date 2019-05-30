#include <iostream>
#include <cstdlib>
#include "tree_class.h"
#include "tree_node.h"
using namespace std;



//main function
int main()
 {
    //declare the variable
    int option, number;
    tree_class bst;
    tree_node *tempvalue;
    while (1)
 {
        cout << "Tree options " << endl;
        cout << "1.Insert value " << endl;
        cout << "2.Delete value " << endl;
        cout << "3.Inorder value" << endl;
        cout << "4.Preorder value" << endl;
        cout << "5.Postorder value" << endl;
        cout << "6.Display" << endl;
        cout << "7.Quit" << endl;
        cout << "Enter your option : ";
        cin>>option;
        switch (option)
 {
            case 1:
                tree_node * root_1= new tree_node;
                cout << "Please Enter insert number: ";
                cin >> tempvalue->ndoe_information;
                bst.Inserttree_node(root_1, tempvalue);
            case 2:
                if (root_1 == NULL){
                    cout << "Empty treeval" << endl;
                    continue;
                }
                cout << "please Enter delete number : ";
                cin>>number;
                bst.Delete_tree_node(number);
                break;
            case 3:
                cout << "Inorder Traversal :" << endl;
                bst.inordertraversal(root_1);
                cout << endl;
                break;
            case 4:
                cout << "Preorder Traversal:" << endl;
                bst.preordertraversal(root_1);
                cout << endl;
                break;
            case 5:
                cout << "Postorder Traversal:" << endl;
                bst.postordertraversal(root_1);
                cout << endl;
                break;
            case 6:
                cout << "Display treeval:" << endl;
                bst.Display(root_1, 1);
                cout << endl;
                break;
            case 7:
                exit(1);
            default:
                cout << "Wrong option" << endl;
        }
    }
}

