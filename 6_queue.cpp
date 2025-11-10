#include <iostream> 
#include <deque> 
#include <string> 
using namespace std; 

class bilet{ 
private: 
    string nazv,number,fio,data; 
public: 
    bilet(string n,string num,string f, string d){nazv=n;number=num;fio=f;data=d;} 
    void setNazv(string n){nazv=n;} 
    void setNumber(string num){number=num;} 
    void setFio(string f){fio=f;} 
    void setData(string d){data=d;} 
     
    string getNazv(){return nazv;} 
    string getNumber(){return number;} 
    string getFio(){return fio;} 
    string getData(){return data;}}; 
 
int main() { 
    deque<bilet> queue; 
    int vibor; 
     
    while (true){ 
        cout<<"\n1. Добавить заявку"<<endl; 
        cout<<"2. Удалить заявку"<<endl; 
        cout<<"3. Показать все"<<endl; 
        cout<<"4. Выход"<<endl; 
        cout<<"Выберите: ";         
        cin>>vibor; 
        cin.ignore(); 
         
        switch (vibor){ 
            case 1:{ 
                string nazv,number,fio,data; 
                cout<<"Пункт назначения: ";getline(cin,nazv); 
                cout<<"Номер рейса: ";getline(cin,number); 
                cout<<"Пассажир: ";getline(cin,fio); 
                cout<<"Дата вылета: ";getline(cin,data); 
                queue.push_back(bilet(nazv,number,fio,data)); 
                cout<<"Заявка добавлена!\n"; 
                break;} 
             
            case 2: { 
                if (queue.empty()){cout<<"Очередь пуста!\n";break;} 
                cout<<"Удалена заявка: "<<queue.front().getFio()<<endl; 
                queue.pop_front(); 
                break;} 
             
            case 3: {      
                if (queue.empty()){cout<<"Очередь пуста!\n";break;} 
                cout<<"\nВсе заявки:\n"; 
                int i=1; 
                for (bilet t:queue){ 
                    cout<<i<<". "; 
                    cout<<t.getNazv()<<" "<<t.getNumber()<<" "<<t.getFio()<<" "<<t.getData()<<endl; 
                    i++;} 
                break;} 
             
            case 4:return 0; 
            default: cout << "Такого варианта НЕТ\n";}}}
