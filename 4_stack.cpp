/*
In this problem, you’ll need to design a Stack class that will hold the integer values
dynamically. Use the following skeleton of Stack class.
class Stack
{
int *p; int len;
public:
Stack(int n);//n = size of the stack
~Stack(){delete [ ]p;}
initStack(int *ara)//init the stack with the values of ara
printStack()//print the values of stack
...//Write more methods if necessary
};
void printSum(Stack s)//non-member function, prints the sum of
elements of s.
*/
#include <iostream>

using namespace std;

class Stack {
    int *p;
    int len;
public:
    Stack(int n) {
        p = new int[n];
        len = n;
    }

    void initStack(int *ara) {
        for (int i = 0; i < len; i++) {
            p[i] = ara[i];
        }
    }

    void printStack() {
        for (int i = 0; i < len; i++) {
            cout << p[i] << " ";
        }
        cout << endl;
    }
    void printSum(Stack s) {
    int sum = 0;
    for (int i = 0; i < s.len; i++) {
        sum += s.p[i];
    }
    cout << "Sum of stack elements: " << sum << endl;
}


    ~Stack() {
        delete[] p;
    }
};


int main() {
    int ara[] = {1, 2, 3, 4, 5};
    int n = sizeof(ara) / sizeof(ara[0]);

    Stack s(n);
    s.initStack(ara);
    s.printStack();
    s.printSum(s);

    return 0;
}
