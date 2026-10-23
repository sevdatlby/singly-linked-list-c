# Singly Linked List in C

A command-line project that implements a singly linked list in C. This project is a learning exercise focused on pointers, dynamic memory allocation, linked-list traversal, searching, node deletion, and memory management.

## Overview

The program reads three integers from the user and stores them in a singly linked list. It then searches for a specified value, asks the user which value to delete, and prints the resulting list.

The implementation uses dynamically allocated nodes and provides separate functions for appending, printing, searching, deleting, and freeing list nodes.

## Features

- Define a singly linked list using a `struct`.
- Allocate nodes dynamically with `malloc`.
- Append new nodes to the end of the list.
- Print list elements in order.
- Search for the first occurrence of a value.
- Return the zero-based index of a matching value, or `-1` if it is not found.
- Delete the first occurrence of a specified value.
- Handle deletion of the head node separately.
- Preserve the list when the requested deletion target does not exist.
- Check whether integer input is successfully read.
- Release dynamically allocated memory before normal program termination.

## Data Structure

Each node contains two fields:

- `data`: Stores an integer.
- `next`: Points to the next node.

The `head` pointer refers to the first node. The last node points to `NULL`, and an empty list is represented by `head == NULL`.

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
| --- | --- |
| `printList(head)` | Prints the values stored in the list. |
| `appendNode(head, data)` | Creates a node and appends it to the end of the list. |
| `searchList(head, target)` | Returns the first matching node's zero-based index, or `-1` if absent. |
| `deleteNode(head, target)` | Deletes the first matching node and returns the updated head pointer. |
| `freeList(head)` | Releases the memory allocated for all nodes. |

### Why Do Some Functions Return a Pointer?

Both `appendNode` and `deleteNode` can change which node is the head of the list.

- When appending to an empty list, the new node becomes the head.
- When deleting the first node, the next node becomes the head.

Therefore, the returned pointer must be assigned back to `head`:

```c
head = appendNode(head, number);
head = deleteNode(head, num);
```

Failing to update `head` can leave the program with an outdated pointer, including a pointer to a node that has already been freed.

## Development Notes

The project was developed incrementally to practice linked-list operations and understand pointer manipulation and memory management.

### 1. Node Structure and Traversal

The initial implementation defined the node structure and introduced traversal using a temporary pointer.

**Key concept:** A separate traversal pointer allows the program to visit each node without losing the original `head` pointer.

### 2. Dynamic Allocation and Appending

The `appendNode` function handles two cases:

1. If the list is empty, the newly allocated node becomes the head.
2. Otherwise, the function traverses the list and connects the new node to the last node.

The new node's `next` pointer is initialized to `NULL`.

**Key concepts:** Dynamic memory allocation, empty-list handling, and pointer traversal.

### 3. Memory Management

The `freeList` function releases nodes one at a time.

Before freeing the current node, the function saves its address in a temporary pointer and advances to the next node.

**Important lesson:** Accessing a node after freeing its memory can cause undefined behavior. The next pointer must be obtained before the current node is freed.

### 4. Searching

The `searchList` function traverses the list and compares each node's value with the target.

The index starts at `0` and increases as the function moves through the list. The function returns immediately when it finds the first match; otherwise, it returns `-1`.

**Design decision:** The `-1` result distinguishes a missing value from a valid zero-based index.

### 5. Deleting Nodes

The `deleteNode` function uses the search result to locate the target node.

Three cases are handled:

- **Target not found:** The list remains unchanged.
- **Target is the head:** The head pointer advances to the next node, and the old head is freed.
- **Target is not the head:** The predecessor is connected directly to the target's successor, and the target node is freed.

During development, particular attention was given to traversal counts, selecting the correct node to free, printing the deleted value, and updating the head pointer when deleting the first node.

### 6. Input Validation

The program checks the return value of each `scanf` call. If an integer cannot be read successfully, it prints an error message, frees the allocated list, and exits with a nonzero status.

This provides basic input-conversion error checking. Stricter validation, including rejecting trailing non-numeric characters, could be implemented using `fgets` and `strtol`.

## Complexity Analysis

Let `n` be the number of nodes in the list.

| Operation | Time Complexity | Explanation |
| --- | --- | --- |
| `printList` | O(n) | Visits each node once. |
| `appendNode` | O(n) | Traverses the list to find the last node. |
| `searchList` | O(n) | May visit every node. |
| `deleteNode` | O(n) | Searches for the target and may traverse the list again. |
| `freeList` | O(n) | Frees each node once. |

The list uses O(n) memory for its nodes.

**Potential optimization:** Maintaining a tail pointer could make appending O(1), excluding allocation overhead. Deletion could also be implemented with a single traversal rather than searching first and traversing again.

## Build and Run

Save the source code as `linked_list.c`.

### Using GCC

Compile with C11 support and common warnings enabled:

```bash
gcc -std=c11 -Wall -Wextra -Wpedantic linked_list.c -o linked_list
```

Run on Linux or macOS:

```bash
./linked_list
```

On Windows with GCC in Git Bash, run:

```bash
./linked_list.exe
```

The executable name depends on the compiler and environment.

### Using Clang

```bash
clang -std=c11 -Wall -Wextra -Wpedantic linked_list.c -o linked_list
```

Run the generated executable using the appropriate command for your operating system.

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

The list values are separated by tab characters in the actual program, so the spacing may vary between terminals.

## Testing

The following cases should be tested:

- [ ] Search for an existing value.
- [ ] Search for a value that does not exist.
- [ ] Delete the first node.
- [ ] Delete a node in the middle.
- [ ] Delete the last node.
- [ ] Attempt to delete a missing value.
- [ ] Test duplicate values and verify that only the first occurrence is deleted.
- [ ] Test non-numeric input at each prompt.
- [ ] Test deletion until the list becomes empty.

Automated unit tests have not yet been implemented.

## Limitations and Future Improvements

- The program always reads exactly three initial integers.
- The list cannot currently be modified through a repeated interactive menu.
- Only the first occurrence of a duplicate value is searched or deleted.
- `scanf` provides basic input validation but does not strictly validate the entire input line.
- Appending requires a traversal to the end of the list.
- Deletion searches for the target and then traverses the list again.
- If `malloc` fails, `appendNode` frees the current list and terminates the program.
- Automated unit tests have not yet been implemented.

Possible future improvements include:

- Allowing the user to enter an arbitrary number of elements.
- Adding an interactive menu for list operations.
- Improving error handling and input validation.
- Optimizing appending with a tail pointer.
- Implementing deletion with a single traversal.
- Adding automated tests and memory-checking tools.

## Changelog

### Initial Implementation

- Defined the node structure and implemented list printing.
- Added dynamic allocation, appending, and memory cleanup.
- Implemented searching with zero-based indexing.
- Implemented deletion, including head-node and missing-target cases.

### Input Handling and Documentation

- Added checks for failed integer input and cleanup before early termination.
- Refined comments to explain pointer manipulation and memory management.
- Documented the implementation, design decisions, limitations, and future improvements.

---

This project is a learning exercise and may be extended as new C programming and data-structure concepts are learned.
