#include <iostream>
#include <string>
using namespace std;

class Car {
public:
    string m_brand;
    string m_model;
    int m_year;
    int m_MaxSeating;
    int m_price;
    string m_DriveMode;

    Car(string x, string y, int z, int s, string t)
        : m_brand(x), m_model(y), m_year(z), m_MaxSeating(s), m_DriveMode(t) {
        m_price = m_MaxSeating * 50000;
        info_print();
    }

    int get_m_MaxSeating() {
        return m_MaxSeating;
    }

    int get_m_price() {
        return m_price;
    }

    string get_m_DriveMode() {
        return m_DriveMode;
    }

    void info_print() {
        cout << "Constructing " << m_brand << "_Car" << endl;
        cout << m_brand << " : Drive Mode = " << m_DriveMode << endl;
    }
};

class BMW_Car : public Car {
public:
    BMW_Car(string model, int year, int maxSeating, string driveMode)
        : Car("BMW", model, year, maxSeating, driveMode) {}
};

class AUDI_Car : public Car {
public:
    AUDI_Car(string model, int year, int maxSeating, string driveMode)
        : Car("Audi", model, year, maxSeating, driveMode) {}
};

class BENZ_Car : public Car {
public:
    BENZ_Car(string model, int year, int maxSeating, string driveMode)
        : Car("Benz", model, year, maxSeating, driveMode) {}
};

int main() {
    BMW_Car car_1("X5", 2023, 6, "Rear-wheel");
    AUDI_Car car_2("A1", 2021, 2, "Front-wheel");
    BENZ_Car car_3("S-Class", 2022, 5, "Front-wheel");

    return 0;
}
