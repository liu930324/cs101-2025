#include <iostream>
#include <string>
using namespace std;

// 基礎汽車類別
class Car {
public:
    string m_brand;
    string m_model;
    int m_year;
    int m_MaxSeating;
    
    // 建構函式
    Car(string x, string y, int z, int s) {
        m_brand = x;
        m_model = y;
        m_year = z;
        m_MaxSeating = s;
    }
    
    // 獲取座位數的方法
    int get_m_MaxSeating() {
        return m_MaxSeating;
    }
};

// BMW汽車類別
class BMW_Car : public Car {
public:
    BMW_Car(string model, int year, int maxSeating) 
        : Car("BMW", model, year, maxSeating) {
        cout << "Constructing BMW_Car" << endl;
        cout << "BMW : Drive Mode = Rear-wheel" << endl;
    }
};

// Audi汽車類別
class AUDI_Car : public Car {
public:
    AUDI_Car(string model, int year, int maxSeating) 
        : Car("Audi", model, year, maxSeating) {
        cout << "Constructing AUDI_Car" << endl;
        cout << "Audi : Drive Mode = Front-wheel" << endl;
    }
};

// Benz汽車類別
class BENZ_Car : public Car {
public:
    BENZ_Car(string model, int year, int maxSeating) 
        : Car("Benz", model, year, maxSeating) {
        cout << "Constructing BENZ_Car" << endl;
        cout << "Benz : Drive Mode = Front-wheel" << endl;
    }
};

int main() {
    // 建立不同品牌的汽車物件，建構函式會直接輸出所需格式的信息
    BMW_Car car_1("X5", 2023, 6);
    AUDI_Car car_2("A1", 2021, 2);
    BENZ_Car car_3("S-Class", 2022, 5);
    
    return 0;
}
