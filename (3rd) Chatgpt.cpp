#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class Book {
private:
    string title;
    string author;
    string isbn;
public:
    Book(const string& _title, const string& _author, const string& _isbn)
        : title(_title), author(_author), isbn(_isbn) {}

    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getISBN() const { return isbn; }

    void printDetails() const {
        cout << title << " by " << author << " (ISBN: " << isbn << ")" << endl;
    }
};

class Library {
private:
    static const int MAX_BOOKS = 100;
    vector<unique_ptr<Book>> books;
public:
    void addBook(const Book& book) {
        if (books.size() < MAX_BOOKS) {
            books.push_back(unique_ptr<Book>(new Book(book))); // using unique_ptr constructor
        } else {
            cout << "Cannot add more books. Library is full." << endl;
        }
    }

    bool removeBook(const string& isbn) {
        for (auto it = books.begin(); it != books.end(); ++it) {
            if ((*it)->getISBN() == isbn) {
                books.erase(it);
                return true;
            }
        }
        return false;
    }

    void listBooks() const {
        if (books.empty()) {
            cout << "The library is empty." << endl;
        } else {
            cout << "Books in the library:" << endl;
            for (const auto& book : books) {
                book->printDetails();
            }
        }
    }
};

int main() {
    Library library;

    Book book1("1984", "George Orwell", "978-0451524935");
    Book book2("To Kill a Mockingbird", "Harper Lee", "978-0061120084");
    Book book3("The Catcher in the Rye", "J.D. Salinger", "978-0316769488");

    library.addBook(book1);
    library.addBook(book2);
    library.addBook(book3);

    library.listBooks();

    library.removeBook("978-0061120084");

    cout << "\nAfter removing a book:" << endl;
    library.listBooks();

    return 0;
}

