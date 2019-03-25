#ifndef List_hpp
#define List_hpp

#include <stdio.h>
#include "iostream"

template <class T>
struct CListNode{
    CListNode<T> *pNext;
    T data;

    CListNode(T data){
        this->data = data;
        this->pNext = nullptr;
    }
};

template <class T>
class CList{
private:
    CListNode<T> *head;
    int size;
    
public:
    CList();
    CList(const CList& other){
        head = nullptr;
        size = 0;
        for (int i=0; i<other.getSize(); i++){
            push_back(other[i]);
        }
    }

    ~CList();
    bool isEmpty() const;
    void show();
    void removeAt(int idx);
    void insert(T data, int idx);
    void clear();
    void pop_front();
    void pop_back();
    void push_front(T data);
    void push_back(T data);
    int getSize()const {return size;}
    T& operator[](int index);
    const T& operator[](int index) const;
};

template <class T>
CList<T>::CList(){
    size = 0;
    head = nullptr;
}

template <class T>
CList<T>::~CList(){
    clear();
}

template <class T>
bool CList<T>::isEmpty() const{
    return head == nullptr;
}


template <class T>
void CList<T>::push_back(T data){
    if (head == nullptr){
        head = new CListNode<T>(data);
    }
    else {
        CListNode<T> *current = this->head;
        
        while (current->pNext != nullptr){
            current = current->pNext;
        }
        current->pNext = new CListNode<T>(data);
    }
    size++;
}

template <class T>
void CList<T>::push_front(T data){
//    head = new CListNode<T>(data, head);
    CListNode<T> *newNode = new CListNode<T>(data);
    newNode->pNext = head;
    head = newNode;
    size++;
}


template <class T>
void CList<T>::pop_front(){
    CListNode<T> *temp = head;
    
    head = head->pNext;
    
    delete temp;
    size--;
}

template <class T>
void CList<T>::pop_back(){
    removeAt(size - 1);
}

template <class T>
void CList<T>::clear(){
    
    while (size){
        pop_front();
    }
}

template <class T>
T& CList<T>::operator[](int index){
    int cnt = 0;
    CListNode<T> *current = head;
    
    while (current != nullptr){
        if (cnt == index) return current->data;
        current = current->pNext;
        cnt++;
    }
    throw "Operator Error";
}

template <class T>
const T& CList<T>::operator[](int index) const {
    int cnt = 0;
    CListNode<T> *current = head;

    while (current != nullptr){
        if (cnt == index) return current->data;
        current = current->pNext;
        cnt++;
    }
    throw "Operator Error";
}

template <class T>
void CList<T>::insert(T data, int idx){
    if (idx == 0) push_front(data);
    else {
        CListNode<T> *prev = this->head;
        
        for (int i = 0; i < idx - 1; i++){
            prev = prev->pNext;
        }
        
        CListNode<T> *newNode = new CListNode<T>(data, prev->pNext);
        prev->pNext = newNode;
        size++;
    }
    
}


template <class T>
void CList<T>::removeAt(int idx){
    if (idx == 0) pop_front();
    else {
        CListNode<T> *prev = this->head;
        
        for (int i = 0; i < idx - 1; i++){
            prev = prev->pNext;
        }
        CListNode<T> *toDelete = prev->pNext;
        prev->pNext = toDelete->pNext;
        delete toDelete;
        size--;
    }
}

template <class T>
void CList<T>::show(){
    CListNode<T> *temp = head;
    for (int i = 0; i<size; i++){
        while (temp) {
            std::cout<<temp->data<<" ";
            temp = temp->pNext;
        }
        
    }
    std::cout<<std::endl;
}



#endif /* List_hpp */
