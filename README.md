# Singly Linked List in C

A command-line project that implements a singly linked list in C. This project is a learning exercise focused on pointers, dynamic memory allocation, linked-list traversal, searching, node deletion, and memory management.

## Overview

The program reads three integers from the user and stores them in a singly linked list. It then searches for a specified value, asks the user which value to delete, and prints the resulting list.

The implementation uses dynamically allocated nodes and provides separate functions for appending, printing, searching, deleting, and freeing list nodes.

## Features

- Define a singly linked list using a `struct`.
- Allocate nodes dynamically using `malloc()`.
- Append new nodes to the end of the list.
- Print list elements in order.
- Search for the first occurrence of a value.
- Return the zero-based index of a matching value, or `-1` if it is not found.
- Delete the first occurrence of a specified value.
- Handle deletion of the head node separately.
- Leave the list unchanged if the requested deletion target does not exist.
- Check whether integer input is successfully read.
- Release dynamically allocated memory before normal program termination.

## Data Structure

Each node contains two fields:

- `data`: Stores an integer.
- `next`: Points to the next node in the list.

The `head` pointer references the first node. The last node points to `NULL`, and an empty list is represented by `head == NULL`.

Example:

```text
head
 |
 v
[10 | next] -> [20 | next] -> [30 | NULL]
```

Nodes are dynamically allocated and do not need to occupy adjacent memory locations.

## Functions

| Function | Description |
|---|---|
| `printList(head)` | Prints all elements in the list. |
| `appendNode(head, data)` | Creates a node and appends it to the end of the list. |
| `searchList(head, target)` | Returns the zero-based index of the first matching value, or `-1` if absent. |
| `deleteNode(head, target)` | Deletes the first matching node and returns the updated head pointer. |
| `freeList(head)` | Frees all nodes in the list. |

### Why Do Some Functions Return a Pointer?

Both `appendNode()` and `deleteNode()` can change the head pointer.

For example:

```c
head = appendNode(head, number);
head = deleteNode(head, num);
```

When a node is added to an empty list or the first node is deleted, the head pointer changes. Assigning the returned pointer back to `head` ensures that the program uses the correct starting node.

## Development Notes

This project was developed incrementally as a practical exercise in C programming.

The main learning topics include:

1. Defining a node structure and traversing a linked list.
2. Allocating memory dynamically and appending nodes.
3. Managing pointers while traversing the list.
4. Searching for values and returning their indices.
5. Deleting nodes, including the special case of deleting the head.
6. Freeing dynamically allocated memory.
7. Checking the result of `scanf()` before using input values.

Comments are included in the source code to explain the purpose of the main operations and pointer manipulations.

## Complexity Analysis

Let `n` be the number of nodes in the list.

| Function | Time Complexity |
|---|---|
| `printList()` | O(n) |
| `appendNode()` | O(n) |
| `searchList()` | O(n) |
| `deleteNode()` | O(n) |
| `freeList()` | O(n) |

The list requires O(n) memory for its nodes.

Note: `deleteNode()` searches for the target and then traverses the list again when the target is not the head. A future improvement could perform the search and deletion in a single traversal.

## Build and Run

### Requirements

- A C compiler, such as GCC or Clang.
- Git Bash or another terminal on Windows, or a terminal on Linux/macOS.

### Compile with GCC

Run the following command from the project directory:

```bash
gcc -std=c11 -Wall -Wextra -Wpedantic Singly-linked-list.c -o Singly-linked-list.exe
```

### Run on Windows using Git Bash

```bash
./Singly-linked-list.exe
```

### Run on Linux or macOS

Compile with an output filename appropriate for your system:

```bash
gcc -std=c11 -Wall -Wextra -Wpedantic Singly-linked-list.c -o singly-linked-list
```

Then run:

```bash
./singly-linked-list
```

## Example Session

```text
Enter number 1: 10
Enter number 2: 20
Enter number 3: 30
Enter number to search: 20
20 found at index 1

Enter number to delete from the list: 20
20 deleted from the list.
10    30
```

The values in the final list are separated by tab characters.

## Current Limitations

- The program accepts exactly three initial integers.
- Each run performs one search and one deletion attempt.
- Only the first occurrence of a duplicate value is deleted.
- Input validation checks whether `scanf()` successfully reads an integer, but does not validate the entire input line.
- Appending a node requires traversing the list to find its end.
- If memory allocation fails, the program frees the existing list and exits.

## Future Improvements

- Allow the user to enter an arbitrary number of elements.
- Add a menu for repeated list operations.
- Improve input validation using `fgets()` and `strtol()`.
- Optimize deletion to use a single traversal.
- Maintain a tail pointer to make appending more efficient.
- Add automated tests and memory-checking tools.

## Repository

GitHub: https://github.com/sevdatlby/singly-linked-list-c

## Changelog

### Initial Version

- Implemented the singly linked list node structure.
- Added functions for printing, appending, searching, deleting, and freeing nodes.
- Added basic input validation and explanatory comments.
- Documented the implementation and build instructions.
