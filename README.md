*This project has been created as part of the 42 curriculum by rexposit.*

# CPP Module 08

`CPP Module 08` is part of the CPP modules of the 42 curriculum. The project introduces STL containers, iterators and algorithms.

Throughout the module, standard containers are searched using generic functions, ranges of iterators are used to insert multiple elements, and a `MutantStack` class is implemented to extend `std::stack` with iterator support.

---

# Table of Contents

- [Description](#description)
- [Project Rules](#project-rules)
- [Exercises Overview](#exercises-overview)
- [STL Overview](#stl-overview)
- [Implementation](#implementation)
- [Compilation](#compilation)
- [Testing](#testing)
- [Project Structure](#project-structure)
- [What I Learned](#what-i-learned)
- [Author](#author)

---

# Description

CPP Module 08 is divided into three independent exercises, each focusing on a different use of STL containers, iterators and algorithms in CPP.

### ex00 — Easy Find

Introduces the `easyfind` function template.

It receives:

- a container of integers;
- an integer value to find.

The function uses `std::find` to search the container and returns an iterator to the first matching element.

If the value cannot be found, an exception is thrown.

This exercise introduces STL algorithms and generic access to container iterators.

---

### ex01 — Span

Introduces the `Span` class.

The class stores a limited number of integers and calculates the shortest and longest distance between its stored values.

It supports:

- construction with a maximum capacity;
- insertion of individual numbers;
- insertion using a range of iterators;
- shortest span calculation;
- longest span calculation;
- exception handling when the container is full;
- exception handling when there are not enough values to calculate a span.

The exercise combines STL containers, algorithms, iterators and exception handling.

---

### ex02 — MutantStack

Introduces the `MutantStack<T>` class template.

`std::stack` provides stack operations but does not expose iterators.

`MutantStack` inherits from `std::stack` and preserves its existing behavior while adding:

```cpp
begin()
end()
```

This makes it possible to iterate over the underlying container while still using normal stack operations such as:

```cpp
push
pop
top
size
```

The exercise combines inheritance, templates and iterators.

---

# Project Rules

The project follows the requirements of CPP Module 08.

- CPP98 standard
- Compilation with:

```bash
-Wall -Wextra -Werror -std=c++98
```

- STL containers
- STL algorithms
- Iterators
- Function templates
- Class templates
- Header include guards
- Orthodox Canonical Form for classes
- Exception handling for invalid operations
- Use of containers and algorithms whenever appropriate

---

# Exercises Overview

| Exercise | Main Concept | Executable |
|----------|--------------|------------|
| ex00 | STL algorithms and iterators | `easy_find` |
| ex01 | Containers, algorithms and iterator ranges | `Span` |
| ex02 | Iterable stack through inheritance | `mutated_abomination` |

---

# STL Overview

CPP Module 08 introduces the Standard Template Library as a central part of the implementation.

```text
                     STL
                      │
        ┌─────────────┼─────────────┐
        │             │             │
        ▼             ▼             ▼
    Containers     Iterators     Algorithms
        │             │             │
        ▼             ▼             ▼
     vector         begin()       std::find
      list           end()        std::sort
      stack            │       std::min_element
        │              │       std::max_element
        └──────────────┴─────────────┘
                       │
                       ▼
                Generic operations
```

Containers store the data, iterators provide a generic way to traverse it, and algorithms operate on ranges defined by iterators.

A range is represented by:

```text
[first, last)
```

The first iterator points to the first element included in the range, while the last iterator points just after the final element.

---

# Implementation

## Easy Find

Exercise 00 implements:

```cpp
template <typename T>
typename T::iterator easyfind(T &container, int value);
```

The function searches between:

```cpp
container.begin()
container.end()
```

using:

```cpp
std::find
```

If the value exists, the iterator returned by `std::find` points to its first occurrence.

If the returned iterator is equal to:

```cpp
container.end()
```

the value was not found and an exception is thrown.

Because the container type is a template parameter, the same implementation can be used with different compatible containers such as:

```text
std::vector<int>
std::list<int>
```

---

## Span Class

Exercise 01 implements the `Span` class.

The class stores its values using:

```cpp
std::vector<int>
```

and keeps a maximum capacity defined during construction.

A single value can be added using:

```cpp
addNumber
```

Before inserting the value, the current number of elements is checked against the maximum capacity.

If the `Span` is already full, an exception is thrown.

---

## Iterator Range Insertion

Multiple values can be inserted in a single operation using:

```cpp
addNumbers(first, last)
```

The number of elements in the range is calculated using:

```cpp
std::distance(first, last)
```

The available capacity is checked before modifying the container.

If the complete range fits, it is inserted using:

```cpp
values.insert(values.end(), first, last);
```

This allows thousands of values to be added without repeatedly calling `addNumber`.

---

## Shortest Span

To calculate the shortest span, a copy of the stored values is created and sorted using:

```cpp
std::sort
```

Only consecutive values in the sorted container need to be compared.

For example:

```text
Original:  17  3  11  6  9

Sorted:     3  6   9 11 17
             │  │   │  │
Spans:       3  3   2  6
```

The smallest distance is therefore:

```text
2
```

The original container is not modified because the sorting operation is performed on a copy.

---

## Longest Span

The longest span is calculated using:

```cpp
std::min_element
std::max_element
```

The distance between the smallest and largest stored values represents the longest possible span.

For example:

```text
3 ─────────────────── 17
          14
```

If fewer than two values are stored, both span functions throw an exception because no valid distance can be calculated.

---

## MutantStack

Exercise 02 implements:

```cpp
template <typename T>
class MutantStack : public std::stack<T>;
```

Public inheritance preserves the normal interface of `std::stack`.

This means `MutantStack` automatically supports operations such as:

```cpp
push
pop
top
size
```

without implementing them again.

The copy constructor and assignment operator delegate the inherited state to `std::stack<T>`.

---

## Stack Iterators

`std::stack` stores its elements inside an underlying container but does not expose iterators publicly.

The underlying container is accessible to derived classes through the protected member:

```cpp
c
```

Its iterator type is exposed in `MutantStack` using:

```cpp
typedef typename std::stack<T>::container_type::iterator iterator;
```

The `begin` and `end` functions then return:

```cpp
this->c.begin()
this->c.end()
```

This makes the stack iterable while preserving its original stack operations.

For example:

```text
MutantStack
     │
     ▼
 std::stack
     │
     ▼
underlying container
     │
     ├── begin()
     │
     └── end()
```

---

# Compilation

Each exercise is independent.

Compile any exercise by entering its directory.

Example:

```bash
cd ex00
make
./easy_find
```

The other exercises can be compiled and executed with:

```bash
cd ex01
make
./Span
```

or:

```bash
cd ex02
make
./mutated_abomination
```

Available Makefile rules:

```bash
make
make clean
make fclean
make re
```

---

# Testing

The test programs verify:

- `easyfind` with vector containers;
- `easyfind` with list containers;
- successful and unsuccessful searches;
- individual insertion into a `Span`;
- exceptions when a `Span` is full;
- exceptions when there are not enough values to calculate a span;
- shortest and longest span calculations;
- insertion using iterator ranges;
- insertion and span calculation with 10,000 values;
- rejection of ranges exceeding the available capacity;
- span calculations using integer limits;
- inherited `std::stack` operations;
- iteration through a `MutantStack`;
- copy construction of a `MutantStack`;
- assignment between `MutantStack` objects;
- independence between copied stacks;
- `MutantStack` with different element types.

Example `Span` test:

```text
Shortest span: 2
Longest span: 14
```

A range containing 10,000 sequential values is also tested:

```text
Shortest span: 1
Longest span: 9999
```

Invalid insertion is tested by attempting to exceed the maximum capacity:

```text
Error: Span is full
```

`MutantStack` iteration is verified with:

```text
Elements (expected 5 3 5 737 0): 5 3 5 737 0
```

Copy independence is also tested by modifying a copied stack and checking that the original size remains unchanged.

---

# Project Structure

```text
42_cpp_module_08/
│
├── ex00/
│   ├── easyfind.hpp
│   ├── main.cpp
│   └── Makefile
│
├── ex01/
│   ├── Span.hpp
│   ├── Span.cpp
│   ├── main.cpp
│   └── Makefile
│
├── ex02/
│   ├── MutantStack.hpp
│   ├── MutantStack.tpp
│   ├── main.cpp
│   └── Makefile
│
└── README.md
```

---

# What I Learned

Through this module I strengthened my understanding of:

- STL containers;
- STL algorithms;
- iterators;
- iterator ranges;
- `std::find`;
- `std::distance`;
- `std::sort`;
- `std::min_element` and `std::max_element`;
- inserting ranges into STL containers;
- combining templates with STL containers;
- inheritance from standard container adapters;
- protected members in inherited classes;
- exposing iterator types with `typedef`;
- dependent types and `typename`;
- accessing the underlying container of `std::stack`;
- implementing iterable behavior on top of an existing container adapter;
- exception handling with STL-based classes.

CPP Module 08 demonstrates how containers, iterators and algorithms work together to provide reusable generic operations while avoiding unnecessary manual implementations.

---

# Author

**Raúl Expósito Campos**

42 Madrid Student

GitHub: https://github.com/raulrecrec