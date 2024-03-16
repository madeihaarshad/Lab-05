#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Book {
private:
    string title;
    string author;
    int publicationYear;

public:
    Book(const string& _title, const string& _author, int _publicationYear)
        : title(_title), author(_author), publicationYear(_publicationYear) {}

    // Getters and setters for attributes
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    int getPublicationYear() const { return publicationYear; }

    void setTitle(const string& _title) { title = _title; }
    void setAuthor(const string& _author) { author = _author; }
    void setPublicationYear(int _publicationYear) { publicationYear = _publicationYear; }
};

class Library {
private:
    vector<Book> books;

public:
    // Method to add a book to the library
    void addBook(const Book& book) {
        books.push_back(book);
    }

    // Method to remove a book from the library by title
    void removeBook(const string& title) {
        for (auto it = books.begin(); it != books.end(); ++it) {
            if (it->getTitle() == title) {
                books.erase(it);
                return; // Assuming each book has a unique title
            }
        }
    }

    // Method to list all books in the library
    void listBooks() const {
        cout << "Library Inventory:" << endl;
        cout << "==============================" << endl;
        for (const auto& book : books) {
            cout << "Title: " << book.getTitle() << ", Author: " << book.getAuthor() << ", Publication Year: " << book.getPublicationYear() << endl;
        }
        cout << "==============================" << endl;
    }
};

int main() {
    
    Library library;

    Book book1("The Great Gatsby", "F. Scott Fitzgerald", 1925);
    Book book2("To Kill a Mockingbird", "Harper Lee", 1960);

    library.addBook(book1);
    library.addBook(book2);

    cout << "List of books in the library:" << endl;
    library.listBooks();

    cout << endl << "Removing book: The Great Gatsby" << endl;
    library.removeBook("The Great Gatsby");

    cout << endl << "List of books in the library after removal:" << endl;
    library.listBooks();

    return 0;
}

