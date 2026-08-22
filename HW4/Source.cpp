// Mohandass Kannan
// CS 315: HW 4

#ifndef TERNARYTREE_H
#define TERNARYTREE_H

#include <iostream>
#include <algorithm>
#include <utility> 

using namespace std;

class Node {
public:
    bool is_two_valued;
    int val1, val2;
    Node* left;
    Node* middle;
    Node* right;

    Node(int v) {
        val1 = v;
        val2 = 0;
        is_two_valued = false;
        left = middle = right = nullptr;
    }

    void add_value(int v) {
        val2 = v;
        if (val1 > val2) {
            swap(val1, val2);
        }
        is_two_valued = true;
    }
};

class TernaryTree {
private:
    Node* root;

    void insert(Node*& n, int p) {
        if (n == nullptr) {
            n = new Node(p);
            return;
        }

        if (!n->is_two_valued) {
            n->add_value(p);
        }
        else {
            if (p <= n->val1) {
                insert(n->left, p);
            }
            else if (p > n->val1 && p <= n->val2) {
                insert(n->middle, p);
            }
            else {
                insert(n->right, p);
            }
        }
    }

    bool search(Node* n, int p) {
        if (n == nullptr) return false;

        if (!n->is_two_valued) {
            return n->val1 == p;
        }

        if (p == n->val1 || p == n->val2) return true;

        if (p <= n->val1) {
            return search(n->left, p);
        }
        else if (p > n->val1 && p <= n->val2) {
            return search(n->middle, p);
        }
        else {
            return search(n->right, p);
        }
    }

    void print(Node* n) {
        if (n == nullptr) return;

        if (!n->is_two_valued) {
            cout << n->val1;
        }
        else {
            if (n->left != nullptr) {
                cout << "(";
                print(n->left);
                cout << ") ";
            }

            cout << n->val1;

            if (n->middle != nullptr) {
                cout << " (";
                print(n->middle);
                cout << ") ";
            }
            else {
                cout << " ";
            }

            cout << n->val2;

            if (n->right != nullptr) {
                cout << " (";
                print(n->right);
                cout << ")";
            }
        }
    }

    void destroy(Node* n) {
        if (n) {
            destroy(n->left);
            destroy(n->middle);
            destroy(n->right);
            delete n;
        }
    }

public:
    TernaryTree() {
        root = nullptr;
    }

    ~TernaryTree() {
        destroy(root);
    }

    void insert(int p) {
        insert(root, p);
    }

    bool search(int p) {
        return search(root, p);
    }

    void print() {
        print(root);
        cout << endl;
    }
};

#endif