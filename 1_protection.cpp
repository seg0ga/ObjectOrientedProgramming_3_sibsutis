#include <iostream>
#include <string>
using namespace std;

class Triangle {
private:
    double a;
    double b;
    double c;

public:
    Triangle(){
        a= 1.0;
        b= 1.0;
        c= 1.0;}

    Triangle(double A, double B, double C) {
        a=A;
        b=B;
        c=C;}

    bool ravno() {
        return (a == b)&&(b == c);}

    bool pryam() {
        if (a*a+b*b==c*c) return true;
        if (a*a+c*c==b*b) return true;
        if (b*b+c*c==a*a) return true;
        return false;}

    double getA(){return a;}
    double getB(){return b;}
    double getC(){return c;}

    void setA(double A){a=A;}
    void setB(double B){b=B;}
    void setC(double C){c=C;}

    void outputInfo() {
        cout<<"Треугольник со сторонами: "<<a<<", "<<b<<", "<<c<< endl;
        
        if (ravno()){cout << "Равносторонний: да"<< endl;} 
        else {cout<<"Равносторонний: нет"<< endl;}
        
        if (pryam()){cout << "Прямоугольный: да" << endl;}
        else {cout << "Прямоугольный: нет" << endl;}
        cout << "________________________" << endl;}};

int main() {
    int N;
    cout<< "Введи количество треугольников: ";
    cin>> N;
    
    Triangle triangles[N];
    int k1 = 0;
    int k2 = 0;

    for (int i = 0; i < N; i++) {
        cout<< "\nТреугольник "<<i+1<< ":" << endl;
        double a, b, c;
        cout << "Введите сторону a: ";
        cin >> a;
        cout << "Введите сторону b: ";
        cin >> b;
        cout << "Введите сторону c: ";
        cin >> c;
        triangles[i] = Triangle(a, b, c);}

    cout<<"\nВСЕ ТРЕУГОЛЬНИКИ:" << endl;
    for (int i = 0; i < N; i++) {
        triangles[i].outputInfo();
        if (triangles[i].ravno()){k1++;}
        if (triangles[i].pryam()){k2++;}}

    cout << "РЕЗУЛЬТАТЫ:" << endl;
    cout << "Количество равносторонних треугольников (k1): " << k1 << endl;
    cout << "Количество прямоугольных треугольников (k2): " << k2 << endl;}
