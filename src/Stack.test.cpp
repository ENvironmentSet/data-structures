#include <iostream>
#include "Stack.cpp"

void TestStack() {
    // Test 1: Initialize stack with initializer list and check top element
    Stack<int> stack1 = {1, 2, 3};
    std::cout << "Test 1 - Top element (expected 3): " << stack1.Top() << std::endl;
    
    // Test 2: Push elements and check top element
    stack1.Push(4);
    std::cout << "Test 2 - Top element after pushing 4 (expected 4): " << stack1.Top() << std::endl;
    
    // Test 3: Pop element and check top element
    int poppedElement;
    stack1.Pop(poppedElement);
    std::cout << "Test 3 - Popped element (expected 4): " << poppedElement << std::endl;
    std::cout << "Test 3 - Top element after popping (expected 3): " << stack1.Top() << std::endl;
    
    // Test 4: Check if stack is empty
    Stack<int> stack2;
    std::cout << "Test 4 - Is stack2 empty (expected true): " << std::boolalpha << stack2.IsEmpty() << std::endl;
    
    // Test 5: Push elements and check if stack is not empty
    stack2.Push(10);
    std::cout << "Test 5 - Is stack2 empty after pushing 10 (expected false): " << std::boolalpha << stack2.IsEmpty() << std::endl;
    
    // Test 6: Pop elements until stack is empty and handle exception
    stack2.Pop(poppedElement);
    std::cout << "Test 6 - Popped element (expected 10): " << poppedElement << std::endl;
    std::cout << "Test 6 - Is stack2 empty after popping (expected true): " << std::boolalpha << stack2.IsEmpty() << std::endl;
    try {
        stack2.Pop(poppedElement);
    } catch (const EmptyStack &e) {
        std::cout << "Test 6 - Caught exception (expected 'Stack is empty'): " << e.what() << std::endl;
    }
    
    // Test 7: Check if stack is full (assuming we never actually run out of memory in the test)
    std::cout << "Test 7 - Is stack2 full (expected true): " << std::boolalpha << stack2.IsFull() << std::endl;
    
    // Test 8: Make stack empty and verify
    stack1.MakeEmpty();
    std::cout << "Test 8 - Is stack1 empty after MakeEmpty (expected true): " << std::boolalpha << stack1.IsEmpty() << std::endl;
    
    std::cout << "All tests completed!" << std::endl;
}