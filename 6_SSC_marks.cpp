/*
A Science Student of SSC has a roll number, marks in primary Subjects, and marks
in Science subjects.
A Commerce Student has a roll number, marks in primary subjects, and marks in
Commerce Subjects.
a. Write down two classes with the mentioned properties. (all private)
b. Write necessary public setter functions
c. Write a non-member compare(…) function that will take a science student
object and a commerce student object, and return the roll number of the
student having higher average overall marks.
*/
#include <iostream>
using namespace std;

class ScienceStudent {
private:
    int rollNo;
    int primaryMarks;
    int scienceMarks;
public:
    void setRollNo(int rollNo) {
        this->rollNo = rollNo;
    }
    void setPrimaryMarks(int primaryMarks) {
        this->primaryMarks = primaryMarks;
    }
    void setScienceMarks(int scienceMarks) {
        this->scienceMarks = scienceMarks;
    }
    float getAverageMarks() {
        return (primaryMarks + scienceMarks) / 2.0;
    }
    int getRollNo() {
        return rollNo;
    }
};

class CommerceStudent {
private:
    int rollNo;
    int primaryMarks;
    int commerceMarks;
public:
    void setRollNo(int rollNo) {
        this->rollNo = rollNo;
    }
    void setPrimaryMarks(int primaryMarks) {
        this->primaryMarks = primaryMarks;
    }
    void setCommerceMarks(int commerceMarks) {
        this->commerceMarks = commerceMarks;
    }
    float getAverageMarks() {
        return (primaryMarks + commerceMarks) / 2.0;
    }
    int getRollNo() {
        return rollNo;
    }
};

int compare(ScienceStudent science, CommerceStudent commerce) {
    if (science.getAverageMarks() > commerce.getAverageMarks()) {
        return science.getRollNo();
    } else {
        return commerce.getRollNo();
    }
}

int main() {
    ScienceStudent science;
    CommerceStudent commerce;

    science.setRollNo(101);
    science.setPrimaryMarks(80);
    science.setScienceMarks(90);

    commerce.setRollNo(201);
    commerce.setPrimaryMarks(70);
    commerce.setCommerceMarks(85);

    int rollNo = compare(science, commerce);
    cout << "Student with higher average marks has roll number: " << rollNo << endl;

    return 0;
}
