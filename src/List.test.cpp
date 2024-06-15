// Machine generated test code
#include <iostream>
#include "Node.h"
#include "List.cpp"

void testUnsortedList() {
    std::cout << "Testing UnsortedList..." << std::endl;
    UnsortedList<int> unsortedList = {3, 1, 4, 1, 5, 9};

    std::cout << "Initial UnsortedList: ";
    int item;
    unsortedList.ResetList();
    for (int i = 0; i < unsortedList.LengthIs(); i++) {
        unsortedList.GetNextItem(item);
        std::cout << item << " ";
    }
    std::cout << std::endl;

    // Test InsertItem
    unsortedList.InsertItem(2);
    unsortedList.InsertItem(6);
    unsortedList.InsertItem(5);
    std::cout << "After inserting 2, 6, 5: ";
    unsortedList.ResetList();
    for (int i = 0; i < unsortedList.LengthIs(); i++) {
        unsortedList.GetNextItem(item);
        std::cout << item << " ";
    }
    std::cout << std::endl;

    // Test RetrieveItem
    bool found;
    item = 4;
    unsortedList.RetrieveItem(item, found);
    std::cout << "Retrieve item 4: " << (found ? "found" : "not found") << std::endl;
    item = 7;
    unsortedList.RetrieveItem(item, found);
    std::cout << "Retrieve item 7: " << (found ? "found" : "not found") << std::endl;

    // Test DeleteItem
    unsortedList.DeleteItem(1);
    std::cout << "After deleting 1: ";
    unsortedList.ResetList();
    for (int i = 0; i < unsortedList.LengthIs(); i++) {
        unsortedList.GetNextItem(item);
        std::cout << item << " ";
    }
    std::cout << std::endl;

    unsortedList.DeleteItem(5);
    std::cout << "After deleting 5: ";
    unsortedList.ResetList();
    for (int i = 0; i < unsortedList.LengthIs(); i++) {
        unsortedList.GetNextItem(item);
        std::cout << item << " ";
    }
    std::cout << std::endl;

    // Test LengthIs and IsFull
    std::cout << "List length: " << unsortedList.LengthIs() << std::endl;
    std::cout << "List is full: " << (unsortedList.IsFull() ? "yes" : "no") << std::endl;
}

void testSortedList() {
    std::cout << "Testing SortedList..." << std::endl;
    SortedList<int> sortedList = {3, 1, 4, 1, 5, 9};

    std::cout << "Initial SortedList: ";
    int item;
    sortedList.ResetList();
    for (int i = 0; i < sortedList.LengthIs(); i++) {
        sortedList.GetNextItem(item);
        std::cout << item << " ";
    }
    std::cout << std::endl;

    // Test InsertItem
    sortedList.InsertItem(2);
    sortedList.InsertItem(6);
    sortedList.InsertItem(5);
    std::cout << "After inserting 2, 6, 5: ";
    sortedList.ResetList();
    for (int i = 0; i < sortedList.LengthIs(); i++) {
        sortedList.GetNextItem(item);
        std::cout << item << " ";
    }
    std::cout << std::endl;

    // Test RetrieveItem
    bool found;
    item = 4;
    sortedList.RetrieveItem(item, found);
    std::cout << "Retrieve item 4: " << (found ? "found" : "not found") << std::endl;
    item = 7;
    sortedList.RetrieveItem(item, found);
    std::cout << "Retrieve item 7: " << (found ? "found" : "not found") << std::endl;

    // Test DeleteItem
    sortedList.DeleteItem(1);
    std::cout << "After deleting 1: ";
    sortedList.ResetList();
    for (int i = 0; i < sortedList.LengthIs(); i++) {
        sortedList.GetNextItem(item);
        std::cout << item << " ";
    }
    std::cout << std::endl;

    sortedList.DeleteItem(5);
    std::cout << "After deleting 5: ";
    sortedList.ResetList();
    for (int i = 0; i < sortedList.LengthIs(); i++) {
        sortedList.GetNextItem(item);
        std::cout << item << " ";
    }
    std::cout << std::endl;

    // Test LengthIs and IsFull
    std::cout << "List length: " << sortedList.LengthIs() << std::endl;
    std::cout << "List is full: " << (sortedList.IsFull() ? "yes" : "no") << std::endl;
}