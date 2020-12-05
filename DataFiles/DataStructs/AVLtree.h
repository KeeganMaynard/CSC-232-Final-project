#ifndef AVLTREE_H
#define AVLTREE_H
#include "Node.h"
#include "Encryption.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cmath>
using namespace std;

template <class T>
class AVLTree
{
private:
    node<T>* root;
    int count;
    int mappedItemCount;

protected:
    void createMidpoints(vector<node<T>*>& list, int start, int end); //used in creating from file
    void destroySubRoot(node<T>*& subRoot); //used in the destructor
    int height(node<T>*& subRoot); //returns height attribute of a given node, or 0
    int getBalanced(node<T>* subRoot); //whether node's subtrees are balanced
    int leafCount(node<T>* subRoot);
    node<T>* insertAssist(node<T>*& subRoot, node<T>*& newNode);
    node<T>* insertItemAssist(node<T>*& subRoot, node<T>*& newNode);
    node<T>* delAssist(node<T>*& subRoot, T value);
    node<T>* searchAssist(T val, node<T>* subRoot);
    void displaySystemAdmins(node<T>* subRoot);
    void displayOfficials(node<T>* subRoot);
    void displayMembers(node<T>* subRoot);      //all displays are in order traversal
    void displayViaHeight(node<T>* subRoot);
    void displayMappedItems(node<T>* subRoot);
    node<T>* delMappedItemAssist(node<T>*& subRoot, T value, T mappedItem);
    node<T>* rightmost(node<T>*& subRoot); //used in removing; from node to remove, left tree's largest value takes spot
    void rotations(node<T>*& subRoot); //will perform one of the 4 types of rotations if necessary
    node<T>* rotateRight(node<T>*& x); //returned node is new root of subtree
    node<T>* rotateLeft(node<T>*& y);
    void saveAssist(node<T>* traversalNode, ofstream& outFile);
    node<T>* buildAssist(string entries);

public:
    AVLTree();
    ~AVLTree();

    void insert(T value); //inserts the node
    void insertWithItem(T value, T mappedItem); //inserts a node with an item associated with the value. Like, phoneNum -> acct
    vector<T> returnMappedItems(T value);
    void insertWithList(T value, vector<T> mappedItems);
    void search(T value);
    void del(T value);
    void delMappedItem(T value, T mappedItem); //deletes a specific item out of list in node. If nothing left after, deletes node.
    void display(int option = 5);     //int allows user to choose from the different display types
    bool isBalanced();
    int getLeaves();
    int getHeight();
    int getCount();
    void saveInfo(string fileID);
    void buildTree(string fileID);
    void getStatistics();
};
#endif
