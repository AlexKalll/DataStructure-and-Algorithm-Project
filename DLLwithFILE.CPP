#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Student structure for the doubly linked list
struct Student {
    string name; // Name (First and Last)
    string id;   // ID (unique)
    Student* prev;
    Student* next;
} *head = NULL, *tail = NULL;

const string fileName = "sample.txt";

// Create a new student node
Student* getStudent(string name, string id) {
    Student* temp = new Student();
    temp->name = name;
    temp->id = id;
    temp->prev = NULL;
    temp->next = NULL;
    return temp;
}

// Save the current list to the file
void saveToFile() {
    ofstream file;
    file.open(fileName, ios::out | ios::trunc);
    Student* curr = head;
    while (curr) {
        file << curr->name << " " << curr->id << "\n";
        curr = curr->next;
    }
    file.close();
}

// Load the list from the file
void loadFromFile() {
    ifstream file;
    file.open(fileName, ios::in);
    if (!file.is_open())
        return;

    string name, id;
    while (file >> name >> id) {
        // Load elements without saving to avoid redundancy
        Student* temp = getStudent(name, id);
        if (!head) {
            head = tail = temp;
        } else {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
    }
    file.close();
}

// Check if the list is empty
bool isEmpty() {
    return head == NULL;
}

// Insert a value at the end of the list
void insertAtEnd(string name, string id) {
    Student* temp = getStudent(name, id);
    if (!head) {
        head = tail = temp;
    } else {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
    saveToFile(); // Save to file only when a new student is added
}

// Insert a value at the beginning of the list
void insertAtBeginning(string name, string id) {
    Student* temp = getStudent(name, id);
    if (!head) {
        head = tail = temp;
    } else {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
    saveToFile(); // Save to file only when a new student is added
}

// Delete a student at the beginning of the list
void deleteAtBeginning() {
    if (isEmpty()) {
        cout << "\nThe list is empty! no data to delete\n";
        return;
    }

    Student* temp = head;
    head = head->next;
    if (head) {
        head->prev = NULL;
    } else {
        tail = NULL; // List is now empty
    }
    cout << "\nSuccessfully deleted\n";
    cout << "Student: " << temp->name << " (ID: " << temp->id << ")\n";
    delete temp;
    saveToFile(); // Save to file after deletion
}

// Delete a student at the end of the list
void deleteAtEnd() {
    if (isEmpty()) {
        cout << "\nThe record is empty! no data to delete\n";
        return;
    }

    Student* temp = tail;
    tail = tail->prev;
    if (tail) {
        tail->next = NULL;
    } else {
        head = NULL; // the List is now empty
    }
    cout << "\nSuccessfully deleted\n";
    cout << "Student: " << temp->name << " (ID: " << temp->id << ")\n";
    delete temp;
    saveToFile(); // Save to file after deletion
}

// Insert a value at a specific position in the list (1-indexed)
void insertAtPosition(string name, string id, int position) {
    if (position <= 0) {
        cout << "\nInvalid position!\n";
        return;
    }

    if (position == 1) {
        insertAtBeginning(name, id);
        return;
    }

    Student* temp = getStudent(name, id);
    Student* curr = head;
    int currentPosition = 1;

    while (curr && currentPosition < position - 1) {
        curr = curr->next;
        currentPosition++;
    }

    if (!curr) {
        cout << "Position out of bounds. So it has been inserted at the end.\n";
        insertAtEnd(name, id);
        return;
    }

    temp->next = curr->next;
    temp->prev = curr;
    if (curr->next) {
        curr->next->prev = temp;
    } else {
        tail = temp;
    }
    curr->next = temp;

    saveToFile(); // Save to file after inserting
}

// Delete a student at a specific position (1-indexed)
void deleteAtPosition(int position) {
    if (isEmpty()) {
        cout << "The list is empty! no data to delete\n";
        return;
    }

    if (position <= 0) {
        cout << "Invalid position! Position must be greater than 0\n";
        return;
    }

    Student* curr = head;
    int currentPosition = 1;

    while (curr && currentPosition < position) {
        curr = curr->next;
        currentPosition++;
    }

    if (!curr) {
        cout << "\nPosition out of bounds! Maximum position is " << currentPosition - 1 << "\n";
        return;
    }

    if (curr->prev) {
        curr->prev->next = curr->next;
    } else {
        head = curr->next;
    }

    if (curr->next) {
        curr->next->prev = curr->prev;
    } else {
        tail = curr->prev;
    }

    cout << "\nSuccessfully deleted\n";
    cout << "Student: " << curr->name << " (ID: " << curr->id << ")\n";
    delete curr;
    saveToFile(); // Save to file after deletion
}

// Delete a student by their ID
void deleteByID(string id) {
    if (isEmpty()) {
        cout << "\nThe list is empty! you can't delete from an empty record\n";
        return;
    }

    Student* curr = head;
    while (curr) {
        if (curr->id == id) {
            if (curr->prev) {
                curr->prev->next = curr->next;
            } else {
                head = curr->next;
            }

            if (curr->next) {
                curr->next->prev = curr->prev;
            } else {
                tail = curr->prev;
            }

            cout << "\nSuccessfully deleted\n";
            cout << "Student: " << curr->name << " (ID: " << curr->id << ")\n";
            delete curr;
            saveToFile(); // Save to file after deletion
            return;
        }
        curr = curr->next;
    }
    cout << "\nID number " << id << " is not found in the database.\n";
}

// Search for a specific student by ID
void searchByID(string id) {
    if (isEmpty()) {
        cout << "\nThe list is empty! you can't search from an empty record\n";
        return;
    }
    Student* curr = head;
    int position = 1;
    while (curr) {
        if (curr->id == id) {
            cout << "Student: " << curr->name << " with ID " << curr->id << " found at row " << position << ".\n";
            return;
        }
        curr = curr->next;
        position++;
    }
    cout << "ID " << id << " not found in the list.\n";
}

// Display the list from head to tail
void displayForward() {
    if (isEmpty()) {
        cout << "\nThe list is empty! no data to traverse\n";
        return;
    }
    Student* curr = head;
    while (curr) {
        cout << "Name: " << curr->name << ", ID: " << curr->id << "\n";
        curr = curr->next;
    }
    cout << endl;
}

// Display the list from tail to head
void displayBackward() {
    if (isEmpty()) {
        cout << "\nThe list is empty! no data to traverse\n";
        return;
    }
    Student* curr = tail;
    while (curr) {
        cout << "Name: " << curr->name << ", ID: " << curr->id << "\n";
        curr = curr->prev;
    }
    cout << endl;
}

// New function to delete all elements
void deleteAll() {
    if (isEmpty()) {
        cout << "\nThe list is already empty!\n";
        return;
    }
    Student* curr = head;
    while (curr) {
        Student* temp = curr;
        curr = curr->next;
        delete temp;
    }

    head = tail = NULL;
    cout << "All students have been deleted.\n";
    saveToFile(); // Save to file after deletion
}

// Main function
int main() {
    loadFromFile(); // Load data from file if available
    cout << "\n================== WELCOME =======================================\n";
    cout << "Welcome to the Doubly Linked List Student Record Management Program!\n";
    cout << "Perform various operations on a doubly linked list,\n";
    cout << "and your data will persist across runs!\n";
    cout << "====================================================================\n\n";
    int choice;
    string name, id;
    int position;
    do {
        cout << "\n Menu:\n";
        cout << "1. Insert at Start\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete at Start\n";
        cout << "5. Delete at End\n";
        cout << "6. Delete at Position\n";
        cout << "7. Delete by ID Number\n";
        cout << "8. Search by ID Number\n";
        cout << "9. Traverse Forward\n";
        cout << "10. Traverse Backward\n";
        cout << "11. Delete All Students\n";  
        cout << "12. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Inserting at the beginning...\n";
                cout << "Enter your name: ";
                cin >> name;
                cout << "Enter ID: ";
                cin >> id;
                insertAtBeginning(name, id);
                cout << "Inserted successful!\n";
                break;
            case 2:
                cout << "Inserting at the end...\n";
                cout << "Enter your name: ";
                cin >> name;
                cout << "Enter ID: ";
                cin >> id;
                insertAtEnd(name, id);
                cout << "Inserted successful!\n";
                break;
            case 3:
                cout << "Inserting at a specific position...\n";
                cout << "Enter position (1-indexed based): ";
                cin >> position;
                cout << "Enter your name: ";
                cin >> name;
                cout << "Enter ID: ";
                cin >> id;
                insertAtPosition(name, id, position);
                cout << "Inserted successful!\n";
                break;
            case 4:
                deleteAtBeginning(); 
                break;
            case 5:
                deleteAtEnd(); 
                break;
            case 6:
                cout << "Enter position to delete (1-indexed based): ";
                cin >> position;
                deleteAtPosition(position);
                break;
            case 7:
                cout << "Enter ID to delete: ";
                cin >> id;
                deleteByID(id);
                break;
            case 8:
                cout << "Enter ID to search: ";
                cin >> id;
                searchByID(id);
                break;
            case 9:
                cout << "\nForward Traverse: \n";
                displayForward();
                break;
            case 10:
                cout << "\nBackward Traverse: \n";
                displayBackward();
                break;
            case 11:
                deleteAll();  
                break;
            case 12:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 12);

    return 0;
}
