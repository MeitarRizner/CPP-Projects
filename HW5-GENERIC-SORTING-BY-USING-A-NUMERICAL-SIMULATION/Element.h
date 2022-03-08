#ifndef HW5_ELEMENT_H
#define HW5_ELEMENT_H

//I used the defaults 'the big three'.
template <typename T>
class Element {
public:
    Element(int n, int m);
    void setRank(int rank);
    int getRank() const;
    T* getTargetVect() const;
    T* getVariableVec() const;
    void setVariableVect(T* arr);
    void setTargetVect(T* arr);
private:
    T* variableVect;
    T* targetVect;
    int rank;
};

//Constructor - creates a element
template<typename T>
Element<T>::Element(int n, int m) {
    this->variableVect = new T[n];
    this->targetVect = new T[m];
    this->rank = 0;
}

template<typename T>
void Element<T>::setRank(int rank) {
    this->rank = rank;
}

template<typename T>
int Element<T>::getRank() const {
    return this->rank;
}

template<typename T>
T *Element<T>::getTargetVect() const {
    return this->targetVect;
}

template<typename T>
void Element<T>::setVariableVect(T *arr) {
    this->variableVect = arr;
}

template<typename T>
void Element<T>::setTargetVect(T *arr) {
    this->targetVect = arr;
}

template<typename T>
T *Element<T>::getVariableVec() const {
    return this->variableVect;
}


#endif //HW5_ELEMENT_H
