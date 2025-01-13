
#include "node.cpp"

int main() {
    node* list1 = new node(2);
    list1->insert(4);
    list1->insert(6);
    list1->insert(8);
    list1->insert(10);

    node* list2 = new node(5);
    list2->insert(1);
    list2->insert(3);
    list2->insert(7);
    list2->insert(9);

    list1->print();
    list2->print();

    if (list1->contains(6)) {
        std::cout << "Value 6" << " is in the list." << std::endl;
    } else {
        std::cout << "Value 6"  << " is not in the list." << std::endl;
    }

    
    list1->remove(6);
    list1->print();
    std::cout << list1->length()<< std::endl;

    node* headnode1 = list1->head();
    node* tailnode1 = list1->tail();

    // Print the values of the head and tail nodes.
    std::cout << "Head Node: " << headnode1->data << std::endl;
    std::cout << "Tail Node: " << tailnode1->data << std::endl;
    
   node* headNode = list2->head();
    node* tailNode = list2->tail();

    // Print the values of the head and tail nodes.
    std::cout << "Head Node: " << headNode->data << std::endl;
    std::cout << "Tail Node: " << tailNode->data << std::endl;

    if (list1->contains(6)) {
        std::cout << "Value 6" << " is in the list." << std::endl;
    } else {
        std::cout << "Value 6"  << " is not in the list." << std::endl;
    }

    

    
    list1->insert(list2);
    list1->print();
    list2->print();

    list1->destroyList();
    list2->destroyList();
    
    return 0;
}

