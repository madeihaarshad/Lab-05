#include <iostream>
#include <string>
#include <vector>

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
  vector<Book> books; // Use vector for dynamic resizing and automatic memory management

public:
  Library() {}

  void addBook(const Book& book) {
    books.push_back(book); // Add book to the vector
  }

  bool removeBook(const string& isbn) {
    for (size_t i = 0; i < books.size(); ++i) {
      if (books[i].getISBN() == isbn) {
        books.erase(books.begin() + i); // Erase element from vector
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
      for (const Book& book : books) {
        book.printDetails();
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

