#include "AVLTree.h"

#include <string>

//----------------------------------------------------------------
// Caleb Wilson
//    AVLTree Project 5
//
//      Project Description : Making a AVL TRee acting as a map
//          that stores key-value pairs. We are able to perform
//          operations on tree as well.
//----------------------------------------------------------------

//----------------------------------------------------------------
// insert: inserts a key-value pair into the AVL tree
//    Returns:  true if insertion successful, false if key already exists
//    Parameters:
//       key (const std::string&) - the key to insert
//       value (size_t) - the value associated with the key
//----------------------------------------------------------------
bool AVLTree::insert(const std::string& key, size_t value) {
    return insertRecursive(root, key, value);
}


bool AVLTree::remove(const std::string& key) {
}

//----------------------------------------------------------------
// contains: checks if a key exists in the AVL tree
//    Returns:  true if key exists, false otherwise
//    Parameters:
//       key (const std::string&) - the key to search for
//----------------------------------------------------------------
//can just return the result of searchRecursive since it is a bool as well.
bool AVLTree::contains(const std::string& key) const {
    return searchRecursive(key, root);
}

//----------------------------------------------------------------
// get: retrieves the value associated with a key
//    Returns:  optional containing the value if found, nullopt otherwise
//    Parameters:
//       key (const std::string&) - the key to search for
//----------------------------------------------------------------
std::optional<size_t> AVLTree::get(const std::string& key) const {
    return getRecursive(key, root);
}

//----------------------------------------------------------------
// operator[]: accesses the value associated with a key
//    Returns:  reference to the value associated with the key
//    Parameters:
//       key (const std::string&) - the key to access
//----------------------------------------------------------------
size_t& AVLTree::operator[](const std::string& key) {
    return operatorBracketRecursive(key, root);
}

//----------------------------------------------------------------
//       Not sure how to do this without changing the return type
//       as doc said to copy method stubs exactly?
//       but return size_t vector
//----------------------------------------------------------------
vector<std::string> AVLTree::findRange( const std::string& lowKey, const std::string& highKey) const {
}

//----------------------------------------------------------------
// keys: returns all keys currently in the tree
//    Returns:  vector of all keys in sorted order
//    Parameters: none
//----------------------------------------------------------------
std::vector<std::string> AVLTree::keys() const {
    std::vector<string> result;
    keysRecursive(root, result);
    return result;
}

//----------------------------------------------------------------
// size: returns the number of key-value pairs in the tree
//    Returns:  number of nodes in the tree (size_t)
//    Parameters: none
//----------------------------------------------------------------
size_t AVLTree::size() const {
    return treeSz;
}

//----------------------------------------------------------------
// getHeight: returns the height of the AVL tree
//    Returns:  height of the tree (size_t)
//    Parameters: none
//----------------------------------------------------------------
size_t AVLTree::getHeight() const {
    return root->height;
}

//----------------------------------------------------------------
// AVLTree: copy constructor - creates a deep copy of another tree
//    Returns:  none (constructor)
//    Parameters:
//       other (const AVLTree&) - the tree to copy
//----------------------------------------------------------------
AVLTree::AVLTree(const AVLTree& other) {
    root = nullptr;
    treeSz = 0;

    root = copyConRecursive(other.root);
    treeSz = other.treeSz;

}

//----------------------------------------------------------------
// operator=: assignment operator - assigns one tree to another
//    Returns:  none (void)
//    Parameters:
//       other (const AVLTree&) - the tree to copy from
//----------------------------------------------------------------
void AVLTree::operator=(const AVLTree& other) {
    deleteNodes(root);
    root = nullptr;
    treeSz = 0;

    root = copyConRecursive(other.root);
    treeSz = other.treeSz;
}

//----------------------------------------------------------------
// ~AVLTree: destructor - cleans up tree resources
//    Returns:  none (destructor)
//    Parameters: none
//----------------------------------------------------------------
AVLTree::~AVLTree() {}

//----------------------------------------------------------------
// AVLTree: default constructor - creates an empty tree
//    Returns:  none (constructor)
//    Parameters: none
//----------------------------------------------------------------
AVLTree::AVLTree(): root(nullptr), treeSz(0) {}

//----------------------------------------------------------------
// operator<<: outputs the tree to an output stream
//    Returns:  reference to the output stream
//    Parameters:
//       os (ostream&) - the output stream
//       avlTree (const AVLTree&) - the tree to output
//----------------------------------------------------------------
 std::ostream& operator<<(ostream& os, const AVLTree & avlTree) {
    return os;
}


size_t AVLTree::AVLNode::numChildren() const {
    return 0;
}


bool AVLTree::AVLNode::isLeaf() const {
    return false;
}

size_t AVLTree::AVLNode::getHeight() const {
    return 0;
}


bool AVLTree::removeNode(AVLNode*& current){
    if (!current) {
        return false;
    }

    AVLNode* toDelete = current;
    auto nChildren = current->numChildren();
    if (current->isLeaf()) {
        // case 1 we can delete the node
        current = nullptr;
    } else if (current->numChildren() == 1) {
        // case 2 - replace current with its only child
        if (current->right) {
            current = current->right;
        } else {
            current = current->left;
        }
    } else {
        // case 3 - we have two children,
        // get smallest key in right subtree by
        // getting right child and go left until left is null
        AVLNode* smallestInRight = current->right;
        // I could check if smallestInRight is null,
        // but it shouldn't be since the node has two children
        while (smallestInRight->left) {
            smallestInRight = smallestInRight->left;
        }
        std::string newKey = smallestInRight->key;
        int newValue = smallestInRight->value;
        remove(root, smallestInRight->key); // delete this one

        current->key = newKey;
        current->value = newValue;

        current->height = current->getHeight();
        balanceNode(current);

        return true; // we already deleted the one we needed to so return
    }
    delete toDelete;

    return true;
}


