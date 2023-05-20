/*
Solve the problem using Object Oriented Paradigm.
An undergraduate course has 70 classes (14wk x 5d). A student can be present, or
absent in any of the days. Devise a way to keep track of the attendance of a
student.
- The student can be marked present or absent on day n
- The total number of present/absent has to be calculated
- Check if the student is dis-collegiate (<75%)
- Check if the student is non-collegiate (<90% & > 75%)
*/
#include <iostream>
using namespace std;
class AttendanceTracker {
private:
    int presentDays[70];
    int totalDays;
public:
    AttendanceTracker() {
        totalDays = 70;
        for (int i = 0; i < totalDays; i++) {
            presentDays[i] = 0; // 0 represents absence, 1 represents presence
        }
    }
    void markPresent(int day) {
        presentDays[day-1] = 1;
    }
    void markAbsent(int day) {
        presentDays[day-1] = 0;
    }
    int getTotalPresent() {
        int totalPresent = 0;
        for (int i = 0; i < totalDays; i++) {
            if (presentDays[i] == 1) {
                totalPresent++;
            }
        }
        return totalPresent;
    }
    int getTotalAbsent() {
        return totalDays - getTotalPresent();
    }
    bool isDisCollegiate() {
        float attendancePercentage = (getTotalPresent() / (float)totalDays) * 100;
        if (attendancePercentage < 75.0) {
            return true;
        }
        return false;
    }
    bool isNonCollegiate() {
        float attendancePercentage = (getTotalPresent() / (float)totalDays) * 100;
        if (attendancePercentage > 75.0 && attendancePercentage < 90.0) {
            return true;
        }
        return false;
    }
};

int main() {
    AttendanceTracker tracker;
    tracker.markPresent(1);
    tracker.markPresent(2);
    tracker.markAbsent(3);
    tracker.markPresent(4);
    tracker.markPresent(5);
    tracker.markPresent(6);
    tracker.markPresent(7);
    // ... mark attendance for remaining days

    cout << "Total Present: " << tracker.getTotalPresent() << endl;
    cout << "Total Absent: " << tracker.getTotalAbsent() << endl;
    cout << "Is Dis-Collegiate? " << (tracker.isDisCollegiate() ? "Yes" : "No") << endl;
    cout << "Is Non-Collegiate? " << (tracker.isNonCollegiate() ? "Yes" : "No") << endl;

    return 0;
}

