#ifndef AVLTREE_H
#define AVLTREE_H
#include "node.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cmath>
//#include "Encryption.h"
using namespace std;

template <class T>
class AVLTree
{
private:
	node<T>* root;
	int count;
	int mappedCount;
};
#endif