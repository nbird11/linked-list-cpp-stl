# C++ Linked List Implementation

This project implements a custom doubly-linked list data structure in C++. The implementation provides a robust foundation for linked list operations with comprehensive memory management.

## Overview

The custom linked list is implemented through a Node class template that supports bidirectional linking. Key features include:

- Template-based implementation supporting any data type
- Doubly-linked structure with previous and next pointers
- Memory-efficient node management
- Support for both copy and move semantics
- Comprehensive node manipulation utilities

## Class Structure

### `Node<T>`
The main node class template with one parameter:
- T: Type of element stored in the node

Key attributes:
- `data`: The stored element
- `pNext`: Pointer to the next node
- `pPrev`: Pointer to the previous node

## Node Operations

The implementation includes several utility functions:

### Core Operations
- `insert()`: Insert a new node before/after a given position
- `remove()`: Remove a node from the list
- `copy()`: Deep copy a list
- `assign()`: Copy values while reusing existing nodes
- `clear()`: Delete all nodes in a list
- `swap()`: Exchange two lists
- `size()`: Count nodes in a list

### Memory Management
- Efficient node reuse in assignment operations
- Proper cleanup of unused nodes
- Prevention of memory leaks

## Usage Example

```cpp
#include "node.h"

// Create nodes with integers
Node<int>* head = new Node<int>(1);
insert(head, 2, true);  // Insert after
insert(head, 0, false); // Insert before

// Copy a list
Node<int>* newList = copy(head);

// Clean up
clear(head);
clear(newList);
```

## Testing

The implementation includes comprehensive unit tests in `testNode.h` that verify:
- Node creation and deletion
- Insert and remove operations
- Copy and assignment operations
- Memory management
- Edge cases

## Files

- `node.h`: Main node implementation with utility functions
- `testNode.h`: Unit tests
- `unitTest.h`: Unit testing framework

## Building

The project includes Visual Studio solution files for building on Windows. Open `LabLinkedList.sln` and build using Visual Studio 2019 or later.

## Notes

- This is an educational implementation focused on demonstrating linked list concepts
- The implementation provides a foundation for more complex data structures
- Special attention is paid to memory management and edge cases
- The node structure supports both forward and backward traversal

## License

This code is provided for educational purposes. See included license file for terms of use. [TODO: add LICENSE]

## Authors

Nathan Bird  
[nathanbirdka@gmail.com](mailto:nathanbirdka@gmail.com)

Brock Hoskins  
[]()