#include <iostream>
#include <string>
using namespace std;

class apteka{
protected:
 string name,phone,address,time;
public:
 apteka(){  
 name="";
 phone="";
 address="";
 time="";}
 apteka(string _name,string _phone,string _address,string _time){
  name= _name;
  phone= phone;
  address= _address;
  time= _time;}
  void setName(string _name){name=_name;}
  void setPhone(string _phone){phone=_phone;}
  void setAddress(string _address){address=_address;}
  void setTime(string _time){time=_time;}
  void setTime(int open,int close){time=to_string(open)+":00-"+to_string(close)+":00";}
  
  string getName(){return name;}
  string getPhone(){return phone;}
  string getAddress(){return address;}
  string getTime(){return time;}
 
  void showInf(){
   cout<<"Аптека: \""<<name<<"\""<<endl;
   cout<<"Телефон :"<<phone<<endl;
   cout<<"Адрес: "<<address<<""<<endl;
   cout<<"Время работы: "<<time<<endl;
   cout<<"________________________"<<endl;
}};

class private_apteka:public apteka{
public:
 string vlad;
 private_apteka():apteka(){vlad="";}
 private_apteka(string _name,string _phone,string _address,string _time,string _vlad):apteka(_name,_phone,_address,_time){vlad=_vlad;}
 void setVlad(string _vlad){vlad=_vlad;}
 string getVlad(){return vlad;}
 void showInf(){
   cout<<"Частная аптека: \""<<name<<"\""<<endl;
   cout<<"Телефон :"<<phone<<endl;
   cout<<"Адрес: "<<address<<""<<endl;
   cout<<"Время работы: "<<time<<endl;
   cout<<"Владелец: "<<vlad<<endl;
   cout<<"________________________"<<endl;
}};

int main(){
 apteka aptk1("Аптека плюс","8-(800)-555-35-35","Сухарная 96","8:00-22:00");
 apteka aptk2("Ромашка","8-(800)-666-66-66","Дуси Ковальчук 14","9:00-21:00");
 private_apteka aptk3("Лека","8-(800)-555-55-55","Гурьевская 51","10:00-12:00","Синица М.А.");
 private_apteka aptk4("Apteka.ru","8-(800)-123-45-67","Бориса Богаткова 51","Круглосуточно","Криволапов Н.А.");
 aptk3.setTime(6,23);
 aptk1.showInf();
 aptk2.showInf();
 aptk3.showInf();
 aptk4.showInf();
}
