#include <iostream>
#include <string>
#include <queue> // for Breadth-First Traversal
using namespace std;

// Student structure for the binary search tree
struct Student {
    string name; 
    string id;   // Unique ID
    Student* left;
    Student* right;
};

// Function to create a new student node
Student* getStudent(string name, string id) {
    Student* temp = new Student();
    temp->name = name;
    temp->id = id;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// Function to insert a new student node
void insert(Student*& node, string name, string id) {
    if (!node) {
        node = getStudent(name, id);
        return;
    }
    if (id < node->id) {
        insert(node->left, name, id);
    } else if (id > node->id) {
        insert(node->right, name, id);
    }
}

// Function to search for a student by ID
Student* search(Student* node, string id) {
    if (!node || node->id == id) {
        return node;
    }
    if (id < node->id) {
        return search(node->left, id);
    }
    return search(node->right, id);
}

// Function to find the minimum value student node
Student* findMin(Student* node) {
    while (node && node->left) {
        node = node->left;
    }
    return node;
}

// Function to find the maximum value student node
Student* findMax(Student* node) {
    while (node && node->right) {
        node = node->right;
    }
    return node;
}

// Function to delete a student node
void deleteNode(Student*& node, string id) {
    if (!node) return;

    if (id < node->id) {
        deleteNode(node->left, id);
    } else if (id > node->id) {
        deleteNode(node->right, id);
    } else {
        // Node found for deletion
        if (!node->left) {
            Student* temp = node->right;
            delete node; // Deletion by removing the node
            node = temp;
        } else if (!node->right) {
            Student* temp = node->left;
            delete node; // Deletion by removing the node
            node = temp;
        } else {
            // Node with two children: Get the inorder successor (smallest in the right subtree)
            Student* leftMin = findMin(node->right);
            node->id = leftMin->id; // Copying the ID
            node->name = leftMin->name; // Copying the name
            deleteNode(node->right, leftMin->id); // Deletion by merging
        }
    }
    cout << "\nStudent with ID " << id << " has Successfully deleted\n";
    cout << "Name: " << node->name <<"\n";
}

// In-order traversal
void inOrder(Student* node) {
    if (node) {
        inOrder(node->left);
        cout << "Name: " << node->name << ", ID: " << node->id << "\n";
        inOrder(node->right);
    } 
}

// Pre-order traversal
void preOrder(Student* node) {
    if (node) {
        cout << "Name: " << node->name << ", ID: " << node->id << "\n";
        preOrder(node->left);
        preOrder(node->right);
    } 
}

// Post-order traversal
void postOrder(Student* node) {
    if (node) {
        postOrder(node->left);
        postOrder(node->right);
        cout << "Name: " << node->name << ", ID: " << node->id << "\n";
    }
}

// Breadth-First Traversal
void BFS(Student* root) {
    if (!root) { 
        cout << "The Tree is empty! No data to traverse\n"; 
        return; 
    }

    queue<Student*> q;
    q.push(root);
    
    while (!q.empty()) {
        Student* current = q.front();
        q.pop();
        cout << "Name: " << current->name << ", ID: " << current->id << "\n";

        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
}

// Main function
int main() {
    cout << "\n========================== WELCOME =================================\n";
    cout << "Welcome to the Binary Search Tree Student Record Management Program!\n";
    cout << "Perform various operations on a binary search tree,\n";
    cout << "===================================================================\n\n";
    
    Student* root = NULL; // Initialize the root pointer
    int choice;
    string name, id;
    
    do {
        cout << "\n Menu:\n";
        cout << "1. Insert\n";
        cout << "2. Search \n";
        cout << "3. Delete \n";
        cout << "4. In-Order Traversal\n";
        cout << "5. Pre-Order Traversal\n";
        cout << "6. Post-Order Traversal\n";
        cout << "7. Breadth First Traversal\n";
        cout << "8. Find Student with Minimum ID\n"; 
        cout << "9. Find Student with Maximum ID\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Name: ";
                cin >> name;
                cout << "Enter ID: ";
                cin >> id;
                insert(root, name, id);
                cout << "The Studnet is Successfully inserted\n";
                break;
            case 2:
                if (!root) {
                    cout << " The Tree is empty. no data to traverse\n";
                    break;
                }
                cout << "Enter ID to search: ";
                cin >> id;
                {
                    Student* result = search(root, id);
                    if (result) {
                        cout << "The student is found!\n";
                        cout << "Name: " << result->name << ", ID: " << result->id << ".\n";
                    } else {
                        cout << "A student with ID " << id << " is not found in the tree.\n";
                    }
                }
                break;
            case 3:
                if (!root) {
                    cout << "The Tree is empty. no data to delete\n";
                    break;
                }
                cout << "Enter ID to delete: ";
                cin >> id;
                deleteNode(root, id);
                break;
            case 4:
                if (!root) {
                    cout << " The Tree is empty. no data to traverse\n";
                    break;
                }
                cout << "In-Order Traversal:\n";
                inOrder(root);
                break;
            case 5:
                if (!root) {
                    cout << " The Tree is empty. no data to traverse\n";
                    break;
                }
                cout << "Pre-Order Traversal:\n";
                preOrder(root);
                break;
            case 6:
                if (!root) {
                    cout << "The Tree is empty. no data to traverse\n";
                    break;
                }
                cout << "Post-Order Traversal:\n";
                postOrder(root);
                break;
            case 7:
                cout << "\nBreadth First Traversal:\n";
                BFS(root);
                break;
            case 8:
                {
                    Student* minNode = findMin(root);
                    if (minNode) {
                        cout << "Minimum ID: " << minNode->id << ", Student Name: " << minNode->name << "\n";
                    } else {
                        cout << "Tree is empty.\n";
                    }
                }
                break;
            case 9:
                {
                    Student* maxNode = findMax(root);
                    if (maxNode) {
                        cout << "Maximum ID: " << maxNode->id << ", Student Name: " << maxNode->name << "\n";
                    } else {
                        cout << "Tree is empty.\n";
                    }
                }
                break;
            case 10:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 10);

    return 0;
}
