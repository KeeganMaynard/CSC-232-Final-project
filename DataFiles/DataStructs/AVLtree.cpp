#include "AVLtree.h"
template <class T>
AVLTree<T>::AVLTree()
{
    root = nullptr;
    count = 0;
}

template <class T>
void AVLTree<T>::createMidpoints(vector<node<T>*>& nodeList, int start, int end)
{
    if (end - start >= 0) //once the distance between the upper and lower numbers is negative, we have done finding all midpoints
    {
        int midpoint = start + ((end - start) / 2); //this will round down

        root = insertAssist(root, nodeList[midpoint]);
        count++;

        //recursive calls to handle both sides of the original midpoint
        createMidpoints(nodeList, start, midpoint - 1); 
        createMidpoints(nodeList, midpoint + 1, end);
    }
}

template <class T>
void AVLTree<T>::destroySubRoot(node<T>*& subRoot)
{
    if (subRoot)
    {
        node<T>* leftNode = subRoot->left;
        node<T>* rightNode = subRoot->right;
        delete subRoot;

        if (leftNode) //if not nullptr
            destroySubRoot(leftNode);

        if (rightNode)//if not nullptr
            destroySubRoot(rightNode);
    }
}

template <class T>
AVLTree<T>::~AVLTree()
{
    destroySubRoot(root);
}

template <class T>
void AVLTree<T>::display(int option)
{
    if (count == 0)
    {
        cout << "No values available to display." << endl;
    }
    else
    {
        switch (option)
        {
        case 1:
        {
            displayMembers(root);
            break;
        }
        case 2:
        {
            displaySystemAdmins(root);
            break;
        }
        case 3:
        {
            displayOfficials(root);
            break;
        }
        case 4:
        {
            displayViaHeight(root);
            break;
        }
        case 5:
        {
            displayMappedItems(root);
            break;
        }
        }
    }
}

template <class T>
void AVLTree<T>::displayMembers(node<T>* subRoot)   //recursive function to display all bank members in the tree
{
    if (subRoot) //not nullptr
    {
        displayMembers(subRoot->left);
        if (subRoot->list[1] == "member")
        {
            cout << subRoot->value << endl;
        }
        displayMembers(subRoot->right);
    }
}

template <class T>
void AVLTree<T>::displaySystemAdmins(node<T>* subRoot)      //recursive function to display all system administrators in the tree
{
    if (subRoot)
    {
        displaySystemAdmins(subRoot->left);
        if (subRoot->list[1] == "admin")
        {
            cout << subRoot->value << endl;
        }
        displaySystemAdmins(subRoot->right);
    }
}

template <class T>
void AVLTree<T>::displayOfficials(node<T>* subRoot)     //recursive function to display all officials in the tree
{
    if (subRoot)
    {
        displayOfficials(subRoot->left);
        if (subRoot->list[1] == "official")
        {
            cout << subRoot->value << endl;
        }
        displayOfficials(subRoot->right);
    }
}

template <class T>
void AVLTree<T>::displayViaHeight(node<T>* subRoot)     //recursive function to dispaly the value of a node and the node height
{
    if (subRoot) //not nullptr
    {
        displayViaHeight(subRoot->left);
        cout << subRoot->value << " Height: " << subRoot->height << endl;
        displayViaHeight(subRoot->right);
    }
}

template <class T>
void AVLTree<T>::displayMappedItems(node<T>* subRoot)
{
    if (subRoot)
    {
        displayMappedItems(subRoot->left);
        cout << "Key: " << subRoot->value << endl << "Value: ";
        for (int i = 0; i < subRoot->list.size(); i++)
        {
            cout << subRoot->list[i];
            if (i + 1 < subRoot->list.size())
            {
                cout << " -- ";
            }
        }
        cout << endl;
        displayMappedItems(subRoot->right);
    }
}

template <class T>
int AVLTree<T>::height(node<T>*& subRoot)
{
    if (!subRoot)
    {
        return 0;
    }
    else
    {
        return subRoot->height;
    }
}

template <class T>
int AVLTree<T>::getBalanced(node<T>* subRoot)
{
    if (!subRoot)
    {
        return 0;
    }
    else
    {
        return height(subRoot->left) - height(subRoot->right);
    }
}

