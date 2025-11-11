#include <iostream> 
#include <deque> 
#include <string> 
using namespace std; 

class decanat{ 
private: 
    string group;
    double ball; 
public: 
    decanat(string g,double b){group=g;ball=b;} 
    void setGroup(string g){group=g;} 
    void setBall(double b){ball=b;} 
     
    string getGroup(){return group;} 
    double getBall(){return ball;}};

int main() { 
    int kol=0;
    double bal=666;
    deque<decanat> queue1;
    deque<decanat> queue2;
    cout<<"Введите количество объектов: ";         
    cin>>kol; 
    cin.ignore(); 

    for (int i=0;i<kol;i++){
        string group;
        double ball; 
        cout<<"Номер группы ";getline(cin,group); 
        cout<<"Средний балл: ";cin>>ball;cin.ignore();
        cout<<"\n";
        queue1.push_back(decanat(group,ball));}

    cout<<"Введите балл для отчисления: ";         
    cin>>bal; 
    cin.ignore();  
    for (decanat a:queue1){
        if (a.getBall()<bal){queue2.push_back(a);}}

    cout<<"\n\nВсе группы:\n";
    for (decanat all:queue1){cout<<"Группа: "<<all.getGroup()<<" "<<"Балл: "<<all.getBall()<<endl;}
    
    
    cout<<"\n\nГруппы с баллом меньше "+ to_string(bal)+"\n";
    for (decanat izbrannie:queue2){cout<<"Группа: "<<izbrannie.getGroup()<<" "<<"Балл: "<<izbrannie.getBall()<<endl;}}
