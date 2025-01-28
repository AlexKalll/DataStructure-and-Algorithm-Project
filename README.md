# Data Structure and Algorithm Project

## Overview

This project implements a **Doubly Linked List** and a **Binary Search Tree (BST)** for managing student records. The data is persisted using file management, allowing the program to load and save student information seamlessly.

## Table of Contents

- [Doubly Linked List Operations](#doubly-linked-list-operations)
  - [Insertions](#insertions)
  - [Deletions](#deletions)
  - [Searching](#searching)
  - [Traversal](#traversal)
  - [File Management](#file-management)
- [Binary Search Tree Operations](#binary-search-tree-operations)
  - [Insertions](#insertions-1)
  - [Searching](#searching-1)
  - [Deletions](#deletions-1)
  - [Traversals](#traversals)
  - [Finding Min/Max](#finding-minmax)
- [Usage](#usage)

## Doubly Linked List Operations

The Doubly Linked List allows for efficient insertion and deletion of student records.

### Insertions

1. **Insert at Beginning**
   - Adds a new student record at the start of the list.
   - **Function:** `insertAtBeginning(string name, string id)`

2. **Insert at End**
   - Appends a new student record to the end of the list.
   - **Function:** `insertAtEnd(string name, string id)`

3. **Insert at Position**
   - Inserts a student record at a specified position (1-indexed).
   - **Function:** `insertAtPosition(string name, string id, int position)`

### Deletions

1. **Delete at Beginning**
   - Removes the first student record from the list.
   - **Function:** `deleteAtBeginning()`

2. **Delete at End**
   - Removes the last student record from the list.
   - **Function:** `deleteAtEnd()`

3. **Delete at Position**
   - Deletes a student record at a specified position (1-indexed).
   - **Function:** `deleteAtPosition(int position)`

4. **Delete by ID**
   - Removes a student record based on the unique ID.
   - **Function:** `deleteByID(string id)`

5. **Delete All**
   - Clears all records from the list.
   - **Function:** `deleteAll()`

### Searching

- **Search by ID**
  - Finds and displays a student record based on the unique ID.
  - **Function:** `searchByID(string id)`

### Traversal

1. **Display Forward**
   - Displays all student records from head to tail.
   - **Function:** `displayForward()`

2. **Display Backward**
   - Displays all student records from tail to head.
   - **Function:** `displayBackward()`

### File Management

- **Load from File**
  - Loads student records from a file upon starting the program.
  - **Function:** `loadFromFile()`

- **Save to File**
  - Saves the current list of student records to a file after each modification.
  - **Function:** `saveToFile()`

## Binary Search Tree Operations

The Binary Search Tree (BST) provides an efficient way to manage student records sorted by ID.

### Insertions

- **Insert**
  - Adds a new student record to the BST based on the unique ID.
  - **Function:** `insert(Student*& node, string name, string id)`

### Searching

- **Search**
  - Finds a student record by ID and returns the corresponding node.
  - **Function:** `search(Student* node, string id)`

### Deletions

- **Delete Node**
  - Removes a student record from the BST based on the unique ID.
  - **Function:** `deleteNode(Student*& node, string id)`

### Traversals

1. **In-Order Traversal**
   - Displays student records in ascending order of IDs.
   - **Function:** `inOrder(Student* node)`

2. **Pre-Order Traversal**
   - Displays student records starting from the root, then left subtree, then right subtree.
   - **Function:** `preOrder(Student* node)`

3. **Post-Order Traversal**
   - Displays student records starting from the left subtree, then right subtree, then root.
   - **Function:** `postOrder(Student* node)`

4. **Breadth-First Traversal**
   - Displays student records level by level.
   - **Function:** `BFS(Student* root)`

### Finding Min/Max

- **Find Minimum ID**
  - Finds and displays the student with the smallest ID.
  - **Function:** `findMin(Student* node)`

- **Find Maximum ID**
  - Finds and displays the student with the largest ID.
  - **Function:** `findMax(Student* node)`

## Usage

1. Clone the repository:
   ```bash
   git clone https://github.com/AlexKalll/DataStructure-and-Algorithm-Project
