#include <sstream>
#include <algorithm>

#include "journal.h"
#include "book.h"

using namespace std;

Journal::Journal() : date(""), type(""), book(nullptr) {}

Journal::Journal(const string& date, const string& type, Book* book) 
    : date(date), type(type), book(book) {}

string Journal::getDate() const { return date; }
string Journal::getType() const { return type; }
Book* Journal::getBook() const { return book; }

void Journal::setDate(const string& date) { this->date = date; }
void Journal::setType(const string& type) { this->type = type; }
void Journal::setBook(Book* book) { this->book = book; }

string Journal::toString() const {
    string result = date + " - [" + type + "] - ";
    if (book) {
        result += book->getTitle() + " par " + book->getAuthor();
    }
    return result;
}

string Journal::toFileFormat() const {
    string result = date + "|" + type;
    if (book) {
        result += "|" + book->toFileFormat();
    }
    return result;
}

void Journal::fromFileFormat(const string& line) {
    istringstream iss(line);
    string bookData;

    getline(iss, date, '|');
    getline(iss, type, '|');
    if (getline(iss, bookData)) {
        book = new Book();
        book->fromFileFormat(bookData);
    } else {
        book = nullptr;
    }
}
