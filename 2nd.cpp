#include <iostream>
#include <string>

using namespace std;

class Book {
private:
    string title;
    string author;
    string isbn;
public:
    Book(string _title, string _author, string _isbn)
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
    Book* books[MAX_BOOKS];
    int numBooks;
public:
    Library() : numBooks(0) {}

    void addBook(const Book& book) {
        if (numBooks < MAX_BOOKS) {
            books[numBooks] = new Book(book);
            numBooks++;
        } else {
            cout << "Cannot add more books. Library is full." << endl;
        }
    }

    bool removeBook(const string& isbn) {
        for (int i = 0; i < numBooks; ++i) {
            if (books[i]->getISBN() == isbn) {
                delete books[i];
                books[i] = books[numBooks - 1];
                numBooks--;
                return true;
            }
        }
        return false;
    }

    void listBooks() const {
        if (numBooks == 0) {
            cout << "The library is empty." << endl;
        } else {
            cout << "Books in the library:" << endl;
            for (int i = 0; i < numBooks; ++i) {
                books[i]->printDetails();
            }
        }
    }

    ~Library() {
        for (int i = 0; i < numBooks; ++i) {
            delete books[i];
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
