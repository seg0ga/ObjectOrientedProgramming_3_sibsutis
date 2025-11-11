#include <iostream>
#include <string>
#include <list>

using namespace std;

class Abonent {
public:
    string phone;
    string name;
    string passport;

    Abonent(string p,string n,string pass){
        phone=p;
        name=n;
        passport=pass;}

    void display(){
        cout<<"Телефон: "<<phone<<endl;
        cout<<"ФИО: "<<name<<endl;
        cout<<"Паспорт: "<<passport<<endl;
        cout<<"-------------------------"<<endl;}};

int main() {
    list<Abonent> abonents;
    int n;
    
    cout<<"Введите количество абонентов: ";
    cin>>n;
    cin.ignore();
    
    for (int i=0;i<n;i++){
            string phone, name, passport;
            cout<<"\nАбонент "<<i+1<<":"<<endl;
            cout<<"Номер телефона: ";
            getline(cin, phone);
            cout<<"ФИО: ";
            getline(cin, name);
            cout<<"Паспорт: ";
            getline(cin, passport);
            
            Abonent newAbonent(phone, name, passport);
            
            auto it=abonents.begin();
            while (it!=abonents.end()&&it->name<name){it++;}
            abonents.insert(it, newAbonent);}
    
    cout<<"\nОТСОРТИРОВАННЫЙ СПИСОК"<<endl;
    for (Abonent a:abonents){a.display();}
    
    int searchCount;
    cout<<"\nВведите количество номеров для поиска: ";
    cin>>searchCount;
    cin.ignore();
    
    for (int i=0;i<searchCount;i++){
        string Phone;
        cout<<"Введите номер телефона для поиска "<<i+1<<": ";
        getline(cin,Phone);
        
        bool found=false;
        for (Abonent a:abonents){
            if (a.phone==Phone){
                cout<<"Владелец: "<<a.name<<endl;
                found=true;
                break;}}
        
        if (!found){cout<<"Абонент не найден!"<<endl;}}}
