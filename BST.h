#ifndef BSTNode_H
#define BSTNode_H

#include <iostream>
#include <string>
using namespace std;

template <class Element> class BSTNode
{
    public:
        Element data;
        BSTNode* left;
        BSTNode* right;

        BSTNode<Element>();
        BSTNode<Element>(Element e);
        string print();
};

template<class Element>
BSTNode<Element>::BSTNode()
{
    data = NULL;
    left = nullptr;
    right = nullptr;
}

template<class Element>
BSTNode<Element>::BSTNode(Element e)
{
    data = e;
    left = nullptr;
    right = nullptr;
}

template<class Element> string
BSTNode<Element>::print()
{
    return "" + data;
}

#endif























#ifndef BST_H
#define BST_H

#include <iostream>
#include <string>
using namespace std;

template<class Element> class BST
{
    public:
        BSTNode<Element>* head;
        bool search(Element e);
        void insert(Element e);
        bool remove(Element e);
        BSTNode<Element>* getSuccessor(BSTNode<Element>* node);
        string print(BSTNode<Element>* node);
        BST();
};

template<class Element> BSTNode<Element>* BST<Element>::getSuccessor(BSTNode<Element>* node)
{
    BSTNode<Element>* current = node->left;
    BSTNode<Element>* parent = node;
    BSTNode<Element>* successor = node;

    while (current != NULL)
    {
        parent = successor;
        successor = current;
        current = current->right;
    }

    parent->right = successor->left;

    return successor;
}

template<class Element> bool BST<Element>::search(Element e)
{
    if (head->data==e)
        return true;

    BSTNode<Element>* current = head;

    while (current->data!=e)
    {
        if (current==NULL)
            return false;
        if (current->data<e)
            current = current->right;
        if (current->data>e)
          current = current->left;
    }
    return true;
}

template<class Element> void BST<Element>::insert(Element e)
{
    //cout << e << endl;
    if (head == NULL)
    {
        head = new BSTNode<Element>(e);
        return;
    }

    BSTNode<Element>* current = head;

    //cout << (bool)(current!=NULL) << endl;
    while (current!=NULL)
    {
        // cout << "left " << (bool)(current->data>e) << endl;
        // cout << "right " << (bool)(current->data<e) << endl;

        if (current->data<e)
        {
            if (current->right!=NULL)
                current = current->right;
            else
            {
                current->right = new BSTNode<Element>(e);
                return;
            }
        }
        if (current->data>e)
        {
            if (current->left!=NULL)
                current = current->left;
            else
            {
                current->left = new BSTNode<Element>(e);
                return;
            }
        }
    }
    current = new BSTNode<Element>(e);
}

template<class Element> bool BST<Element>::remove(Element e)
{

    BSTNode<Element>* parent = head;
    BSTNode<Element>* current = head;
    bool left = true;

    cout << e << ":" << endl;
    cout << (head==NULL) << endl;
    if (head==NULL)
        return false;

    while (current->data!=e)
    {
        cout << "equal " << (current->data!=e) << endl;

        cout << "   NULL " << (current==NULL) << endl;
        if (current==NULL)
        {
            return false;
        }

        cout << "   right " << (current->data<e) << endl;
        if (current->data<e)
        {
            current = current->right;
            left = false;
        }

        cout << "   left " << (current->data>e) << endl;
        if (current->data>e)
        {
            current = current->left;
            left = true;
        }
        parent = current;
    }

    cout << "   equal " << (current->data!=e) << endl << endl;
    //best case scenario
    cout << "no children " << (current->left==NULL && current->right==NULL) << endl;
    if (current->left==NULL && current->right==NULL)
    {
        cout << "head " << (current==head) << endl;
        if(current==head)
            head==NULL; //now empty list
        cout << "left" << (left) << endl;
        if (left)
            parent->left == NULL;
        cout << "right" << (!left) << endl;
        if (!left)
            parent->right == NULL;
    }
    //else the parent has a children, at least so we will take case where there is 1 children
    cout << "no right children " << (current->right==NULL) << endl;
    if (current->right==NULL)
    {
        cout << "head " << (current==head) << endl;
        if(current==head)
            head = current->left;
        cout << "left " << (left) << endl;
        if (left)
            parent->left = current->left;
            //derivation: current must be left by checking left bool var
            //.: the new current must remain the child of the parent so
            //the only option we have to replace is the left of the current
        cout << "right " << (!left) << endl;
        if (!left)
            parent->right = current->left;
            //and vice versa,
    }
    cout << "no left children " << (current->right==NULL) << endl;
    if (current->left==NULL)
    {
        cout << "head " << (current==head) << endl;
        if(current==head)
            head = current->right;
        cout << "left " << (left) << endl;
        if (left)
            parent->left = current->right;
            //derivation: current must be left by checking left bool var
            //.: the new current must remain the child of the parent so
            //the only option we have to replace is the right of the current
        cout << "right " << (right) << endl;
        if (!left)
            parent->right = current->right;
            //and vice versa,
    }

    else //current has zwei childrenen, hahaha its in german @rene.
    {
        cout << getSuccessor(current)->data << endl;
        BSTNode<Element>* successor = getSuccessor(current);
        current = successor;
        if (left)
            parent->left=successor;
        if (!left)
            parent->right=successor;
    }

    return true;

    //next current node needs to be attached to the parent so we exit when one of the children is equal ot the searching vlaue
    //shortcut for get getSuccessor

}

template<class Element> BST<Element>::BST()
{
    head=NULL;
}

//ordered print
template<class Element> string BST<Element>::print(BSTNode<Element>* node)
{
    if (node->left!=NULL && node->right!=NULL)
        return print(node->left) + " " + to_string(node->data) + " " + print(node->right);
    else if (node->left!=NULL)
        return print(node->left) + " "+ to_string(node->data);
    else if (node->right!=NULL)
        return to_string(node->data) + " " + print(node->right);
    return to_string(node->data);
}


#endif
