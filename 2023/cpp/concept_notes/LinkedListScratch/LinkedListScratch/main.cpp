//
//  main.cpp
//  LinkedListScratch
//
//  Created by Will Schmitz on 9/29/23.
//

#include <iostream>

class Node {
  public:
    int data;
    Node* next;
    
    
    //constructors
    Node(){
        this->data = 0;
        this->next = NULL;
    }
    
    Node(int data){
        this->data = data;
    }
};

class List{
    public:
    Node* permHead;
    
    List(){
        permHead = NULL;
    }
    
    void prePendNode(Node* t_node){
        t_node->next = permHead;
        permHead = t_node;
    }
    
    
    void appendNode(Node* t_node){
        Node* walker = this->permHead;
        std::cout << walker->data << std::endl;
        while(walker->next != NULL){
            walker = walker->next;
            std::cout << walker->data << std::endl;
        }
        walker->next = t_node;
        t_node->next = NULL;
        
        std::cout << "added new node!" << std::endl;
    }
    
    void print(){
        std::cout << "PRINTING..." << std::endl;
        Node* walker = this->permHead;
        std::cout << walker->data << std::endl;
        while(walker->next != NULL){
            walker = walker->next;
            std::cout << walker->data << std::endl;
        }

        
        
    }
};

int main(int argc, const char * argv[]) {
    List myList;
    myList.permHead = new Node(1);
    myList.permHead->next = NULL;
    Node* guy = new Node(55);
    myList.appendNode(guy);
    Node* Anotherguy = new Node(700);
    myList.prePendNode(Anotherguy);
    myList.print();
}
