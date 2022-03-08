#ifndef HW3_MAP_H
#define HW3_MAP_H

using namespace std;
#include <iostream>

template <typename Tkey, typename Tval >
class Map{
public:
    class Node {
    public:
        Tkey key;
        Tval value;
        Node* next;
    };
    Map();
    void insert(Tkey key, Tval val);
    Tval* findElement(Tkey key);
    void deleteElement(Tkey key);
    void destroyMap();
    void print();
    int getNumberOfElements();


private:
    Node* head;
    int numberOfElements;
    void setValue(Tkey key, Tval val);

};

template<typename Tkey, typename Tval>
Map<Tkey, Tval>::Map() : numberOfElements(0) {
    this->head = NULL;
}

template<typename Tkey, typename Tval>
void Map<Tkey, Tval>::insert(Tkey key, Tval val) {
    if (findElement(key) != NULL){
        setValue(key,val);
        return;
    }
    this->numberOfElements++;
    Node* new_node = new Node();
    new_node->key = key;
    new_node->value = val;
    new_node->next = NULL;
    if (head == NULL){
        head = new_node;
        return;
    }
    else if (head->key >= key) {
        new_node->next = head;
        head = new_node;
        return;
    }
    else {
        Node* current = head;
        while (current->next != NULL && current->next->key < key) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

template<typename Tkey, typename Tval>
Tval* Map<Tkey, Tval>::findElement(Tkey key) {
    Node* temp = head;
    while (temp != NULL){
        if (temp->key == key){
            return &temp->value;
        }
        temp = temp->next;
    }
    return NULL;
}

template<typename Tkey, typename Tval>
void Map<Tkey, Tval>::setValue(Tkey key, Tval val) {
    Node* temp = head;
    while (temp != NULL){
        if (temp->key == key){
            temp->value = val;
            return;
        }
        temp = temp->next;
    }
}

template<typename Tkey, typename Tval>
void Map<Tkey, Tval>::deleteElement(Tkey key) {
    this->numberOfElements--;
    Node* temp = head;
    Node* prev = NULL;
    if (temp != NULL && temp->key == key)
    {
        head = head->next;
        delete temp;
        return;
    }
    else
    {
        while (temp != NULL && temp->key != key)
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

template<typename Tkey, typename Tval>
void Map<Tkey, Tval>::destroyMap() {
    while (head != NULL){
        Node* temp = head->next;
        delete(head);
        head = temp;
    }
    this->numberOfElements = 0;
}

template<typename Tkey, typename Tval>
void Map<Tkey, Tval>::print() {
    Node* temp = head;
    while (temp != NULL){
        cout << temp->key << " " << temp->value << "\n";
        temp = temp->next;
    }
}

template<typename Tkey, typename Tval>
int Map<Tkey, Tval>::getNumberOfElements() {
    return this->numberOfElements;
}

#endif //HW3_MAP_H