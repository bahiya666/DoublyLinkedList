Doubly Linked List with Node Class
This project is an implementation of a doubly linked list, where each node contains a data element and pointers to both the next and previous nodes in the list. The code demonstrates how to create, manipulate, and interact with nodes in a doubly linked list.

Classes and Their Functions
node Class
The node class represents a single node in the doubly linked list. Each node contains an integer data, a pointer to the previous node (prev), and a pointer to the next node (next).

Public Methods
  Constructor:
  node(int val) - Initializes the node with a given integer value and sets next and prev pointers to NULL.
  Destructor:
  ~node() - Cleans up the node by nullifying the next and prev pointers.
  destroyList() - Destroys the entire list starting from the current node by deleting nodes in both directions until the end.
  contains(int val) - Searches for the specified value in the list and returns true if the value is found, otherwise false.
  insert(int val) - Inserts a new node with the given value into the list in a sorted order.
  insert(node* n) - Merges another list into the current list while keeping the combined list sorted.
  print() - Prints the values of the nodes in the list in a readable format.
  length() - Returns the number of nodes in the list.
  remove(int val) - Removes the first node with the specified value from the list and returns the node that was removed.
  head() - Returns the first node in the list.
  tail() - Returns the last node in the list.

Compile the C++ code:
Run the following command in your terminal or command prompt:
g++ -o main main.cpp
./main
