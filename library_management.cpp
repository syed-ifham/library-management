#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct Book {
    int id;
    string title;
    string author;
    bool isIssued;
};

class Library {
private:
    vector<Book> books;
    int nextId;

public:
    Library() : nextId(1) {}

    void addBook() {
        Book newBook;
        newBook.id = nextId++;
        cout << "Enter book title: ";
        cin.ignore();
        getline(cin, newBook.title);
        cout << "Enter author name: ";
        getline(cin, newBook.author);
        newBook.isIssued = false;
        books.push_back(newBook);
        cout << "Book added successfully.\n";
    }

    void displayBooks() {
        if (books.empty()) {
            cout << "No books available.\n";
            return;
        }

        cout << left << setw(5) << "ID" << setw(30) << "Title" << setw(25) << "Author" << "Status" << endl;
        for (const Book& book : books) {
            cout << left << setw(5) << book.id << setw(30) << book.title << setw(25) << book.author << (book.isIssued ? "Issued" : "Available") << endl;
        }
    }

    void issueBook() {
        int id;
        cout << "Enter book ID to issue: ";
        cin >> id;
        for (Book& book : books) {
            if (book.id == id) {
                if (book.isIssued) {
                    cout << "Book already issued.\n";
                    return;
                }
                book.isIssued = true;
                cout << "Book issued successfully.\n";
                return;
            }
        }
        cout << "Book not found.\n";
    }

    void returnBook() {
        int id;
        cout << "Enter book ID to return: ";
        cin >> id;
        for (Book& book : books) {
            if (book.id == id) {
                if (!book.isIssued) {
                    cout << "Book was not issued.\n";
                    return;
                }
                book.isIssued = false;
                cout << "Book returned successfully.\n";
                return;
            }
        }
        cout << "Book not found.\n";
    }
};

int main() {
    Library library;
    int choice;
    while (true) {
        cout << "\n\n------ Library Management System --==\n";
        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Issue Book\n";
        cout << "4. Return Book\n";
        cout << "5. Exit\n";
        cout << "Hit your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: library.addBook(); break;
            case 2: library.displayBooks(); break;
            case 3: library.issueBook(); break;
            case 4: library.returnBook(); break;
            case 5: cout << "Exiting...\n"; return 0;
            default: cout << "Wrong : invalid choice! Try again.\n";
        }
    }
}
