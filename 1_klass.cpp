#include <iostream>
#include <string>
using namespace std;

class Manufacturer {
    private:
    string country;
    string type;
    int year;
    string segment;

public:
Manufacturer(string c, string e, int y, string m) {
    country = c;
    type = e;
    year = y;
    segment = m;}

    string getCountry() { return country; }
    string getType() { return type; }
    int getYear() { return year; }
    string getSegment() { return segment; }

    void setCountry(string c) { country = c; }
    void setType(string e) { type = e; }
    void setYear(int y) { year = y; }
    void setSegment(string m) { segment = m; }

    void outputInfo() {
        cout<< "Страна: " << country << endl;
        cout<< "Тип оборудования: " << type << endl;
        cout<< "Год основания: " << year << endl;
        cout<< "Рыночный сегмент: " << segment << endl;
        cout<< "-----------------------------" << endl;}};

int main() {
    Manufacturer bosch("Германия", "Промышленные станки", 1886, "Премиум");
    Manufacturer toyota("Япония", "Автомобили", 1937, "Средний");
    Manufacturer cisco("США","Сетевое оборудование",1984,"Средний");

    cout << "ПЕРВОНАЧАЛЬНЫЕ ДАННЫЕ:" << endl;
    bosch.outputInfo();
    toyota.outputInfo();
    cisco.outputInfo();

    bosch.setSegment("Люкс");
    bosch.setYear(2024);

    cout<< "ПОСЛЕ ИЗМЕНЕНИЙ:" << endl;
    bosch.outputInfo();
    toyota.outputInfo();
    cisco.outputInfo();

    cout<< "Года основания" << endl;
    cout << "Bosch: "<<bosch.getYear()<< endl;
    cout<<"toyota: "<<toyota.getYear()<<endl;
    cout<< "cisco: "<<cisco.getYear()<<endl;
}
