#ifndef HW3_LINKEDLIST_H
#define HW3_LINKEDLIST_H
using namespace std;
#include <iostream>

//This class is a generic linked list, without using STL
template <typename T>
class LinkedList {
public:
    class Node {
    public:
        T data;
        Node* next;
    };
    Node* head;

    LinkedList(){
        this->head = NULL;
    }

    LinkedList(Node* lst){
        this->head = lst;
    }

    void insert(T x){
        Node* new_node = new Node();
        new_node->data = x;
        new_node->next = (head);
        head = new_node;
    }

    T getData(int i){
        LinkedList<T>* temp = new LinkedList<T>(this->head);
        int counter = 0;
        while (counter < i){
            temp->head = temp->head->next;
            counter++;
        }
        T val = temp->head->data;
        delete(temp);
        return val;
    }

    void Delete(T element){
        Node* temp = head;
        Node* prev = NULL;
        if (temp != NULL && temp->data == element)
        {
            head = head->next;
            delete temp;
            return;
        }
        else
        {
            while (temp != NULL && temp->data != element)
            {
                prev = temp;
                temp = temp->next;
            }
            if (temp == NULL)
                return;
            prev->next = temp->next;
            delete temp;
        }
    }

    void destroyList(){
        while (head != NULL){
            Node* temp = head->next;
            delete(head);
            head = temp;
        }
    }
private:

};
#endif //HW3_LINKEDLIST_H
