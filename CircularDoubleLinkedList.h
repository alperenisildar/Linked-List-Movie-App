#ifndef CIRCULARDOUBLELINKEDLIST_H
#define CIRCULARDOUBLELINKEDLIST_H
#include <iostream>
#include "DoubleNode.h"
using namespace std;

template <class T> 
class CircularDoubleLinkedList
{
public:
	CircularDoubleLinkedList();
	~CircularDoubleLinkedList();

	DoubleNode<T> *getFirstNode() const;
	DoubleNode<T> *getLastNode() const;
	DoubleNode<T> *getNode(const T &data) const;
	int getNumberOfNodes() const;
	bool isEmpty() const;
	bool contains(DoubleNode<T> *DoubleNode) const;
	void insertAtTheHead(const T &data);
    void insertAtTheTail(const T &data);
    void removeNode(DoubleNode<T> *DoubleNode);
    void removeNode(const T &data);
	void removeFirst();
	
private:
	
	DoubleNode<T> *head;
	DoubleNode<T> *tail;
};

template<class T>
CircularDoubleLinkedList<T>::CircularDoubleLinkedList(){
	
	head = nullptr;
	tail = nullptr;	
}

template <class T>
CircularDoubleLinkedList<T>::~CircularDoubleLinkedList(){
	while(!isEmpty())
		removeFirst();
	delete head;
	head = nullptr;
	tail = nullptr;
}

template <class T>
DoubleNode<T> *CircularDoubleLinkedList<T>::getFirstNode() const{
	if(isEmpty())
		return nullptr;
	else
		return head;
}

template<class T>
DoubleNode<T> *CircularDoubleLinkedList<T>::getLastNode() const{
	if(isEmpty())
		return nullptr;
	else
		return tail;
}

template<class T>
DoubleNode<T> *CircularDoubleLinkedList<T>::getNode(const T &data) const{
	DoubleNode<T> *curr;
	if(isEmpty())
		return nullptr;
	curr = head;
	while(curr->next != head){
		if(curr -> data == data)
			return curr;
		curr = curr->next;
	}
	return nullptr;
}

template<class T>
int CircularDoubleLinkedList<T>::getNumberOfNodes() const{
	int k = 0;
	DoubleNode<T> *curr;
	curr = head;
	while(curr->next != head){
		k++;
		curr = curr->next;
	}
	return k;
}

template<class T>
bool CircularDoubleLinkedList<T>::isEmpty() const{
	if(head == nullptr)
		return true;
	return false;
}

template<class T>
bool CircularDoubleLinkedList<T>::contains(DoubleNode<T> *doubleNode) const{
	DoubleNode<T> *curr;
	curr = head;
	while(curr->next != head){
		if(curr == doubleNode)
			return true;
		curr = curr->next;
	}
	if(curr == doubleNode)
		return true;
	return false;
}

template<class T>
void CircularDoubleLinkedList<T>::insertAtTheHead(const T &data){
	if(head == nullptr){
		head = new DoubleNode<T>(data, tail, head);
		tail = head;
	}
	else{
		DoubleNode<T> *doubleNode = new DoubleNode<T>(data, tail, head);
		head = doubleNode;
		tail->next = head;
		head->prev = tail;
	}
}

template<class T>
void CircularDoubleLinkedList<T>::insertAtTheTail(const T &data){
	if(head == nullptr){
		head = new DoubleNode<T>(data, tail, head);
		tail = head;
		tail->next = head;
	}
	else{
		DoubleNode<T> *doubleNode = new DoubleNode<T>(data, tail, head);
		tail->next = doubleNode;
		tail = doubleNode;
		head->prev = tail;
	}
}

template<class T>
void CircularDoubleLinkedList<T>::removeNode(DoubleNode<T> *node){
	if(isEmpty() || !contains(node))
		return;
	DoubleNode<T> *curr;
	curr = head;
	while(curr != node){
		curr = curr->next;
	}
	if(curr == head)
		removeFirst();
	else if(curr == tail){
		tail = tail->prev;
		tail->next = head;
		head->prev = tail;
		delete curr;
	}
	else{
		curr->prev->next = curr->next;
		curr->next->prev = curr->prev;
		delete curr;
	}
}

template<class T>
void CircularDoubleLinkedList<T>::removeNode(const T &data){
	if(isEmpty())
		return;
	DoubleNode<T> *curr;
	curr = head;
	while(curr->next != head && curr->data != data)
		curr = curr->next;
	removeNode(curr);
}

template<class T>
void CircularDoubleLinkedList<T>::removeFirst(){
	
	if(isEmpty())
		return;
	DoubleNode<T> *curr;
	curr = head;
	if(curr==tail){
		delete head;
		head = nullptr;
		tail = nullptr;
		return;
	}
	head = curr->next;	
	tail->next = head;
	head->prev = tail;
	delete curr;
	curr = nullptr;
}

#endif // CIRCULARDOUBLELINKEDLIST_H
