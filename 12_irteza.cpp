/*
Irteza likes to travel many places. Sometimes for efficient travelling he needs to
travel in minimum time or minimum cost. Naturally, he travels by BUS or TRAIN. So,
now you have to help him to find out which vehicle satisfies his requirement for
efficient travelling.
a. Write down two classes that represents a BUS and a TRAIN successively (all
the attributes will be private)
b. Each class will have two attributes
i. Velocity
ii. Cost per Kilometer
c. Write a function in each class to set the values.
d. Write one non-member function time(....) that will calculate the time
needed for each vehicle and compare them for finding the efficient vehicle.
e. Write a non-member function cost(...) that will calculate the cost for each
vehicle and compare them for finding the efficient vehicle.
*/
#include <iostream>

using namespace std;

class Bus {
private:
    double velocity; // km/h
    double costPerKm; // $
public:
    void setVelocity(double v) {
        velocity = v;
    }
    void setCostPerKm(double c) {
        costPerKm = c;
    }
    double getTime(double distance) const {
        return distance / velocity; // in hours
    }
    double getCost(double distance) const {
        return distance * costPerKm; // in dollars
    }
};

class Train {
private:
    double velocity; // km/h
    double costPerKm; // $
public:
    void setVelocity(double v) {
        velocity = v;
    }
    void setCostPerKm(double c) {
        costPerKm = c;
    }
    double getTime(double distance) const {
        return distance / velocity; // in hours
    }
    double getCost(double distance) const {
        return distance * costPerKm; // in dollars
    }
};

string time(const Bus& b, const Train& t, double distance) {
    double busTime = b.getTime(distance);
    double trainTime = t.getTime(distance);
    if (busTime < trainTime) {
        return "Bus is faster";
    } else if (trainTime < busTime) {
        return "Train is faster";
    } else {
        return "Both are equally fast";
    }
}

string cost(const Bus& b, const Train& t, double distance) {
    double busCost = b.getCost(distance);
    double trainCost = t.getCost(distance);
    if (busCost < trainCost) {
        return "Bus is cheaper";
    } else if (trainCost < busCost) {
        return "Train is cheaper";
    } else {
        return "Both cost the same";
    }
}

int main() {
    Bus b;
    b.setVelocity(80.0); // km/h
    b.setCostPerKm(0.5); // $
    Train t;
    t.setVelocity(120.0); // km/h
    t.setCostPerKm(0.7); // $
    double distance = 500.0; // km
    cout << time(b, t, distance) << endl;
    cout << cost(b, t, distance) << endl;
    return 0;
}

