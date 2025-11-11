#include <iostream>
#include <string>
#include <list>
using namespace std;

class parkovka{
public:
    string nomer_avto;
    int nomer_mesta;
    
    parkovka(string a,int m){nomer_avto=a;nomer_mesta=m;}
    
    void display(){cout<<"Место "<<nomer_mesta<<": "<<nomer_avto<<endl;}};

int main(){
    list<parkovka> zaparkovannie;
    int kolvo=5;
    
    cout<<"ПАРКОВКА"<<endl;
    int vibor;
    
    while (true){
        cout<<"\n1. Поставить машину"<<endl;
        cout<<"2. Убрать машину"<<endl;
        cout<<"3. Вывести все места"<<endl;
        cout<<"4. Выход"<<endl;
        cout<<"Выберите действие: ";
        cin>>vibor;
        cin.ignore();
        
        switch (vibor){
            case 1:{
                string nomer;
                cout<<"Введите номер машины: ";getline(cin,nomer);
                
                if (zaparkovannie.size()>=kolvo){cout<<"Нет свободных мест! Машина "<<nomer<<" не может припарковаться"<<endl;break;}
                
                bool uzhe_est=false;
                for (parkovka car:zaparkovannie){
                    if (car.nomer_avto==nomer){uzhe_est=true;break;}}
                
                if (uzhe_est){
                    cout<<"Машина "<<nomer<<" уже на стоянке!"<<endl;}
                else{
                    int svobodnoe_mesto=-1;
                    
                    for (int mesto=1;mesto<=kolvo;mesto++){
                        bool zanyato=false;
                        for (parkovka car:zaparkovannie){
                            if (car.nomer_mesta==mesto){zanyato=true;break;}}
                        
                        if (!zanyato){svobodnoe_mesto=mesto;break;}}
                    
                    parkovka novaya_mashina(nomer, svobodnoe_mesto);
                    zaparkovannie.push_back(novaya_mashina);
                    cout<<"Машина "<<nomer<<" заняла место №"<<svobodnoe_mesto<<endl;}break;}
            
            case 2:{
                string nomer;
                cout<<"Введите номер машины: ";getline(cin,nomer);
                
                bool mashina_naydena=false;
                list<parkovka> noviy_spisok;
                
                for (parkovka car:zaparkovannie){
                    if (car.nomer_avto==nomer){
                        cout<<"Машина "<<nomer<<" уехала с места №"<<car.nomer_mesta<<endl;
                        mashina_naydena=true;}
                    else{noviy_spisok.push_back(car);}}
                
                zaparkovannie = noviy_spisok;
                
                if (!mashina_naydena){cout<<"Машина "<<nomer<<" не найдена"<<endl;}break;}
            
            case 3:{
                cout<<"\nСОСТОЯНИЕ СТОЯНКИ"<<endl;
                for (int mesto=1;mesto<=kolvo;mesto++){
                    bool zanyato=false;
                    for (parkovka car:zaparkovannie){
                        if (car.nomer_mesta==mesto){
                            cout<<"Место "<<mesto<<": "<<car.nomer_avto<<endl;
                            zanyato=true;
                            break;}}
                    if (!zanyato){cout<<"Место "<<mesto<<": свободно"<<endl;}}break;}
            
            case 4:return 0;
            default:{cout<<"Неверный выбор!"<<endl;break;}}}}
