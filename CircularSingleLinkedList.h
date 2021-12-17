#ifndef CIRCULARSINGLELINKEDKIST_H
#define CIRCULARSINGLELINKEDKIST_H
#include <iostream>
#include "Node.h"
using namespace std;

template<class T>
class CircularSingleLinkedList
{
public:
	CircularSingleLinkedList();
	~CircularSingleLinkedList();

	Node<T> *getFirstNode() const;
	Node<T> *getLastNode() const;
	Node<T> *getNode(const T &data) const;
	int getNumberOfNodes() const;
	bool isEmpty() const;
	bool contains(Node<T> *node) const;
	void insertAtTheHead(const T &data);
    void insertAtTheTail(const T &data);
    void removeNode(Node<T> *node);
    void removeNode(const T &data);
	void removeFirst();
	
private:

	Node<T> *head;
	Node<T> *tail;
};

template<class T>
CircularSingleLinkedList<T>::CircularSingleLinkedList(){
	
	head = nullptr;
	tail = nullptr;	
}
template<class T>
CircularSingleLinkedList<T>::~CircularSingleLinkedList(){
	
	while(!isEmpty())
		removeFirst();
	delete head;
	head = nullptr;
	tail = nullptr;
}

template<class T>
Node<T> *CircularSingleLinkedList<T>::getFirstNode() const{
	if(isEmpty())
		return nullptr;
	else
		return head;
}

template<class T>
Node<T> *CircularSingleLinkedList<T>::getLastNode() const{
	if(isEmpty())
		return nullptr;
	else
		return tail;
}

template<class T>
Node<T> *CircularSingleLinkedList<T>::getNode(const T &data) const{
	Node<T> *curr;
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
int CircularSingleLinkedList<T>::getNumberOfNodes() const{
	int k = 1;
	Node<T> *curr;
	curr = head;
	if(isEmpty())
		return 0;
	while(curr->next != head){
		k++;
		curr = curr->next;
	}
	return k;
}

template<class T>
bool CircularSingleLinkedList<T>::isEmpty() const{
	if(head == nullptr)
		return true;
	return false;
}

template<class T>
bool CircularSingleLinkedList<T>::contains(Node<T> *node) const{
	Node<T> *curr;
	curr = head;
	
	while(curr->next != head){
		if(curr == node)
			return true;
		curr = curr->next;
	}
	if(curr == node)
		return true;
	return false;
}

template<class T>
void CircularSingleLinkedList<T>::insertAtTheHead(const T &data){
	if(head == nullptr){
		head = new Node<T>(data, head);
		tail = head;
	}
	else{
		Node<T> *node = new Node<T>(data, head);
		head = node;
		tail->next = head;
	}
}

template<class T>
void CircularSingleLinkedList<T>::insertAtTheTail(const T &data){
	if(head == nullptr){
		head = new Node<T>(data,head);
		tail = head;
		tail->next = head;
	}
	else{
		Node<T> *node = new Node<T>(data, head);
		tail->next = node;
		tail = node;
	}
}

template<class T>
void CircularSingleLinkedList<T>::removeNode(Node<T> *node){
	if(isEmpty() || !contains(node))
		return;
	Node<T> *curr;
	Node<T> *prev;
	prev = nullptr;
	curr = head;
	while(curr != node){
		prev = curr;
		curr = curr->next;
	}
	if(curr == head)
		removeFirst();
	else if(curr == tail){
		delete curr;
		tail = prev;
		tail->next = head;
	}
	else{
		prev->next = curr->next;
		delete curr;
	}
}

template<class T>
void CircularSingleLinkedList<T>::removeNode(const T &data){
	if(isEmpty())
		return;
	Node<T> *curr;
	curr = head;
	while(curr->next != head && curr->data != data)
		curr = curr->next;
	removeNode(curr);
}

template<class T>
void CircularSingleLinkedList<T>::removeFirst(){
	if(isEmpty())
		return;
	Node<T> *curr;
	curr = head;
	if(curr == tail){
		delete head;
		head = nullptr;
		tail = nullptr;
		return;
	}
	head = curr->next;	
	tail->next = curr->next;
	delete curr;
	curr = nullptr;
}

#endif // CIRCULARSINGLELINKEDKIST_H
