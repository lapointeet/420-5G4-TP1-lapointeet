#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include <memory>

#include "book.h"
#include "user.h"
#include "journal.h"

using namespace std;

class Library {
private:
    vector<unique_ptr<Book>> books;
    vector<unique_ptr<User>> users;
    vector<unique_ptr<Journal>> journals; // Journal of operations

public:
    // Constructor and destructor
    Library();
    ~Library() = default;
    
    // Book management
    void restoreBook(const Book& book);
    void addBook(const Book& book);
    bool removeBook(const string& isbn);
    Book* findBookByISBN(const string& isbn);
    vector<Book*> searchBooksByTitle(const string& title);
    vector<Book*> searchBooksByAuthor(const string& author);
    vector<Book*> getAvailableBooks();
    vector<Book*> getAllBooks();
    
    // User management
    void restoreUser(const User& user);
    void addUser(const User& user);
    User* findUserById(const string& userId);
    vector<User*> getAllUsers();
    
    // Library operations
    bool checkOutBook(const string& isbn, const string& userId);
    bool returnBook(const string& isbn);

    // Journal management
    void restoreJournalEntry(const Journal& journal);
    vector<Journal*> getAllJournals();
    
    // Display methods
    void displayAllBooks();
    void displayAvailableBooks();
    void displayAllUsers();
    void displayJournal();
    
    // Statistics
    int getTotalBooks() const;
    int getAvailableBookCount() const;
    int getCheckedOutBookCount() const;

    // Helper function to get current date as string (YYYY-MM-DD)
    string getCurrentDate() const;
};

#endif
