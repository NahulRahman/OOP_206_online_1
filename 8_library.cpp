/*
Solve the problem using Object Oriented Paradigm.
A library has some books on Data Structure and some books on Algorithms.
- Books can be issued (taken from library)
- Books can be returned (to the library)
- If book-count falls below 2, a warning is shown
- If book-count is zero, it cannot be issued from the library
*/
#include <iostream>
#include <string>
using namespace std;
class Book {
    private:
        string title;
        int bookCount;

    public:
        Book(string title, int bookCount): title(title), bookCount(bookCount) {}

        void issue() {
            if (bookCount > 0) {
                bookCount--;
                if (bookCount < 2) {
                    cout << "Warning: Only " << bookCount << " copies of " << title << " left." << endl;
                }
                cout << "Issued " << title << "." << endl;
            }
            else {
                cout << "Sorry, " << title << " is not available." << endl;
            }
        }

        void returnBook() {
            bookCount++;
            cout << "Returned " << title << "." << endl;
        }
};

int main() {
    Book dsBook("Data Structures", 3);
    Book algoBook("Algorithms", 1);

    dsBook.issue();
    dsBook.issue();
    algoBook.issue();
    dsBook.issue();
    dsBook.returnBook();
    dsBook.issue();
    dsBook.issue();
    dsBook.issue();

    return 0;
}