bool AVLTree::remove(AVLNode *&current, KeyType key) {
    return false;

}


void AVLTree::balanceNode(AVLNode *&node) {
}

//----------------------------------------------------------------
// searchRecursive: recursive helper to search for a key
//    Returns:  true if key found, false otherwise
//    Parameters:
//       key (const string&) - the key to search for
//       current (AVLNode*) - pointer to current node
//----------------------------------------------------------------
bool AVLTree::searchRecursive(const string& key, AVLNode* current ) const{
    //base case
    if (current == nullptr) return false;

    //exit case
    else if (key == current->key) return true;

    //traversing tree, go left then call
    if (key < current-> key) {
            return searchRecursive(key, current->left);

    }
    //go right then call
    if (key > current->key) {
        return searchRecursive(key, current->right);
    }
}

//----------------------------------------------------------------
// insertRecursive: recursive helper to insert a key-value pair
//    Returns:  true if insertion successful, false if duplicate
//    Parameters:
//       current (AVLNode*&) - reference to pointer to current node
//       key (const string&) - the key to insert
//       value (size_t) - the value to insert
//----------------------------------------------------------------
bool AVLTree::insertRecursive (AVLNode*& current, const string& key, size_t value) {
    // Base case. If node not found in tree insert it
    if (current == nullptr) {
       current = new AVLNode(key, value);
        treeSz++;// Want to add to the size of the tree when we insert a node
        return true;
    }

    //If key is in tree returns false
    if (key == current -> key) {
        return false;
    }

    // Go left. Traversing tree
    if (key < current ->key) {
        return insertRecursive(current->left, key, value);
    }

    // Go Right
    if (key > current ->key) {
       return insertRecursive(current->right, key, value);
    }
}

//----------------------------------------------------------------
// getRecursive: recursive helper to retrieve a value by key
//    Returns:  optional containing value if found, nullopt otherwise
//    Parameters:
//       key (const string&) - the key to search for
//       current (AVLNode*) - pointer to current node
//----------------------------------------------------------------
std::optional<size_t> AVLTree::getRecursive(const string& key, AVLNode* current) const {

    //if not in tree just return a null value
    if (current == nullptr) {
            return std::nullopt;
        }

    //if key is found in the tree, then return the value
    if (key == current->key) {
        return current->value;
    }

    // Go left
    if (key < current->key) {
        return getRecursive(key, current->left);
    }

    // Go right
    if (key > current->key) {
        return getRecursive(key, current->right);
    }
}

//----------------------------------------------------------------
// keysRecursive: recursive helper to collect all keys in order
//    Returns:  none (void)
//    Parameters:
//       current (AVLNode*) - pointer to current node
//       result (std::vector<string>&) - vector to store keys
//----------------------------------------------------------------
void AVLTree::keysRecursive(AVLNode* current, std::vector<string>& result) const{

    //base case
    if (current == nullptr) {
        return;
    }

    //inorder traversal
    keysRecursive(current->left, result);
    result.push_back(current->key);
    keysRecursive(current->right, result);
}

//----------------------------------------------------------------
// operatorBracketRecursive: recursive helper for operator[]
//    Returns:  reference to value associated with key
//    Parameters:
//       key (const string&) - the key to access
//       current (AVLNode*) - pointer to current node
//----------------------------------------------------------------
size_t& AVLTree::operatorBracketRecursive(const string& key, AVLNode* current) {


    //If the key is found return the value of the key
    if (key == current->key) {
        return current->value;
    }

    // Go left
    if (key < current->key) {
        return operatorBracketRecursive(key, current->left);
    }

    //Go Right
    if (key > current->key) {
        return operatorBracketRecursive(key, current->right);
    }
}

//----------------------------------------------------------------
// copyConRecursive: recursive helper to deep copy a tree
//    Returns:  pointer to root of copied subtree
//    Parameters:
//       node (AVLNode*) - pointer to node to copy
//----------------------------------------------------------------
AVLTree::AVLNode* AVLTree::copyConRecursive(AVLNode* node) {

    //base case
    if (node == nullptr) {
        return nullptr;
    }

    // New node created
    AVLNode* newNode = new AVLNode(node->key, node->value);

    // Use recursion to copy the tree
    newNode->left = copyConRecursive(node->left);
    newNode->right = copyConRecursive(node->right);

    return newNode;
}

//----------------------------------------------------------------
// deleteNodes: recursive helper to delete all nodes in a tree
//    Returns:  none (void)
//    Parameters:
//       node (AVLNode*) - pointer to node to delete
//----------------------------------------------------------------
void AVLTree::deleteNodes(AVLNode* node) {
    //Base case
    if (node == nullptr) {
        return;
    }

    // Must delete the children first so they don't get left in memory
    deleteNodes(node->left);
    deleteNodes(node->right);
    //then delete parent
    delete node;
}

