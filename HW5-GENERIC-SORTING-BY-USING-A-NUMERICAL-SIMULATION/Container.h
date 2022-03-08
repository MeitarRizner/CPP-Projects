#ifndef HW5_CONTAINER_H
#define HW5_CONTAINER_H

#include <iostream>
#include "Element.h"
using namespace std;

//I used the defaults 'the big three' except destructor.
template<typename T>
class Container {
public:
    Container(int n, int m, int numberOfElements);
    ~Container();
    void setVariableVects(T** arr);
    void setTargetVects(T** arr);
    Element<T>** getElemPool() const;
    T* getVariableVect(int vectNumber);
    int* ParetoRanking(T* targetVectors[], int numberOfVectors, int m);
    void ElementsReordering(Element<T>** arr, int numberOfElements);
    void ParetoSorting(Element<T>** arr, int numberOfElements);
private:
    Element<T>** ElemPool;
    int targetVectSize;
    int variableVectSize;
    int numberOfElements;
};

//Constructor - creates n elements
template<typename T>
Container<T>::Container(int n, int m, int numberOfElements) {
    this->targetVectSize = m;
    this->variableVectSize = n;
    this->numberOfElements = numberOfElements;
    this->ElemPool = new Element<T>*[this->numberOfElements];
    for (int i=0 ;i<this->numberOfElements; i++){
        this->ElemPool[i] = new Element<T>(n,m);
    }
}

//destructor - deletes the elements pool
template<typename T>
Container<T>::~Container() {
    for (int i=0 ;i<this->numberOfElements; i++){
        delete(this->ElemPool[i]);
    }
    delete(this->ElemPool);
}


//I assumed that T has a operator > (bigger than) , operator != (not equal)
//This function calculates the ranks of all the targets vectors
template<typename T>
int* Container<T>::ParetoRanking(T* targetVectors[], int numberOfVectors, int m) {
    int* ranks = new int [numberOfVectors];
    bool smallerExistFlag = false;
    bool allAreSmallEqual = true;
    for (int i=0; i<numberOfVectors; i++){
        ranks[i] = 0;
        for (int j=0; j<numberOfVectors; j++){
            if (i != j){
                for (int k=0; k<m; k++){
                    if (targetVectors[i][k] > targetVectors[j][k]){
                        smallerExistFlag = true;
                    }
                    else if (targetVectors[i][k] != targetVectors[j][k]){
                        allAreSmallEqual = false;
                        break;
                    }
                }
                if (allAreSmallEqual && smallerExistFlag){
                    ranks[i]++;
                }
                smallerExistFlag = false;
                allAreSmallEqual = true;
            }
        }
    }
    return ranks;
}

//This function reorders the elements by their ranks
template<typename T>
void Container<T>::ElementsReordering(Element<T>** arr, int numberOfElements) {
    int k;
    Element<T>* temp;
    for (int i = 0; i < numberOfElements - 1; i++) {
        k = i;
        for (int j = i + 1; j < numberOfElements; j++) {
            if (arr[j]->getRank() < arr[k]->getRank())
                k = j;
        }
        temp = arr[i];
        arr[i] = arr[k];
        arr[k] = temp;
    }
}

//This function calculates the ranks of all the targets vectors and reorders the elements by their ranks
template<typename T>
void Container<T>::ParetoSorting(Element<T> **arr, int numberOfElements) {
    T** targetVectors = new T*[numberOfElements];
    for (int i=0; i<numberOfElements; i++){
        targetVectors[i] = arr[i]->getTargetVect();
    }
    int* ranks = ParetoRanking(targetVectors,numberOfElements,this->targetVectSize);
    for (int i=0; i<numberOfElements; i++){
        arr[i]->setRank(ranks[i]);
    }
    ElementsReordering(arr,numberOfElements);
}

//This function sets the variables vectors for each element
template<typename T>
void Container<T>::setVariableVects(T **arr) {
    for (int i=0; i<this->numberOfElements; i++){
        this->ElemPool[i]->setVariableVect(arr[i]);
    }
}

//This function sets the targets vectors for each element
template<typename T>
void Container<T>::setTargetVects(T **arr) {
    for (int i=0; i<this->numberOfElements; i++){
        this->ElemPool[i]->setTargetVect(arr[i]);
    }
}

//This function returns the variables vectors of a element
template<typename T>
T* Container<T>::getVariableVect(int vectNumber) {
    for (int i=0; i<this->numberOfElements; i++){
        if (i == vectNumber)
            return this->ElemPool[i]->getVariableVec();
    }
    return NULL;
}

//This function returns array of elements
template<typename T>
Element<T> **Container<T>::getElemPool() const {
    return this->ElemPool;
}

#endif //HW5_CONTAINER_H
