#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class Quadrangle {
protected:
    double x1,y1,x2,y2,x3,y3,x4,y4;

public:
    Quadrangle(double X1,double Y1,double X2,double Y2,double X3,double Y3,double X4,double Y4):
    x1(X1),y1(Y1),x2(X2),y2(Y2),x3(X3),y3(Y3),x4(X4),y4(Y4){}
        
    double length(double xa, double ya,double xb,double yb)const{
        return sqrt((xb-xa)*(xb-xa)+(yb-ya)*(yb-ya));}

    virtual double perimeter() const {
        return length(x1,y1,x2,y2)+length(x2,y2,x3,y3)+length(x3,y3,x4,y4)+length(x4,y4,x1,y1);}

    virtual double area() const {
        return abs((x1*y2+x2*y3+x3*y4+x4*y1)-(y1*x2+y2*x3+y3*x4+y4*x1))/2.0;}

    virtual void show() const {
        cout<< "Координаты: ("<<x1<<","<<y1<<"), ("<<x2<<","<<y2<<"), ("<<x3<<","<<y3<<"), ("<<x4<<","<<y4<<")" << endl;
        cout<< "Периметр: "<< perimeter() <<endl;
        cout<< "Площадь: "<< area()<<endl;}};

class Parallelogram:public Quadrangle {
private:
    string name;

public:
    Parallelogram(double a,double b,double c,double d,double e,double f,double g,double h,string n=""):Quadrangle(a,b,c,d,e,f,g,h),name(n){}

    string getName()const {return name;}
    void setName(string n){name=n;}

    bool isPara()const{
        double xab=x2-x1,yab=y2-y1;
        double xcd=x4-x3,ycd=y4-y3;
        double xbc=x3-x2,ybc=y3-y2;
        double xda=x1-x4,yda=y1-y4;
        bool ab_parallel_cd =abs(xab*ycd-yab*xcd)<0.0001;
        bool bc_parallel_da =abs(xbc*yda-ybc*xda)<0.0001;
        
        return ab_parallel_cd && bc_parallel_da;}

    void show() const override {
        cout<<"=== "<<name<<" ==="<<endl;
        bool valid_para=isPara();
        cout<<"Является параллелограммом: "<<(valid_para?"ДА":"НЕТ")<<endl;
        
        if (valid_para) {
            Quadrangle::show();
        } else {
            cout<<"Фигура не является параллелограммом"<<endl;
            cout<<"Координаты: ("<<x1<<","<<y1<<"), ("<<x2<<","<<y2<<"), ("<<x3<<","<<y3<<"), ("<<x4<<","<<y4<<")"<< endl;}
        cout << "------------------------" << endl;}};

class Main {
public:
    static void main(){
        int figureCount;
        cout<<"Введите количество четырехугольников: ";
        cin>>figureCount;
        Quadrangle** figures=new Quadrangle*[figureCount];
        for (int i=0;i<figureCount;i++) {
            double x1,y1,x2,y2,x3,y3,x4,y4;
            
            cout<< endl<<"Фигура "<<i+1<<":"<<endl;
            cout<<"Введите координаты четырехугольника:" << endl;
            cout<<"Точка 1 (x y): "; cin>>x1>>y1;
            cout<<"Точка 2 (x y): "; cin>>x2>>y2;
            cout<<"Точка 3 (x y): "; cin>>x3>>y3;
            cout<<"Точка 4 (x y): "; cin>>x4>>y4;
            
            int type;
            cout<< "Выберите тип фигуры (1-четырехугольник,2-парралелограм): ";
            cin>> type;
            
            if (type == 2) {
                string name;
                cout << "Введите название параллелограмма: ";
                cin.ignore();
                getline(cin, name);
                figures[i]=new Parallelogram(x1,y1,x2,y2,x3,y3,x4,y4,name);
            } else {
                figures[i]=new Quadrangle(x1,y1,x2,y2,x3,y3,x4,y4);}}
        
        cout<<endl<<"ВЫВОД ИНФОРМАЦИИ О ФИГУРАХ:"<<endl;
        cout<<"============================"<<endl;
        
        for (int i = 0; i < figureCount; i++) {
            cout << "Фигура " << i + 1 << ":" << endl;
            figures[i]->show();}}};

int main() {
    Main::main();}
