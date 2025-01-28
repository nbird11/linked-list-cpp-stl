# C++ STL Stack Implementation

This project implements a custom version of the C++ Standard Template Library (STL) stack container. The implementation provides exactly the same memory and performance characteristics as `std::stack`.

## Overview

The custom stack is a container adapter that provides a LIFO (Last-In-First-Out) data structure. Key features include:

- Template-based implementation supporting any data type
- Customizable underlying container (defaults to custom::vector)
- LIFO (Last-In-First-Out) data access pattern
- Element access via top()
- Push and pop operations
- Size and empty status methods

## Class Structure

### `custom::stack<T, Container>`
The main stack class template with two parameters:
- T: Type of elements
- Container: Underlying container type (default `custom::vector<T>`)

Key methods:
- `top()`: Access next element
- `push()`: Add element to top
- `pop()`: Remove top element
- `size()`, `empty()`: Container info
- `swap()`: Exchange contents with another stack

## Usage Example

```cpp
#include "stack.h"

// Create stack of integers
custom::stack<int> s;

// Add elements
s.push(1);
s.push(2);

// Access elements
int top = s.top();

// Remove elements
s.pop();
```

## Testing

The implementation includes comprehensive unit tests in `testStack.h` that verify:
- Element access operations
- Push/pop operations
- Memory management
- Edge cases

Run tests by building in debug mode with the DEBUG flag defined.

## Files

- `stack.h`: Main stack implementation
- `testStack.h`: Unit tests
- `spy.h`: Helper class for testing
- `unitTest.h`: Unit testing framework
- `vector.h`: Custom vector implementation used by stack

## Building

The project includes Visual Studio solution files for building on Windows. Open `LabStack.sln` and build using Visual Studio 2019 or later.

## Notes

- This is an educational implementation focused on demonstrating STL container concepts
- The implementation aims to match `std::stack`'s interface and performance
- The stack is implemented as a container adapter, using a custom vector as its default underlying container

#### Disclaimer

This README was initially generated using an AI Language Model (Claude 3.5 Sonnet) and subsequently edited by a human for accuracy and completeness. While the content accurately describes the codebase, the writing structure and initial draft were AI-assisted. The actual code implementation and testing were completed by human developers.

## License

This code is provided for educational purposes. See included license file for terms of use. [TODO: add LICENSE]

## Authors

Nathan Bird  
[nathanbirdka@gmail.com](mailto:nathanbirdka@gmail.com)

Brock Hoskins  
[]()