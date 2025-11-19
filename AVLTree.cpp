#include "AVLTree.h"

#include <string>

bool AVLTree::insert(const std::string& key, size_t value) {
    return insertRecursive(root, key, value);
}
bool AVLTree::remove(const std::string& key){}
bool AVLTree::contains(const std::string& key) const{}
std::optional<size_t> AVLTree::get(const std::string& key) const {}
size_t& AVLTree::operator[](const std::string& key){}
vector<std::string> AVLTree::findRange( const std::string& lowKey, const std::string& highKey) const{}
std::vector<std::string> AVLTree::keys() const{}
size_t AVLTree::size() const{}
size_t AVLTree::getHeight() const{}
AVLTree::AVLTree(const AVLTree& other){}
void AVLTree::operator=(const AVLTree& other){}
AVLTree::~AVLTree() {}
AVLTree::AVLTree(): root(nullptr) {}

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

bool AVLTree::searchRecursive(string& key, AVLNode* current ){
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

bool AVLTree::insertRecursive (AVLNode*& current, const string& key, size_t value) {
    // Base case. If node not found in tree insert it
    if (current == nullptr) {
       current = new AVLNode(key, value);
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
