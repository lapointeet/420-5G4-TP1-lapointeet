#ifndef JOURNAL_H
#define JOURNAL_H

#include <string>

using namespace std;

class Book;

class Journal {
    private:
        string date;
        string type;
        Book* book;

    public:
        Journal();
        Journal(const string& date, const string& type, Book* book);

        // Getters
        string getDate() const;
        string getType() const;
        Book* getBook() const;

        // Setters
        void setDate(const string& date);
        void setType(const string& type);
        void setBook(Book* book);

        // Methods
        string toString() const;
        string toFileFormat() const;
        void fromFileFormat(const string& line);
};

#endif