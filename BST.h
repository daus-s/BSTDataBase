#ifndef BSTNode_H
#define BSTNode_H

#include <iostream>
#include <string>
using namespace std;

template <class Element> class BSTNode
{
    public:
        Element data;
        BSTNode<Element>* left;
        BSTNode<Element>* right;

        BSTNode<Element>();
        BSTNode<Element>(Element e);
        string print();
};

template<class Element>
BSTNode<Element>::BSTNode()
{
    data = NULL;
    left = NULL;
    right = NULL;
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
    return "" + to_string(data);
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
        BSTNode<Element>* search(Element e);
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

    //this makes the parent of the successor possibly hold the successors left tree
    parent->right = successor->left;
    return successor;
}

template<class Element> BSTNode<Element>* BST<Element>::search(Element e)
{
    cout << "entered search" << endl;
    if (head->data==e)
        return head;

    BSTNode<Element>* current = head;
    cout << current->print() << endl;

    while (true)
    {
        if (current==NULL)
          return NULL;
        if (current->data==e)
            return current;

        if (current->data<e)
            current = current->right;
        else
            current = current->left;
    }
    return current;
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

    if (head==NULL)
        return false;

    while (true)
    {
        if (current==NULL)
        {
            return false;
        }
        if (current->data==e)
        {
            break;
        }
        parent = current;

        if (current->data<e)
        {
            current = current->right;
            left = false;
        }
        else
        {
            if (current->data>e)
            {
                current = current->left;
                left = true;
            }
        }
    }

    //best case scenario
    if (current->left==NULL && current->right==NULL)
    {
        if(current==head)
            head=NULL; //now empty list
        if (left)
            parent->left = NULL;
        if (!left)
            parent->right = NULL;

        return true;
    }

    //else the parent has a children, at least so we will take case where there is 1 children
    if (current->right==NULL)
    {
        if(current==head)
            head = current->left;
        if (left)
            parent->left = current->left;
            //derivation: current must be left by checking left bool var
            //.: the new current must remain the child of the parent so
            //the only option we have to replace is the left of the current
        if (!left)
            parent->right = current->left;
            //and vice versa,

        return true;
    }
    if (current->left==NULL)
    {
        if(current==head)
            head = current->right;
        if (left)
            parent->left = current->right;
            //derivation: current must be left by checking left bool var
            //.: the new current must remain the child of the parent so
            //the only option we have to replace is the right of the current
        if (!left)
            parent->right = current->right;
            //and vice versa,

        return true;
    }
    else //current has zwei childrenen, hahaha its in german @rene.
    {
      BSTNode<Element>* successor = getSuccessor(current);
        successor->right = current->right;
        successor->left = current->left;
        current = successor;
        if (left)
            parent->left=successor;
        if (!left)
            parent->right=successor;
        return true;
    }

}

template<class Element> BST<Element>::BST()
{
    head=NULL;
}

//ordered print
template<class Element> string BST<Element>::print(BSTNode<Element>* node)
{
    if (node->left!=NULL && node->right!=NULL)
    {
        //cout << "two children " << (node->left!=NULL && node->right!=NULL) << endl;
        return print(node->left) + " " + to_string(node->data) + " " + print(node->right);
    }
    else if (node->left!=NULL)
    {
        //cout << "left child " << (node->left!=NULL) << endl;
        return print(node->left) + " "+ to_string(node->data);
    }
    else if (node->right!=NULL)
    {
        //cout << "right child " << (node->right!=NULL) << endl;
        return to_string(node->data) + " " + print(node->right);
    }
    return to_string(node->data);
}


#endif
