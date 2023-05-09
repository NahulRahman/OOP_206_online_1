/*
Consider the following skeleton for problem a, b and c.
class String
{
int len;
char *ptr;
public: //declare constructor, destructor and copy constructor
char get(int ind)

{
//return the character at the given index
//Check if index is out of bound
//return 0 in case of error
}
int put(int ind,char c)
{
//Assign character c at position index
//Check if index is out of bound
//return -1 in case of error
}
int getlength()
{
//return the allocation length of the string
}
void print()
{
//print the string upto allocation size
}

};
a. Design a String class that will hold the character values dynamically. Use the
above mentioned skeleton. Declare a non-member function, which will
compare the sum of ASCII characters between two strings. If the sum of
ASCII characters of String 1 is greater than String 2, ‘1’ will be printed
whereas, if the sum of ASCII characters of String 2 is greater than String 1,
‘2’ will be printed. However, for the sum of ASCII characters of two strings
being the same, 0 will be printed by the program.
void compare(String s1,String s2)
{
// print 1; if sum of ASCII character of s1 is greater than s2
// print 2; if sum of ASCII character of s2 is greater than s1
// print 0; if sum of ASCII characters of both string being
the same.
}
b. Declare a non-member function of the class of problem 1, which will join 2
strings and will return the resultant string.
String concat(String s1, String s2){
//string s1=”abcd”
//string 2 = “1234”
//result= = “abcd1234”
//Joins two strings s1 and s2 and returns the resultant
string.
}

c. Declare a non-member function of the class of problem 1, which will insert
a particular character at a fixed position of the string and other characters
of the string will be shifted to the right
void insert(String &st, int index, char c) {
//string s1=”abcd”
//insert(s1,0,’k’) //kabc
// Insert char c at index position of st. Shift other characters to
the right.}
*/

#include <iostream>
#include <cstring>

using namespace std;

class String {
    public:
    int len;
    char *ptr;
    // constructor
    String() {
        len = 0;
        ptr = new char[len+1];
        ptr[0] = '\0';
    }

    // parameterized constructor
    String(const char *s) {
        len = strlen(s);
        ptr = new char[len+1];
        strcpy(ptr, s);
    }

    // destructor
    ~String() {
        delete[] ptr;
    }

    // copy constructor
    String(const String &s) {
        len = s.len;
        ptr = new char[len+1];
        strcpy(ptr, s.ptr);
    }

    // get character at index
    char get(int ind) {
        if (ind < 0 || ind >= len) {
            return 0;
        }
        return ptr[ind];
    }

    // put character at index
    int put(int ind, char c) {
        if (ind < 0 || ind >= len) {
            return -1;
        }
        ptr[ind] = c;
        return 0;
    }

    // get length of string
    int getlength() {
        return len;
    }

    // print string
    void print() {
        cout << ptr << endl;
    }
};

// compare two strings by sum of ASCII characters
void compare(String s1, String s2) {
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < s1.getlength(); i++) {
        sum1 += (int)s1.get(i);
    }
    for (int i = 0; i < s2.getlength(); i++) {
        sum2 += (int)s2.get(i);
    }
    if (sum1 > sum2) {
        cout << "1" << endl;
    } else if (sum2 > sum1) {
        cout << "2" << endl;
    } else {
        cout << "0" << endl;
    }
}

// concatenate two strings
String concat(String s1, String s2) {
    int len1 = s1.getlength();
    int len2 = s2.getlength();
    char *newptr = new char[len1+len2+1];
    strcpy(newptr, s1.ptr);
    strcat(newptr, s2.ptr);
    String result(newptr);
    delete[] newptr;
    return result;
}

// insert character at a fixed position in string
void insert_(String &st, int index, char c) {
    int len = st.getlength();
    char *newptr = new char[len+2];
    for (int i = 0; i <= len; i++) {
        if (i < index) {
            newptr[i] = st.get(i);
        } else if (i == index) {
            newptr[i] = c;
        } else {
            newptr[i] = st.get(i-1);
        }
    }
    st = String(newptr);
    delete[] newptr;
}

int main() {
    // testing String class and non-member functions
    String s1("hello");
    String s2("world");
    String s3 = concat(s1, s2);
    s3.print();
    compare(s1, s2);
    insert_(s3, 5, '-');
    s3.print();
    return 0;
}
