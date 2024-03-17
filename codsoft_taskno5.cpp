#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct Book {
    string title;
    string author;
    string ISBN;
    bool available;
};


struct Borrower {
    string name;
    string id;
};

void searchBook(vector<Book>& books, string query) {
    cout << "Search Results:" << endl;
    for (const auto& book : books) {
        if (book.title.find(query) != string::npos ||
            book.author.find(query) != string::npos ||
            book.ISBN.find(query) != string::npos) {
            cout << "Title: " << book.title << endl;
            cout << "Author: " << book.author << endl;
            cout << "ISBN: " << book.ISBN << endl;
            cout << "Available: " << (book.available ? "Yes" : "No") << endl;
            cout << "------------------------" << endl;
        }
    }
}

void checkoutBook(vector<Book>& books, string ISBN) {
    auto it = find_if(books.begin(), books.end(), [ISBN](const Book& book) {
        return book.ISBN == ISBN && book.available;
    });

    if (it != books.end()) {
        it->available = false;
        cout << "Book checked out successfully!" << endl;
    } else {
        cout << "Book not found or unavailable for checkout." << endl;
    }
}

void returnBook(vector<Book>& books, string ISBN) {
    auto it = find_if(books.begin(), books.end(), [ISBN](const Book& book) {
        return book.ISBN == ISBN && !book.available;
    });

    if (it != books.end()) {
        it->available = true;
        cout << "Book returned successfully!" << endl;
    } else {
        cout << "Book not found or already returned." << endl;
    }
}

int main() {
    vector<Book> books = {
        {"Book1", "Author1", "ISBN1", true},
        {"Book2", "Author2", "ISBN2", true},
        {"Book3", "Author3", "ISBN3", false},
    };

    cout << "Welcome to the Library Management System!" << endl;

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Search for a book\n";
        cout << "2. Checkout a book\n";
        cout << "3. Return a book\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string query;
                cout << "Enter title, author, or ISBN to search: ";
                cin.ignore();
                getline(cin, query);
                searchBook(books, query);
                break;
            }
            case 2: {
                string ISBN;
                cout << "Enter the ISBN of the book to checkout: ";
                cin >> ISBN;
                checkoutBook(books, ISBN);
                break;
            }
            case 3: {
                string ISBN;
                cout << "Enter the ISBN of the book to return: ";
                cin >> ISBN;
                returnBook(books, ISBN);
                break;
            }
            case 4:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}