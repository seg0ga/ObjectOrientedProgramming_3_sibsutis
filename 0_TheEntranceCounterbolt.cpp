#include <iostream>
#include <string>

using namespace std;

struct Premaya{
    double x1;
    double x2;
    double y1;
    double y2;};

void uravnenie(Premaya p){
    double k,b;
    k=(p.y2-p.y1)/(p.x2-p.x1);
    b=p.y1-k*p.x1;
    cout<< "y="<<k<<"x+"<<b<<"\n";}

int main(){
    int k;
    cout<<"Введите количество прямых: ";
    cin>> k;

    Premaya z[20];

    for (int i=0;i<k;i++){
        cout<<"Введите x1: ";
        cin>>z[i].x1;
        cout<<"Введите x2: ";
        cin>>z[i].x2;
        cout<<"Введите y1: ";
        cin>>z[i].y1;
        cout<<"Введите y2: ";
        cin>>z[i].y2;
        cout<<"Уравнение прямой: ";
        uravnenie(z[i]);}}
