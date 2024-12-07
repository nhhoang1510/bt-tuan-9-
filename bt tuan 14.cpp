#include <iostream>
#include <string>
using namespace std;


struct Node {
    string value;   
    Node* left;    
    Node* right;    

    Node(string v) : value(v), left(nullptr), right(nullptr) {}
};

class ExpressionTree {
public:
    Node* root;  
    ExpressionTree() : root(nullptr) {}
    bool isEmpty() {
        return root == nullptr;
    }
    void insert(Node* node) {
        if (root == nullptr) {
            root = node;
        }
    }
    void printInfix() {
        printInfixRec(root);
        cout << endl;
    }
    void printPrefix() {
        printPrefixRec(root);
        cout << endl;
    }
    void printPostfix() {
        printPostfixRec(root);
        cout << endl;
    }

private:
    void printInfixRec(Node* node) {
        if (node) {
            if (node->left) {
                cout << "(";
            }
            printInfixRec(node->left);
            cout << node->value;
            printInfixRec(node->right);
            if (node->right) {
                cout << ")";
            }
        }
    }
    void printPrefixRec(Node* node) {
        if (node) {
            cout << node->value << " ";
            printPrefixRec(node->left);
            printPrefixRec(node->right);
        }
    }
    void printPostfixRec(Node* node) {
        if (node) {
            printPostfixRec(node->left);
            printPostfixRec(node->right);
            cout << node->value << " ";
        }
    }
};
ExpressionTree parseExpression(const string& expr) {
    ExpressionTree tree;
    Node* node1 = new Node("a");
    Node* node2 = new Node("*");
    Node* node3 = new Node("5");
    Node* node4 = new Node("-");
    Node* node5 = new Node("b");
    Node* node6 = new Node("*");
    Node* node7 = new Node("c");
    Node* node8 = new Node("^");
    Node* node9 = new Node("6");
    Node* node10 = new Node("/");
    Node* node11 = new Node("d");
    Node* node12 = new Node("+");
    Node* node13 = new Node("(");
    Node* node14 = new Node("h");
    Node* node15 = new Node("-");
    Node* node16 = new Node("f");
    Node* node17 = new Node(")");
    Node* node18 = new Node("*");
    Node* node19 = new Node("e");
    Node* node20 = new Node("^");
    Node* node21 = new Node("1/2");
    node2->left = node1;
    node2->right = node3;
    node6->left = node7;
    node6->right = node8;
    node8->left = node9;
    node10->left = node6;
    node10->right = node11;
    node5->left = node6;
    node5->right = node10;
    node4->left = node2;
    node4->right = node5;
    node14->left = node13;
    node15->left = node14;
    node15->right = node16;
    node18->left = node15;
    node18->right = node20;
    node20->left = node19;
    node20->right = node21;

    tree.insert(node4);

    return tree;
}

int main() {
    string expr = "a*5-b*c^6/d+(h-f)*e^(1/2)";  

    ExpressionTree tree = parseExpression(expr);

    cout << "Infix expression: ";
    tree.printInfix();

    cout << "Prefix expression: ";
    tree.printPrefix();

    cout << "Postfix expression: ";
    tree.printPostfix();

    return 0;
}
