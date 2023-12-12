#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string author;
    string title;
    string publisher;
    double price;
    int quantity;

public:
    Book(string a="", string t="", string p="", double pr=0.0, int q=0) {
        author = a;
        title = t;
        publisher = p;
        price = pr;
        quantity = q;
    }

    string getAuthor() { return author; }
    string getTitle() { return title; }
    string getPublisher() { return publisher; }
    double getPrice() { return price; }
    int getQuantity() { return quantity; }

    void display() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Publisher: " << publisher << endl;
        cout << "Price: $" << price << endl;
        cout << "Quantity: " << quantity << endl << endl;
    }
};

class BookStore {
private:
    Book *books;
    int numBooks;

public:
    BookStore() {
        books = NULL;
        numBooks = 0;
    }

    ~BookStore() {
        if (books != NULL) {
            delete[] books;
        }
    }

    void addBook(string a, string t, string p, double pr, int q) {
        Book *temp = new Book[numBooks + 1];
        for (int i = 0; i < numBooks; i++) {
            temp[i] = books[i];
        }
        temp[numBooks] = Book(a, t, p, pr, q);
        numBooks++;
        delete[] books;
        books = temp;
        cout << "Book added successfully." << endl;
    }

    void displayAllBooks() {
        if (numBooks == 0) {
            cout << "No books available." << endl;
        }
        else {
            for (int i = 0; i < numBooks; i++) {
                books[i].display();
            }
        }
    }

    void searchBooks(string t="", string a="") {
        bool found = false;
        for (int i = 0; i < numBooks; i++) {
            if ((t != "" && books[i].getTitle() == t) || (a != "" && books[i].getAuthor() == a)) {
                found = true;
                books[i].display();
            }
        }
        if (!found) {
            cout << "Book not found." << endl;
        }
    }
};

int main() {
    BookStore myStore;
    int choice = 0;
    while (choice != 4) {
        cout << "Enter your choice:" << endl;
        cout << "1. Add a book" << endl;
        cout << "2. Display all books" << endl;
        cout << "3. Search for a book" << endl;
        cout << "4. Quit" << endl;
        cin >> choice;
        
        if (choice == 1) {
            string author, title, publisher;
            double price;
            int quantity;
            cout << "Enter author name: ";
            cin.ignore();
            getline(cin, author);
            cout << "Enter title: ";
            getline(cin, title);
            cout << "Enter publisher: ";
            getline(cin, publisher);
            cout << "Enter price: ";
            cin >> price;
            cout << "Enter quantity: ";
            cin >> quantity;
            myStore.addBook(author, title, publisher, price, quantity);
        }
    }
}
