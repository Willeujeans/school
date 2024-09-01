#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *left;
    Node *right;
    Node(int value){
        data = value;
        left = NULL;
        right = NULL;
    }
    void setLeft(Node* in_left){
        left = in_left;
    }
    void setRight(Node* in_right){
        right = in_right;
    }
    Node* getLeft(){
        return left;
    }
    Node* getRight(){
        return right;
    }
};

int main(int argc, const char * argv[]){
    Node root(0);
    Node first(1);
    Node second(2);
    root.setRight(&first);
    root.setLeft(&second);
    cout << root.getLeft()->data << endl;
    return 0;
}
