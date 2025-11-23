/*
Driver code for testing your AVL Tree
This is NOT the test code for grading,
instead for you to get an idea of how to test the tree
 */
#include "AVLTree.h"
#include <iostream>
#include <string>
#include <ranges>
#include <vector>
using namespace std;


int main() {
     AVLTree tree;
     bool insertResult;
     insertResult = tree.insert("F", 'L');
    insertResult = tree.insert("B", 'B');
    insertResult = tree.insert("A", 'C');
    insertResult = tree.insert("E", 'D');
    insertResult = tree.insert("T", 'E');
    insertResult = tree.insert("Z", 'E');
    insertResult = tree.insert("J", 'L');



    cout << tree["F"] << endl;

    AVLTree treeCopy(tree);
    cout << treeCopy.size() << endl;
    cout << tree.size() << endl;

    AVLTree tree1 = tree;
    cout << tree1.size() << endl;

    cout << insertResult << endl;
     insertResult = tree.insert("F", 'F'); // false, no duplicates allowed
    cout << insertResult << endl;
 insertResult = tree.insert("B", 'D'); // false, no duplicates allowed
    insertResult = tree.insert("T", 'F'); // false, no duplicates allowed
    insertResult = tree.insert("z", 'F'); // false, no duplicates allowed


    // insertResult = tree.insert("K", 'K');
    //cout << insertResult << endl;
 // contains
         bool containsResult;
    containsResult = tree.contains("F"); // true
 cout << containsResult << endl;
   // containsResult = tree.contains("Z"); // false
 //cout << containsResult << endl;
    cout<< tree.size()<< endl;
 //get
    optional<int> getResult;
//
   getResult = tree.get("F"); // 65
    cout << "F: " << getResult.value() << endl;
//

 std::vector<std::string> keysInTree = tree.keys();
for (const auto& key : keysInTree) {
        std::cout << key << endl;
    }

     //insertResult = tree.insert("X", 'X');// single rotate left
    // cout << endl << endl;
    // cout << tree << endl;
    //
    // insertResult = tree.insert("C", 'C');
    // insertResult = tree.insert("A", 'A'); // single rotate right
    // cout << endl << endl;
    // cout << tree << endl;
    //
    // insertResult = tree.insert("D", 'D'); // double rotate right
    // cout << endl << endl;
    // cout << tree << endl;
    //
    // insertResult = tree.insert("R", 'R'); // double rotate left
    // cout << endl << endl;
    // cout << tree << endl;
    //
    // insertResult = tree.insert("V", 'V');
    // insertResult = tree.insert("A", 'A'); // false, duplicate
    // insertResult = tree.insert("Z", 'Z');
    // insertResult = tree.insert("M", 'M');
    // insertResult = tree.insert("D", 'D'); // false, duplicate
    // cout << endl << endl;
    // cout << tree << endl;
    //
    // // size and getHeight
    // cout << "tree size: " << tree.size() << endl; // 10
    // cout << "tree height: " << tree.getHeight() << endl; // 3
    // cout << endl;
//
//    // contains
//    bool containsResult;
//    containsResult = tree.contains("A"); // true
//    containsResult = tree.contains("N"); // false
//
//    // get
//    optional<int> getResult;
//
//    getResult = tree.get("A"); // 65
//    cout << "A: " << getResult.value() << endl;
//
//    getResult = tree.get("C"); // 67
//    cout << "C: " << getResult.value() << endl;
//
//    getResult = tree.get("Q"); // getResult has no value
//    cout << "Q: " << getResult.has_value() << endl; // print 0
//    cout << endl;
//
    // findRange
//    vector<int> rangeTest = tree.findRange("D", "W");
//    // 70 68 82 75 77 86
//    for (auto val: rangeTest) {
//        cout << val << " ";
//    }
//    cout << endl << endl;
//
//    // operator[]
//    tree["A"] = 108;
//    cout << tree << endl;
//    cout << endl;
//
//    // remove
//    bool removeResult;
//    removeResult= tree.remove("A"); // "A" is a leaf
//    cout << endl << endl;
//    cout << tree << endl;
//
//    removeResult = tree.remove("C"); // "C" has one child, single rotate left
//    cout << endl << endl;
//    cout << tree << endl;
//
//    removeResult = tree.remove("F"); // "F" has two children
//    cout << endl << endl;
//    cout << tree << endl;
//
//    removeResult = tree.remove("V");
//    removeResult = tree.remove("X");
//    removeResult = tree.remove("Z"); // double rotate right
//    cout << endl << endl;
//    cout << tree << endl;

    cout<< "Hello World" << endl;

    return 0;
}