/*
Problem based on namespace:
We all know about the built in function strlen(strg1). It determines the length of a
particular string strg1 (with spaces). Now you have to make your own function
int func(strg1) in a class that will find the length of a string without the
spaces.
Example:
Input: My name is x.
Built in function Output: 13
Own function Output: 10
*/
#include <iostream>
#include <string>
using namespace std;
namespace StringOperations {
    int strlenWithoutSpaces(const std::string& str) {
        int length = 0;
        for (char c : str) {
            if (c != ' ') {
                length++;
            }
        }
        return length;
    }
}

int main() {
    string str = "i'm dead inside";
    int builtInLength = str.length();
    int customLength = StringOperations::strlenWithoutSpaces(str);
    cout << "Built-in function output: " << builtInLength << endl;
    cout << "Custom function output: " << customLength << endl;
    return 0;
}

