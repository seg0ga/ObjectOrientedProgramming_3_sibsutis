#include <iostream> 
#include <fstream> 
#include <string> 
using namespace std;

class kinoteatr{
protected:
    string nazv,phone,address,time;
    int kolvo;
public:
    kinoteatr(){
        nazv="";
        phone="";
        address="";
        time="";
        kolvo=0;}
    kinoteatr(string _nazv,string _phone, string _address, string _time, int _kolvo){
        nazv=_nazv;
        phone=_phone;
        address=_address;
        time=_time;
        kolvo=_kolvo;}

    void setNazv(string _nazv){nazv=_nazv;}
    void setPhone(string _phone){phone=_phone;}
    void setAddress(string _address){address=_address;}
    void setTime(string _time){time=_time;}
    void setKolvo(int _kolvo){kolvo=_kolvo;}

    string getNazv(){return nazv;}
    string getPhone(){return phone;}
    string getAddress(){return address;}
    string getTime(){return time;}
    int getKolvo(){return kolvo;}

    virtual void showInf(){
        cout<<"Кинотеатр: "<<nazv<<endl;
        cout<<"Телефон :"<<phone<<endl;
        cout<<"Адрес: "<<address<<""<<endl;
        cout<<"Время работы: "<<time<<endl;
        cout<<"Количество залов: "<<kolvo<<endl;
        cout<<"________________________"<<endl;}};

class kinozali:public kinoteatr{
public:
    int vmest;
    kinozali():kinoteatr(){vmest=0;}
    kinozali(string _nazv,string _phone,string _address,string _time,int _kolvo, int _vmest):kinoteatr(_nazv,_phone,_address,_time,_kolvo){vmest=_vmest;}
    void setVmest(int _vmest){vmest=_vmest;}
    int getVmest(){return vmest;}
    void showInf() override{
        cout<<"Кинотеатр: "<<nazv<<endl;
        cout<<"Телефон :"<<phone<<endl;
        cout<<"Адрес: "<<address<<""<<endl;
        cout<<"Время работы: "<<time<<endl;
        cout<<"Количество залов: "<<kolvo<<endl;
        cout<<"Вместимость: "<<vmest<<endl;
        cout<<"________________________"<<endl;}};

int main(){
    ifstream inKino("Kino.txt",ios::in);
    ifstream inZal("Zal.txt",ios::in);
    if (!inKino) {
        cout<< "Ошибка открытия файла Kino.txt!" << endl;
        return 1;}
    if (!inZal) {
        cout <<"Ошибка открытия файла Zal.txt!" << endl;
        return 1;}
    int n;
    cout<<"Введите количество объектов N: ";
    cin>>n;
    cin.ignore();   

    kinoteatr* kino=new kinoteatr[n];
    kinozali* zal=new kinozali[n];

    cout<<"\nКинотеатры"<<endl;
    for (int i=0;i<n;i++){
        string nazv,phone,address,time;
        int kolvo;
        
        getline(inKino,nazv);
        getline(inKino,phone);
        getline(inKino,address);
        getline(inKino,time);
        inKino>>kolvo;
        inKino.ignore();
        
        kino[i]=kinoteatr(nazv,phone,address,time,kolvo);
        kino[i].showInf();}
    
    cout<<"\nКинозалы"<<endl;
    for (int i=0;i<n;i++){
        string nazv,phone,address,time;
        int kolvo,vmest;
        
        getline(inZal, nazv);
        getline(inZal, phone);
        getline(inZal, address);
        getline(inZal, time);
        inZal >> kolvo >> vmest;
        inZal.ignore();
        zal[i] = kinozali(nazv, phone, address, time, kolvo, vmest);
        zal[i].showInf();}
    
    inKino.close();
    inZal.close();}
