#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>;
using namespace std;

template <class T>
struct Node
{
	T value;
	Node<T>* prev;
	Node<T>* next;
};

template <class T>
class LinkedList
{
private:
	Node<T>* head;
	Node<T>* tail;
	int max;
	int currentItem;
public:
	LinkedList();
	~LinkedList();

	bool isFull();
	bool isEmpty();
	int size();
	void push(T value);	//add to the front
	void append(T value);	//add to the ed
	void remove(T value);
	bool search(T value);
	void clear();	//clear entire list
};

template <class T>
LinkedList<T>::LinkedList()
{
	head = nullptr;
	tail = nullptr;
	int max = -1;
	currentItem = 0;
}
#endif