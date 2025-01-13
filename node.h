#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <sstream>

class node
{
    public:
    
        int data;
        node* prev;
        node* next;

        node(int val);
        ~node();
        void destroyList();
        bool contains(int val);
        void insert (int val);
        void print();
        node* remove (int val);
        node* head();
        node* tail();
        void insert(node* n);
        int length();
        
};

#endif