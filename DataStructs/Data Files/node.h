//Header file for nodes
#ifndef NODE_H
#define NODE_H
#include <vector>
using namespace std;

template <class T>
struct node
{
	T value;
	vector<T> list;
	node* left;
	node* right;

	//constructors
	node() {}
	node(T item);
	node(T item, T mapped);
	node(T item, vector<T> mapped);
};

template <class T>
node<T>::node(T item)
{
	value = item;
	left = nullptr;
	right = nullptr;
	list = {};
}

template <class T>
node<T>::node(T item, T mapped)
{
	value = item;
	left = nullptr;
	right = nullptr;
	list = { mapped };
}

template <class T>
node<T>::node(T item, vector<T>mapped)
{
	value = item;
	left = nullptr;
	right = nullptr;
	list = mapped;
}
#endif