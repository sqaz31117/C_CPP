#include <iostream>
#include <string>

using namespace std;

template<class T1, class T2, class T3> 
class Car {
    public:
        Car(T1 brand, T2 type, T3 hp) {
            this->brand = brand;
            this->type = type;
            this->hp = hp;
        }

        ~Car() {
            cout << "goodbye " << brand << " " << type << endl;
        }

        void getInfo() {
            cout << brand << " " << type << " " << hp << endl;
        }
    protected:
        T1 brand;
        T2 type;
        T3 hp;
};

template<class T1, class T2, class T3, class T4>
class Taxi:public Car<T1, T2, T3> {
    public:
        // overloading
        // 相同類別中，定一名稱相同，但是參數個數不同，可以利用參數個數或是型態互叫不同的方法
        Taxi(T1 brand, T2 type, T3 hp) : Car<string, string, int>(brand, type, hp) {}
        Taxi(T1 brand, T2 type, T3 hp, T4 driverName) : Car<string, string, int>(brand, type, hp), driverName(driverName) {}

        void setDriverName(T4 driverName) {
            this->driverName = driverName;
        }

        // override
        void getInfo() {
            cout << this->brand << " " << this->type << " " << this->hp << " " << driverName << endl;
        }
    private:
        T4 driverName;
};

int main() {
    Car<string, string, int>* BMW = new Car<string, string, int>("BMW", "X5", 340);
    BMW->getInfo();
    
    Taxi<string, string, int, string>* driver1 = new Taxi<string, string, int, string>("Toyota", "Altis", 100);
    driver1->setDriverName("driver1");
    driver1->getInfo();

    Taxi<string, string, int, string>* driver2 = new Taxi<string, string, int, string>("Toyota", "Altis", 100, "driver2");
    driver2->getInfo();

    delete BMW;
    delete driver1;
    delete driver2;
}