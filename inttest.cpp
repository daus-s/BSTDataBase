#include "BST.h"
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char** argv)
{
    cout << "creating tree" << endl;
    BST<int>* tree = new BST<int>();

    tree->insert(5);
    cout << "insert 5" << endl;

    tree->insert(8);
    cout << "insert 8" << endl;

    tree->insert(2);
    cout << "insert 2" << endl;

    tree->insert(10);
    cout << "insert 10" << endl;

    tree->insert(9);
    cout << "insert 9" << endl;

    tree->insert(6);
    cout << "insert 6" << endl;

    tree->insert(7);
    cout << "insert 7" << endl;

    tree->insert(0);
    cout << "insert 0" << endl;

    tree->insert(1);
    cout << "insert 1" << endl;

    tree->insert(3);
    cout << "insert 3" << endl;

    tree->insert(4);
    cout << "insert 4" << endl;

    if ((tree->search(12))==NULL)
    {
        cout << "NULL" << endl;
    }
    else cout << tree->search(12)->print() << endl;

    cout << tree->print(tree->head) << endl;

    cout << tree->search(8) << endl;

    cout << tree->remove(11) << endl;
    tree->remove(8);

    cout << tree->print(tree->head) << endl;

    return 0;
}
