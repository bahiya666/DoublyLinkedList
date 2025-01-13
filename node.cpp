#include "node.h"
#include <sstream>
#include <iostream>

node::node (int val): data(val), next(NULL), prev(NULL)
{}

node::~node()
{
    // delete next;
    // delete prev;
    next = NULL;
    prev = NULL;
}

void node::destroyList()
{
    node* current = this;

    while (current->prev != NULL) 
    {
        current = current->prev;
    }
    while (current != NULL)
    {
        node* temp = current;
        current = current->next;
        temp->next = NULL;
        temp->prev = NULL;
        delete temp;
    }
}

bool node::contains(int val)
{
    node* current = this;

    while (current != NULL)
    {
        if(current->data ==val)
        {
            return true;
        }
        current = current->next;
    }

    current = this;

    while (current != NULL)
    {
        if(current->data ==val)
        {
            return true;
        }
        current = current->prev;
    }

    // delete current;
    return false;
}

void node:: insert(int val)
{
    // if(!contains(val))
    // {    
    //     node* newnode = new node(val); //delete this in main
    //     node* current = this;

    //     while (current !=NULL)
    //     {
    //         if (val < current->data)
    //         {
    //             if (current->prev != NULL)
    //             {
    //                 current->prev->next = newnode;
    //             }
    //             newnode->prev = current->prev;
    //             current->prev = newnode;
    //             newnode->next = current;

    //             if (current == this)
    //             {
    //                 return;
    //             }
    //             return;
    //         }
    //         if (current->next == NULL)
    //         {
    //             current->next = newnode;
    //             newnode->prev = current;
    //             return;
    //         }
    //         current = current->next;
    //     }

    // }

    if (data == val) {
        // Value already exists in the list, do nothing
        return;
    }

    node* newNode = new node(val);
    node* current = this;

    while (current->prev != NULL) {
        current = current->prev;
    }

    // Find the appropriate position to insert the new node
    while (current != NULL) {
        if (val < current->data) {
            break;
        }
        current = current->next;
    }

    if (current == NULL) {
        // Insert at the end of the list
        current = this;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    } else {
        // Insert the new node before the current node
        newNode->next = current;
        newNode->prev = current->prev;
        current->prev = newNode;

        if (newNode->prev != NULL) {
            newNode->prev->next = newNode;
        }
    }
     
}


void node:: insert (node* n)
{
    if (n == NULL || n->data == data) {
        return;
    }

    // Merge the two lists while keeping them sorted.
    node* currentThis = this;
    node* currentOther = n;

    while (currentOther != NULL) {
        if (currentThis == NULL || currentOther->data < currentThis->data) {
            // Insert the currentOther node before currentThis.
            node* nextOther = currentOther->next;

            if (currentThis != NULL) {
                currentThis->prev = currentOther;
                currentOther->next = currentThis;
            }

            currentOther->prev = NULL;
            currentThis = currentOther;
            currentOther = nextOther;
        } else if (currentOther->data == currentThis->data) {
            // Duplicate values, delete currentOther node.
            node* nextOther = currentOther->next;
            delete currentOther;
            currentOther = nextOther;
        } else {
            // Move to the next node in this list.
            currentThis = currentThis->next;
        }
    }
}

void node::print()
{
    // node* current = head();

    // while (current != NULL ) 
    // {
    //     if (current != this) 
    //     {
    //         std::cout << "->";
    //     }

    //     if (current == this) 
    //     {
    //         std::cout << "[" << current->data << "]";
    //     } 
    //     else 
    //     {
    //         std::cout << current->data;
    //     }

    //     current = current->next;
    // }

    // std::cout << std::endl;

    node* current = head(); // Start from the head node
    while (current != NULL) {
        if (current == this) {
            std::cout << "[" << current->data << "]";
        } else {
            std::cout << current->data;
        }
        if (current->next != NULL) {
            std::cout << "->";
        }
        current = current->next;
    }
    std::cout << std::endl;
}

    

int node:: length()
{
    int count = 0;
    node* current = this;

    while (current->prev != NULL) 
    {
        count++;
        current = current->prev;
    }

    while (current != NULL) 
    {
        count++;
        current = current->next;
    }

    return count;
}

node* node:: remove (int val)
{
    node* current = this;

    while (current != NULL) 
    {
        if (current->data == val) 
        {
            if (current == this) 
            {
                if (current->next != NULL) 
                {
                    current->next->prev = NULL;
                }
                return current;
            } 
            else if (current->next != NULL) 
            {
                current->prev->next = current->next;
                current->next->prev = current->prev;
                return current;
            } 
            else 
            {
                current->prev->next = NULL;
                return current;
            }
        }
        current = current->next;
    }

    return NULL;
}

node* node:: head() 
{
    node* current = this;

    while (current->prev != NULL) 
    {
        current = current->prev;
    }

    return current;
}

// Return the last node in the list.
node* node:: tail() 
{
    node* current = this;

    while (current->next != NULL) 
    {
        current = current->next;
    }

    return current;
}