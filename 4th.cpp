#include <iostream>
#include <vector>
#include <string>

using namespace std; // Adding namespace directive

// Include the previously defined Book and Library classes
class Book {
    string title;
    string author;

public:
    Book(string _title, string _author) : title(_title), author(_author) {}

    string getTitle() const { return title; }
    string getAuthor() const { return author; }
};

class Library {
    vector<Book> books;

public:
    void addBook(const Book& book) {
        books.push_back(book);
    }

    void removeBook(const string& title) {
        for (auto it = books.begin(); it != books.end(); ++it) {
            if (it->getTitle() == title) {
                books.erase(it);
                return;
            }
        }
    }

    void listBooks() const {
        cout << "Books in the library:\n";
        for (const auto& book : books) {
            cout << "Title: " << book.getTitle() << ", Author: " << book.getAuthor() << endl;
        }
    }
};

void userInterface(Library& lib) {
    string command;
    string title, author;

    while (true) {
        cout << "Enter command (add, remove, list, quit): ";
        getline(cin, command);

        if (command == "add") {
            cout << "Enter title: ";
            getline(cin, title);
            cout << "Enter author: ";
            getline(cin, author);
            lib.addBook(Book(title, author));
        } else if (command == "remove") {
            cout << "Enter title of the book to remove: ";
            getline(cin, title);
            lib.removeBook(title);
        } else if (command == "list") {
            lib.listBooks();
        } else if (command == "quit") {
            break; // Exit the loop and end the program
        } else {
            cout << "Invalid command. Please try again.\n";
        }
    }
}

int main() {
    Library myLibrary;
    userInterface(myLibrary); // Implement this function
    return 0;
}

