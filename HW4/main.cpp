// Mohandass Kannan
// CS 315: HW 4

#include <iostream>
#include "TernaryTree.h"

using namespace std;

int main() {
    TernaryTree tree;
    int val;

    while (cin >> val) {
        tree.insert(val);
    }

    cin.clear();
    cin.ignore(10000, '\n');

    tree.print();

    cout << "Enter a value to search for: ";
    if (cin >> val) {
        if (tree.search(val)) {
            cout << "found" << endl;
        }
        else {
            cout << "not found" << endl;
        }
    }

    return 0;
}