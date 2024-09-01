#include<iostream>
#include<array>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    
    Node(int in_data){
        data = in_data;
    }
};


class MyQueue{
    public:
        Node* PermHead;
    
        MyQueue(){
            PermHead->next = NULL;
        }
    
        void append(Node* t_node){
            Node* walker = PermHead;
            while(walker->next != NULL){
                walker = walker->next;
            }
            walker->next = t_node;
            t_node->next = NULL;
            
            std::cout << "added new node!" << std::endl;
        }
    
        void deQueue(){
            PermHead = PermHead->next;
        }
    
        void print(){
            Node* walker = PermHead;
            while(walker != NULL){
                cout << walker->data << endl;
                walker = walker->next;
            }
        }
};

int main(int argc, const char * argv[]) {
    MyQueue myGuy;
    Node* newDude = new Node(1);
    myGuy.append(newDude);
    
    Node* newerDude = new Node(5);
    myGuy.append(newerDude);
    
    Node* newestDude = new Node(13);
    myGuy.append(newestDude);
    
    myGuy.print();
    myGuy.deQueue();
    myGuy.print();
    
    return 0;
}
