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
    node<T>* root; //Root node of tree
    int count;     //Count of keys
    int mappedItemCount; //Count of mapped items

protected:
    void createMidpoints(vector<node<T>*>& list, int start, int end); //used in creating from file
    void destroySubRoot(node<T>*& subRoot); //used in the destructor
    int height(node<T>*& subRoot); //returns height attribute of a given node, or 0
    int getBalanced(node<T>* subRoot); //returns difference in height between left and right
    int leafCount(node<T>* subRoot); //Returns number of leaves
    node<T>* insertAssist(node<T>*& subRoot, node<T>*& newNode); //Finds location to add new node and returns newNode
    node<T>* insertItemAssist(node<T>*& subRoot, node<T>*& newNode);
    node<T>* delAssist(node<T>*& subRoot, T value); //Searches for a node based on a value and returns nullpointer
    node<T>* searchAssist(T val, node<T>* subRoot); //Searches for a value and returns its address
    void displaySystemAdmins(node<T>* subRoot);
    void displayOfficials(node<T>* subRoot);
    void displayMembers(node<T>* subRoot);      //all displays are in order traversal
    void displayViaHeight(node<T>* subRoot);
    void displayMappedItems(node<T>* subRoot);
    node<T>* delMappedItemAssist(node<T>*& subRoot, T value, T mappedItem);
    node<T>* rightmost(node<T>*& subRoot); //used in removing; from node to remove, left tree's largest value takes spot
    void rotations(node<T>*& subRoot); //will perform one of the 4 types of rotations if necessary
    node<T>* rotateRight(node<T>*& x); //Rotates the tree right and returns the new root node
    node<T>* rotateLeft(node<T>*& y); //Rotates the tree left and returns the new root node
    void saveAssist(node<T>* traversalNode, ofstream& outFile); //Takes a node to traverse the list and an output file to save all the data to
    node<T>* buildAssist(string entries); //

public:
    AVLTree();//Constructor
    ~AVLTree();//Destructor

    void insert(T value); //inserts the node
    void insertWithItem(T value, T mappedItem); //inserts a node with an item associated with the value. Like, phoneNum -> acct
    vector<T> returnMappedItems(T value); //returns a vector of the contents of that value's node
    void insertWithList(T value, vector<T> mappedItems); //replaces node at value's location and replaces it with a vector of items
    void search(T value); //Searches for a node with the value and prints each node
    void del(T value); //deletes node with specified value
    void delMappedItem(T value, T mappedItem); //deletes a specific item out of list in node. If nothing left after, deletes node.
    void display(int option = 5);     //int allows user to choose from the different display types
    bool isBalanced(); //returns true if tree is balanced
    int getLeaves();  //returns number of leaves
    int getHeight(); //returns height of tree
    int getCount(); //returns count of keys
    void saveInfo(string fileID); //Public function to save the AVL tree
    void buildTree(string fileID); //Creates tree based on text file
    void getStatistics(); //Prints statistics of tree
};
#endif
