#include <iostream>
#include <string>
using namespace std;
struct Node {
    string title;         
    int pageCount;        
    Node* firstChild;     
    Node* nextSibling;    
};
Node* createNode(const string& title, int pageCount) {
    Node* newNode = new Node;
    newNode->title = title;
    newNode->pageCount = pageCount;
    newNode->firstChild = nullptr;
    newNode->nextSibling = nullptr;
    return newNode;
}
int countChapters(Node* root) {
    if (!root) return 0;
    int chapterCount = 0;
    Node* current = root->firstChild;
    while (current) {
        chapterCount++;
        current = current->nextSibling;
    }
    return chapterCount;
}
Node* findLongestChapter(Node* node, int& maxPages) {
    if (!node) return nullptr;
    Node* longestChapter = nullptr;
    if (node->pageCount > maxPages) {
        maxPages = node->pageCount;
        longestChapter = node;
    }
    Node* childLongest = findLongestChapter(node->firstChild, maxPages);
    if (childLongest && childLongest->pageCount > maxPages) {
        maxPages = childLongest->pageCount;
        longestChapter = childLongest;
    }
    Node* siblingLongest = findLongestChapter(node->nextSibling, maxPages);
    if (siblingLongest && siblingLongest->pageCount > maxPages) {
        maxPages = siblingLongest->pageCount;
        longestChapter = siblingLongest;
    }
    return longestChapter;
}
bool findAndDelete(Node* root, const string& targetTitle) {
    if (!root) return false;
    Node* parent = nullptr;
    Node* current = root->firstChild;
    while (current) {
        if (current->title == targetTitle) {
            if (parent) {
                parent->nextSibling = current->nextSibling;
            } else {
                root->firstChild = current->nextSibling;
            }
            delete current; 
            return true;
        }
        parent = current;
        current = current->nextSibling;
    }
    current = root->firstChild;
    while (current) {
        if (findAndDelete(current, targetTitle)) {
            return true;
        }
        current = current->nextSibling;
    }
    return false;
}
void printTree(Node* node, int level = 0) {
    if (!node) return;
    for (int i = 0; i < level; ++i) {
        cout << "  ";
    }
    cout << node->title << " (Pages: " << node->pageCount << ")\n";
    printTree(node->firstChild, level + 1);
    printTree(node->nextSibling, level);
}
void deleteTree(Node* root) {
    if (!root) return;
    deleteTree(root->firstChild);
    deleteTree(root->nextSibling);
    delete root;
}
