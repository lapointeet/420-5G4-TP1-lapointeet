#include <fstream>
#include <iostream>
#include <filesystem>
#include "filemanager.h"

using namespace std;

// Constructor
FileManager::FileManager(const string& booksFile, const string& usersFile, const string& journalFile)
    : booksFileName(booksFile), usersFileName(usersFile), journalFileName(journalFile) {}

// Save all library data
bool FileManager::saveLibraryData(Library& library) {
    return saveBooksToFile(library) && saveUsersToFile(library) && saveJournalToFile(library);
}

// Load all library data
bool FileManager::loadLibraryData(Library& library) {
    bool booksLoaded = loadBooksFromFile(library);
    bool usersLoaded = loadUsersFromFile(library);
    bool journalLoaded = loadJournalData(library);
    return booksLoaded || usersLoaded || journalLoaded; // Return true if at least one file was loaded
}

// Save books to file
bool FileManager::saveBooksToFile(Library& library) {
    ofstream file(booksFileName);
    if (!file.is_open()) {
        cout << "Erreur : Impossible d'ouvrir " << booksFileName << " en écriture.\n";
        return false;
    }
    
    auto books = library.getAllBooks();
    for (Book* book : books) {
        file << book->toFileFormat() << "\n";
    }
    
    file.close();
    return true;
}

// Save users to file
bool FileManager::saveUsersToFile(Library& library) {
    ofstream file(usersFileName);
    if (!file.is_open()) {
        cout << "Erreur : Impossible d'ouvrir " << usersFileName << " en écriture.\n";
        return false;
    }
    
    auto users = library.getAllUsers();
    for (User* user : users) {
        file << user->toFileFormat() << "\n";
    }
    
    file.close();
    return true;
}

// Save journal to file
bool FileManager::saveJournalToFile(Library& library) {
    ofstream file(journalFileName);
    if (!file.is_open()) {
        cout << "Erreur : Impossible d'ouvrir " << journalFileName << " en écriture.\n";
        return false;
    }

    auto journals = library.getAllJournals();
    for (const auto& journal : journals) {
        file << journal->toFileFormat() << "\n";
    }

    file.close();
    return true;
}

// Load books from file
bool FileManager::loadBooksFromFile(Library& library) {
    if (booksFileName.empty()) {
        cerr << "Erreur : le chemin du fichier de livres est vide.\n";
        return false;
    }
    ifstream file(booksFileName);
    if (!file.is_open()) {
        cout << "Aucun fichier de livres existant trouvé. Démarrage avec une bibliothèque vide.\n";
        return false;
    }
    
    string line;
    int count = 0;
    while (getline(file, line)) {
        if (!line.empty()) {
            Book book;
            book.fromFileFormat(line);
            library.restoreBook(book);
            count++;
        }
    }
    
    file.close();
    cout << "Chargé " << count << " livre(s) depuis le fichier.\n";
    return true;
}

// Load users from file
bool FileManager::loadUsersFromFile(Library& library) {
    if (usersFileName.empty()) {
        cerr << "Erreur : le chemin du fichier d'utilisateurs est vide.\n";
        return false;
    }
    ifstream file(usersFileName);
    if (!file.is_open()) {
        cout << "Aucun fichier d'utilisateurs existant trouvé. Démarrage sans utilisateurs enregistrés.\n";
        return false;
    }
    
    string line;
    int count = 0;
    while (getline(file, line)) {
        if (!line.empty()) {
            User user;
            user.fromFileFormat(line);
            library.restoreUser(user);
            count++;
        }
    }
    
    file.close();
    cout << "Chargé " << count << " utilisateur(s) depuis le fichier.\n";
    return true;
}

// Load journal data from file
bool FileManager::loadJournalData(Library& library) {
    if (journalFileName.empty()) {
        cerr << "Erreur : le chemin du fichier de journal est vide.\n";
        return false;
    }
    ifstream file(journalFileName);
    if (!file.is_open()) {
        cout << "Aucun fichier de journal existant trouvé. Démarrage avec un journal vide.\n";
        return false;
    }

    string line;
    int count = 0;
    while (getline(file, line)) {
        if (!line.empty()) {
            Journal journal;
            journal.fromFileFormat(line);
            library.restoreJournalEntry(journal);
            count++;
        }
    }

    file.close();
    cout << "Chargé " << count << " entrée(s) de journal depuis le fichier.\n";
    return true;
}

// Check if file exists
bool FileManager::fileExists(const string& filename) {
    ifstream file(filename);
    return file.good();
}

// Create backup
void FileManager::createBackup() {
    if (fileExists(booksFileName)) {
        filesystem::copy_file(booksFileName, booksFileName + ".backup");
    }
    
    if (fileExists(usersFileName)) {
        filesystem::copy_file(usersFileName, usersFileName + ".backup");
    }
    
    cout << "Fichiers de sauvegarde créés.\n";
}