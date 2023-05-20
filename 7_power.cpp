/*
Solve the problem using Object Oriented Paradigm.
Given an integer n, find the value of
a. 1 + 2 + 3 + … … … + n
b. 1^2 + 2^2 + 3^2 + … … … + n^2
c. 1^3 + 2^3 + 3^3 + … … … + n^3
*/
#include <iostream>
using namespace std;

class Summation {
private:
    int n;
public:
    Summation(int n) {
        this->n = n;
    }
    int sum() {
        int s = 0;
        for (int i = 1; i <= n; i++) {
            s += i;
        }
        return s;
    }
    int sumSquares() {
        int s = 0;
        for (int i = 1; i <= n; i++) {
            s += i * i;
        }
        return s;
    }
    int sumCubes() {
        int s = 0;
        for (int i = 1; i <= n; i++) {
            s += i * i * i;
        }
        return s;
    }
};

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    Summation s(n);
    cout << "Summation of 1 to n: " << s.sum() << endl;
    cout << "Summation of squares of 1 to n: " << s.sumSquares() << endl;
    cout << "Summation of cubes of 1 to n: " << s.sumCubes() << endl;
    return 0;
}
