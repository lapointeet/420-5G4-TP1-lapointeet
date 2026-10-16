#include <sstream>
#include <algorithm>

#include "book.h"
#include "library.h"

using namespace std;

// Default constructor
Book::Book() : title(""), author(""), isbn("") {}

// Parameterized constructor
Book::Book(const string& title, const string& author, const string& isbn) 
    : title(title), author(author), isbn(isbn) {}

// Getters
string Book::getTitle() const { return title; }
string Book::getAuthor() const { return author; }
string Book::getISBN() const { return isbn; }
bool Book::getAvailability() const { return isAvailable; }
string Book::getBorrowerId() const { return borrowerId; }

// Setters
void Book::setTitle(const string& title) { this->title = title; }
void Book::setAuthor(const string& author) { this->author = author; }
void Book::setISBN(const string& isbn) { this->isbn = isbn; }
void Book::setAvailability(bool isAvailable) { this->isAvailable = isAvailable; }
void Book::setBorrowerId(const string& borrowerId) { this->borrowerId = borrowerId; }

// Checkout a book
void Book::checkOut(const string& borrowerId){
    if (isAvailable){
        setBorrowerId(borrowerId);
        setAvailability(false);
    }
}

// Return a book
void Book::returnBook(){
    if (!isAvailable){
        setAvailability(true);
    }
    if (!borrowerId.empty()){
        setBorrowerId("");
    }
}

// Display book information
string Book::toString(Library& library) const {
    string result = title + " par " + author;

    if (!isAvailable) {
        User* user = library.findUserById(borrowerId);
        result += " | EMPRUNTÉ PAR : "
            + (user ? user->getName() : borrowerId);
    }

    return result;
}

// Format for file storage
string Book::toFileFormat() const {
    string result = title + "|" + author + "|" + isbn + "|";

    if (isAvailable){
        result += "1|";
    } else {
        result += "0|" + borrowerId;
    }

    return result;
}

// Parse from file format
void Book::fromFileFormat(const string& line) {
    stringstream ss(line);
    string token;

    getline(ss, title, '|');
    getline(ss, author, '|');
    getline(ss, isbn, '|');

    string available;
    getline(ss, available, '|');

    if (!available.empty()){
        if (available == "0"){
            setAvailability(false);
            getline(ss, borrowerId, '|');
        } else {
            setAvailability(true);
            setBorrowerId("");
        }
    }
}