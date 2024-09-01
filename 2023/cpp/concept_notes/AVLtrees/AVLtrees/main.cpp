//
//  main.cpp
//  AVLtrees
//
//  Created by Will Schmitz on 10/31/23.
//

#include <iostream>
#include <string>
#define COUNT 10
using namespace std;
//BINARY TREE, every parent can have up to two children
//  Node Structure {data,left,right}
//BINARY SEARCH TREE, every left child is less than parent, right child is greater than parent
//  Insert(), Search(), remove()
//AVL TREE, the tree must maintain balance no more than 1
//  Right rotation(), left rotation(), getBalance()


class node{
public:
    int data;
    node* parent;
    node* left;
    node* right;
    node(int in_data){
        parent = NULL;
        data = in_data;
    }
    void insert(node* in_node){
        cout << data << " Called: Inserting(" << in_node->data << ")" << endl;
        if(in_node->data < data){
            if(left != NULL){ //If theres a node there
                left->insert(in_node);
            }else{
                left = in_node;
                in_node->parent = this;
            }
        }else{
            if(right != NULL){ //If theres a node there
                right->insert(in_node);
            }else{
                right = in_node;
                in_node->parent = this;
            }
        }
    }
    
    node* search(int key){
        cout << data << " called search(" << key << ")" << endl;
        if(data == key){
            cout << "found(" << data <<")"<< endl;
            return this;
        }
        //left
        if(data > key){
            cout << data << " < " << key << endl;
            if(left != NULL){
                return left->search(key);
            }
            return NULL;
        //right
        }else{
            if(right != NULL){
                return right->search(key);
            }
            return NULL;
        }
    }
    node* findMin(){
        cout << "findingMin for: " << data << endl;
        if(left == NULL){
            cout << "MIN IS: " << data << endl;
            return this;
        }else{
            return left->findMin();
        }
    }
    void remove(int key){
        node* nodeToDelete = search(key);
        nodeToDelete->data = 100;
        int childrenCount = 0;
        bool isLeft = true;
        bool hasLeftChild = false;
        bool hasRightChild = false;
        if(nodeToDelete->data < nodeToDelete->parent->data){
            isLeft = true;
            cout << "Node(" << nodeToDelete->data << ") is left of its parent" << endl;
        }else{
            isLeft = false;
            cout << "Node(" << nodeToDelete->data << ") is left of its parent" << endl;
        }
        //Has a left child
        if(nodeToDelete->left != NULL){
            hasLeftChild = true;
            childrenCount++;
        }
        //Has a right child
        if(nodeToDelete->right != NULL){
            hasRightChild = true;
            childrenCount++;
        }
        
        //Checking for the three cases
        if(childrenCount == 2){
            cout << "TWO CHILDREN" << endl;
            node* replacmentNode = nodeToDelete->right->findMin();
            replacmentNode->parent->left = NULL;
            replacmentNode->left = nodeToDelete->left;
            replacmentNode->right = nodeToDelete->right;
            if(isLeft){
                nodeToDelete->parent->left = replacmentNode;
            }else{
                nodeToDelete->parent->right = replacmentNode;
            }

        }else if(childrenCount == 1){
            cout << "ONE CHILD" << endl;
            if(hasLeftChild){
                cout << "has a left child" << endl;
                if(isLeft){
                    nodeToDelete->parent->left = nodeToDelete->left;
                    nodeToDelete->left = NULL;
                }else{
                    nodeToDelete->parent->right = nodeToDelete->left;
                    nodeToDelete->left = NULL;
                }
            }else if(hasRightChild){
                cout << "has a right child" << endl;
                if(isLeft){
                    nodeToDelete->parent->left = nodeToDelete->right;
                    nodeToDelete->right = NULL;
                }else{
                    nodeToDelete->parent->right = nodeToDelete->right;
                    nodeToDelete->right = NULL;
                }
            }
        }else{
            cout << "NO CHILDREN";
            if(isLeft){
                nodeToDelete->parent->left = NULL;
                cout << "Node(" << nodeToDelete->data << ") is left of its parent" << endl;
            }else{
                nodeToDelete->parent->right = NULL;
                cout << "Node(" << nodeToDelete->data << ") is left of its parent" << endl;
            }
        }
    }
};

int height(node* in_node) {
   int h = 0;
   if (in_node != NULL) {
      int l_height = height(in_node->left);
      int r_height = height(in_node->right);
      int max_height = max(l_height, r_height);
      h = max_height + 1;
   }
   return h;
}
int difference(node* in_node) {
   int l_height = height(in_node->left);
   int r_height = height(in_node->right);
   int b_factor = l_height - r_height;
   return b_factor;
}

void print2DUtil(node* root, int space){
    // Base case
    if (root == NULL)
        return;
 
    // Increase distance between levels
    space += COUNT;
 
    // Process right child first
    print2DUtil(root->right, space);
 
    // Print current node after space
    // count
    cout << endl;
    for (int i = COUNT; i < space; i++)
        cout << " ";
    cout << root->data << "<" << "\n";
 
    // Process left child
    print2DUtil(root->left, space);
}
 
// Wrapper over print2DUtil()
void print2D(node* root){
    // Pass initial space count as 0
    print2DUtil(root, 0);
}


int main(int argc, const char * argv[]) {
    node* myRoot = new node(6);
    node* nodeOne = new node(2);
    node* nodeTwo = new node(14);
    node* nodeThree = new node(5);
    node* nodeFour = new node(4);
    node* nodeFive = new node(2);
    node* nodeSix = new node(6);
    myRoot->insert(nodeOne);
    myRoot->insert(nodeTwo);
    myRoot->insert(nodeThree);
    myRoot->insert(nodeFour);
    myRoot->insert(nodeFive);
    myRoot->insert(nodeSix);
    print2DUtil(myRoot, 0);
    if(height(myRoot) >= 2){
        cout << "UNBALANCED" <<endl;
    }

    return 0;
}