template <class T>
node<T>* AVLTree<T>::rotateRight(node<T>*& x)
{
    //node pointer locations               
    node<T>* lft = x->left;                      //lft is the left child of x        
    node<T>* sub = lft->right;                   //sub is the right child of lft        

    //performing rotation                                           
    lft->right = x;
    x->left = sub;

    //updating heights of nodes
    lft->height = max(height(lft->left), height(lft->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return lft; //the new root
}

template <class T>
node<T>* AVLTree<T>::rotateLeft(node<T>*& y)
{
    //node pointer locations
    node<T>* rght = y->right;                   //rght is the right child of y                                       
    node<T>* sub = rght->left;                  //sub is the left child of rght                    
      
    //performing rotation
    y->right = sub;
    rght->left = y;

    //updating heights of nodes
    y->height = max(height(y->left), height(y->right)) + 1;
    rght->height = max(height(rght->left), height(rght->right)) + 1;

    return rght; //the new root
}

template<class T>
node<T>* AVLTree<T>::insertAssist(node<T>*& subRoot, node<T>*& newNode)
{
    //inserting the newNode
    if (!subRoot)
    {
        mappedItemCount += newNode->list.size();
        return newNode;
    }
    else if (newNode->value < subRoot->value)
    {
        subRoot->left = insertAssist(subRoot->left, newNode);
    }
    else if (newNode->value > subRoot->value)
    {
        subRoot->right = insertAssist(subRoot->right, newNode);
    }
    else //equal values 
    {
        count--; //undo increment from insert function
        cout << "Invalid entry. Duplicates are not permitted." << endl;
    }

    //resetting the heights
    subRoot->height = max(height(subRoot->left), height(subRoot->right)) + 1;

    
    rotations(subRoot);

    return subRoot; //return the root 
}

template <class T>
void AVLTree<T>::insert(T value)
{
    node<T>* newNode = new node<T>(value);
    root = insertAssist(root, newNode); //inserts node into list
    count++;
}

template <class T>
node<T>* AVLTree<T>::insertItemAssist(node<T>*& subRoot, node<T>*& newNode)
{
    if (!subRoot)
    {
        return newNode;
    }
    else if (newNode->value < subRoot->value)
    {
        subRoot->left = insertItemAssist(subRoot->left, newNode);
    }
    else if (newNode->value > subRoot->value)
    {
        subRoot->right = insertItemAssist(subRoot->right, newNode);
    }
    else //equal values, so new mappedItem into list, if not there. If there, say that
    {
        bool newValue = true;
        for (int i = 0; i < subRoot->list.size(); i++)
        {
            if (newNode->list[0] == subRoot->list[i]) //newNode will only have the one value, subRoot could have multiple
            {
                cout << "Invalid entry. Duplicates are not permitted." << endl;
                newValue = false;
                break;
            }
        }
        if (newValue)
        {
            subRoot->list.push_back(newNode->list[0]);
            mappedItemCount++;
        }

        nodeCount--; //undo increment from insert function
    }

    //resetting the heights
    subRoot->height = max(height(subRoot->left), height(subRoot->right)) + 1;

    rotations(subRoot);

    return subRoot; //returning the root
}

template <class T>
void AVLTree<T>::insertWithItem(T value, T mappedItem)
{
    node<T>* newNode = new node<T>(value, mappedItem);
    root = insertItemAssist(root, newNode);
    count++;
}

template <class T>
bool AVLTree<T>::isBalanced()
{
    int balance = getBalanced(root);
    bool status = ((balance >= -1) && (balance <= 1)) ? true : false;
    return status;
}

template <class T>
void AVLTree<T>::del(T value)
{
    if (root)
    {
        root = delAssist(root, value);
        count--;
    }
}

template <class T>
node<T>* AVLTree<T>::rightmost(node<T>*& subRoot)
{
    while (subRoot->right)
    {
        subRoot = subRoot->right;
    }
    return subRoot;
}

template <class T>
node<T>* AVLTree<T>::delAssist(node<T>*& subRoot, T value)
{
    if (value < subRoot->value)
    {
        if (subRoot->left)
        {
            subRoot->left = delAssist(subRoot->left, value);
        }
        else
        {
            count++;
        }
    }
    else if (value > subRoot->value)
    {
        if (subRoot->right)
        {
            subRoot->right = delAssist(subRoot->right, value);
        }
        else
        {
            
            count++; //undo decrement in del function
        }
    }
    else  //the values are equal
    {
        mappedItemCount -= subRoot->list.size();
        

        if (subRoot->left && subRoot->right) //two children
        {
            node<T>* largestLeftNode = rightmost(subRoot->left); //finding max value in left subtree of del node
            subRoot->value = largestLeftNode->value; 
            subRoot->list = largestLeftNode->list; //deep copy of list
            mappedItemCount += largestLeftNode->list.size(); //if largestLeftNode is deleted, then undo decrement of mappedItems
            subRoot->left = delAssist(subRoot->left, largestLeftNode->value); 
        }

        else if (!subRoot->left && !subRoot->right) //is a leaf
        {
            delete subRoot;  //deallocating memory
            subRoot = nullptr; 
            return subRoot; //return back to previous function call
        }

        else  //only one child
        {
            node<T>* child = (subRoot->right) ? subRoot->right : subRoot->left; //makes child either left or right
            delete subRoot; //deallocating parent
            subRoot = child; //takes on child's value
        }
    }

    //resetting the heights
    subRoot->height = max(height(subRoot->left), height(subRoot->right)) + 1;

    //rotate if needed
    rotations(subRoot);

    return subRoot;
}

template <class T>
void AVLTree<T>::delMappedItem(T value, T mappedItem)
{
    root = delMappedItemAssist(root, value, mappedItem);
    count--;
}

template <class T>
node<T>* AVLTree<T>::delMappedItemAssist(node<T>*& subRoot, T value, T mappedItem)
{
    //This function is designed for if there is more than one item in node's list
    if (value < subRoot->value)
    {
        if (subRoot->left)
        {
            subRoot->left = delMappedItemAssist(subRoot->left, value, mappedItem);
        }
        else
        {
            count++;
        }
    }
    else if (value > subRoot->value)
    {
        if (subRoot->right)
        {
            subRoot->right = delMappedItemAssist(subRoot->right, value, mappedItem);
        }
        else
        {
            count++;
        }
    }
    else  //the values are equal
    {
        bool present = false;
        int index = -1;

        for (int i = 0; i < subRoot->list.size(); i++) //checking to see if the item is in the entry
        {
            if (mappedItem == subRoot->list[i])
            {
                present = true;
                index = i; //index of the mappedValue
                break;
            }
        }

        if (present)
        {
            if (subRoot->list.size() == 1) //only the mapped item is in the list
            {
                //The following lines are coppied from delAssist

                if (subRoot->left && subRoot->right) //two children present
                {
                    node<T>* largestLeftNode = rightmost(subRoot->left); //finding max value in left subtree of the node 
                    subRoot->value = largestLeftNode->value; 
                    subRoot->list = largestLeftNode->list; //deep copy of the list
                    subRoot->left = delMappedItemAssist(subRoot->left, largestLeftNode->value, mappedItem); //deleting the value
                }

                else if (!subRoot->left && !subRoot->right) //is a leaf
                {
                    delete subRoot;  //deallocating memory
                    subRoot = nullptr; 
                    return subRoot; //return back to previous function call
                }

                else  //only one child
                {
                    node<T>* child = (subRoot->right) ? subRoot->right : subRoot->left; //makes child either left or right
                    delete subRoot;
                    subRoot = child; //takes on child's value
                }

            }

            else //there is more than one entry in the list
            {
                subRoot->list.erase(subRoot->list.begin() + index); //finds the index of the mapped item and erases it 
                count++;
            }
            mappedItemCount--;
        }

        else
        {
            count++;
            cout << "No mapped item was found. Unable to delete." << endl;
        }

    }

    //resetting the height
    subRoot->height = max(height(subRoot->left), height(subRoot->right)) + 1;

    //rotate if needed
    rotations(subRoot);

    return subRoot;
}

template <class T>
void AVLTree<T>::rotations(node<T>*& subRoot)
{
    int balance = getBalanced(subRoot);
    int leftBal = getBalanced(subRoot->left);
    int rightBal = getBalanced(subRoot->right);

    if ((balance > 1) && (leftBal >= 0)) //Left heavy, one rotation
    {
        subRoot = rotateRight(subRoot);
    }
    else if ((balance > 1) && (leftBal < 0)) //Left heavy, double rotation
    {
        subRoot->left = rotateLeft(subRoot->left);
        subRoot = rotateRight(subRoot);
    }
    else if ((balance < -1) && (rightBal > 0)) //Right heavy, double rotation
    {
        subRoot->right = rotateRight(subRoot->right);
        subRoot = rotateLeft(subRoot);
    }
    else if ((bal < -1) && (rightBal <= 0)) //Right heavy, one
    {
        subRoot = rotateLeft(subRoot);
    }
}

template <class T>
vector<T> AVLTree<T>::returnMappedItems(T value)
{
    node<T>* nodePtr = searchAssist(value, root);
    if (nodePtr)
    {
        return nodePtr->list;
    }
    else
    {
        vector<T> value = {};
        return value; 
    }
}

template <class T>
void AVLTree<T>::insertWithList(T value, vector<T> mappedItems)
{
    del(value); //delete old node
    node<T>* newNode = new node<T>(value, mappedItems); //create node to replace
    root = insertAssist(root, newNode); //insert the node
    count++;
}

template <class T>
void AVLTree<T>::search(T value)
{
    node<T>* nodePtr = searchAssist(value, root);
    if (nodePtr)
    {
        for (int i = 0; i < nodePtr->list.size(); i++)
        {
            cout << nodePtr->list[i] << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "Unable to find that entry in records." << endl;
    }
}

template <class T>
node<T>* AVLTree<T>::searchAssist(T val, node<T>* subRoot)      //recursive function to help search for value
{
    if (subRoot)
    {
        if (val < subRoot->value)
        {
            return searchAssist(val, subRoot->left);
        }
        else if (val > subRoot->value)
        {
            return searchAssist(val, subRoot->right);
        }
        else
        {
            return subRoot;
        }
    }
    else
    {
        return nullptr;     //if the value is not found
    }
}

template <class T>
void AVLTree<T>::saveAssist(node<T>* traversalNode, ofstream& outFile)      //function to help save the info to files
{
    if (traversalNode)
    {
        saveAssist(traversalNode->left, outFile);
        string output = traversalNode->value + "%#";        //this will need to be changed
        for (int i = 0; i < traversalNode->list.size(); i++)
        {
            output += traversalNode->list[i];
            if (i < traversalNode->list.size() - 1)
            {
                output += "%&";
            }
        }
        outFile << EncryptionBox::encrypt(output) << endl;
        saveAssist(traversalNode->right, outFile);
    }
}

template <class T>
void AVLTree<T>::saveInfo(string fileID)
{
    EncryptionBox::positionInFile = 0;
    ofstream outFile;
    outFile.open(fileID);
    if (outFile)
    {
        node<T>* traversalNode = root;
        saveAssist(traversalNode, outFile); //prints to .txt file
    }
    else
    {
        cout << fileID << " could not be saved at this time." << endl;
    }
    outFile.close();
}

template <class T>
void AVLTree<T>::buildTree(string fileID)       //building the tree from a text file, will need to be edited
{
    EncryptionBox::positionInFile = 0;
    ifstream inFile(fileID);
    if (inFile)
    {
        //destroy tree before building new one
        count = 0;
        mappedItemCount = 0;
        destroySubRoot(root);

        string text = "";
        vector<node<T>*> nodes = {};

        while (getline(inFile, text))
        {
            string keyDelim = "%#";
            string entryDelim = "%&";

            text = text.substr(0, text.rfind("\r")); //getting rid of carriage return at the end from .txt file
            text = EncryptionBox::decrypt(text); //decrypting text to further parse and store inside the tree
            string key = text.substr(0, text.find(keyDelim));
            text = text.substr(key.length() + keyDelim.length(), string::npos);

            vector<string> entries = {};
            string entry = "";
            int pos1 = -entryDelim.length();
            int pos2 = 0;

            while (pos2 != string::npos) //while not reached end of string
            {
                //essentially, pos1 and pos2 move thru the string to get each entry out
                pos2 = text.find(entryDelim, pos1 + entryDelim.length());
                entry = text.substr(pos1 + entryDelim.length(), pos2 - pos1 - entryDelim.length());
                pos1 = pos2;
                entries.push_back(entry);
            }

            //vector entries is now ready to be inserted along with the key into the tree!
            node<T>* toBeInserted = new node<T>(key, entries); 
            nodes.push_back(toBeInserted);
        }

        createMidpoints(nodes, 0, nodes.size() - 1);
    }
    else
    {
        cout << fileID << " could not be accessed at this time." << endl;
    }
}

template <class T>
int AVLTree<T>::leafCount(node<T>* subRoot)
{
    if (!subRoot) //if nullptr
    {
        return 0;
    }
    else if (!subRoot->left && !subRoot->right) //if node is a leaf
    {
        return 1;
    }
    else
    {
        return leafCount(subRoot->left) + leafCount(subRoot->right); //recursively add returned values to calculate number of leaf nodes 
    }
}

template <class T>
int AVLTree<T>::getLeaves()
{
    return leafCount(root);
}

template <class T>
int AVLTree<T>::getHeight()
{
    node<T>* size = root; //includes all members for height 
    return height(size);
}

template <class T>
int AVLTree<T>::getCount()
{
    return count;
}

template <class T>
void AVLTree<T>::getStatistics()        //might not need this function
{
    unsigned int minHeight = log2(2 * count);
    cout << endl;
    cout << "Total keys stored: " << count << endl;
    cout << "Total items mapped to keys: " << mappedItemCount << endl;
    cout << "Height of tree: " << getHeight() << endl;
    cout << "Theoretical minimum height: " << minHeight << endl;
    cout << "Total leaf count: " << getLeaves() << endl;
}