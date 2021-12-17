#ifndef DOUBLENODE_H
#define DOUBLENODE_H

template<class T>

class DoubleNode
{
public:

	T data;
	DoubleNode<T> *prev;
	DoubleNode<T> *next;
	DoubleNode();
	DoubleNode(T data, DoubleNode<T> *prev, DoubleNode<T> *next);
	
};

template<class T>
DoubleNode<T>::DoubleNode(){
	this->next = nullptr;
	this->prev = nullptr;
}

template<class T>
DoubleNode<T>::DoubleNode(T data,DoubleNode<T> *prev, DoubleNode<T> *next){
	this->data = data;
	this->next = next;
	this->prev = prev;
}


#endif // DOUBLENODE_H
