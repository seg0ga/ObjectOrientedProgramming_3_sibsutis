#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class magaz {
private:
    string name,address,time,type;
    double plosh;

public:
    magaz(string n,string addr,string t,string typ,double p){
        name=n;
        address=addr;
        time=t;
        type=typ;
        plosh=p;}

    string getName(){return name;}
    string getAddress(){return address;}
    string getTime(){return time;}
    string getType(){return type;}
    double getPlosh(){return plosh;}

    void setName(string n){name=n;}
    void setAddress(string addr){address=addr;}
    void setTime(string t){time=t;}
    void setType(string typ){type=typ;}
    void setPlosh(double p){plosh=p;}

    void outputInfo(){
        cout<<"Название: "<<name<<endl;
        cout<<"Адрес: "<<address<<endl;
        cout<<"Время работы: "<<time<<endl;
        cout<<"Тип инструментов: "<<type<<endl;
        cout<<"Площадь: "<<plosh<<endl;
        cout<<"________________________"<<endl;}

    void write(ofstream& file){
        file<<name<<endl;
        file<<address<<endl;
        file<<time<<endl;
        file<<type<<endl;
        file<<plosh<<endl;}

    void read(ifstream& file){
        getline(file,name);
        getline(file,address);
        getline(file,time);
        getline(file,type);
        file>>plosh;
        file.ignore();}
};

int main(){
    vector<magaz> allmagaz;
    vector<magaz> bigmagaz;
    
    ifstream inputFile("instrument.txt");
    if(!inputFile.is_open()){
        cout<<"Ошибка"<<endl;
        return 1;}

    int N;
    cout<<"Введите количество магазинов: ";
    cin>>N;
    cin.ignore();

    for(int i=0;i<N;i++){
        magaz store("","","","",0);
        store.read(inputFile);
        allmagaz.push_back(store);
        if(store.getPlosh()>200){
            bigmagaz.push_back(store);}}
    inputFile.close();

    cout<<"\nВСЕ МАГАЗИНЫ ИЗ ФАЙЛА"<<endl;
    for(int i=0;i<allmagaz.size();++i){
        cout<<"Магазин №"<<i+1<<":"<<endl;
        allmagaz[i].outputInfo();}

    cout<<"\nМАГАЗИНЫ С ПЛОЩАДЬЮ >200"<<endl;
    if(bigmagaz.empty()){
        cout<<"Нет магазинов с площадью более 200 м²!"<<endl;
    }else{
        for(int i=0;i<bigmagaz.size();++i){
            cout<<"Магазин №"<<i+1<<endl;
            bigmagaz[i].outputInfo();}}

    if(!bigmagaz.empty()){
        for(int i=0;i<bigmagaz.size()-1;++i){
            for(int j=0;j<bigmagaz.size()-i-1;++j){
                if(bigmagaz[j].getPlosh()<bigmagaz[j+1].getPlosh()){
                    magaz temp=bigmagaz[j];
                    bigmagaz[j]=bigmagaz[j+1];
                    bigmagaz[j+1]=temp;}}}

        cout<<"\nОТСОРТИРОВАННЫЙ ВЕКТОР"<<endl;
        for(int i=0;i<bigmagaz.size();++i){
            cout<<"Магазин №"<<i+1<<" c площадью "<<bigmagaz[i].getPlosh()<<endl;
            bigmagaz[i].outputInfo();}}

    cout<<"\nДОБАВЛЕНИЕ НОВОГО МАГАЗИНА"<<endl;
    string name,address,time,type;
    double plosh;

    cout<<"Введите данные нового магазина:"<<endl;
    cout<<"Название: ";
    getline(cin,name);
    cout<<"Адрес: ";
    getline(cin,address);
    cout<<"Время работы: ";
    getline(cin,time);
    cout<<"Тип инструментов: ";
    getline(cin,type);
    cout<<"Площадь: ";
    cin>>plosh;
    cin.ignore();

    magaz newstore(name,address,time,type,plosh);

    allmagaz.push_back(newstore);

    if(newstore.getPlosh()>200){
        bigmagaz.push_back(newstore);
        for(int i=0;i<bigmagaz.size()-1;++i){
            for(int j=0;j<bigmagaz.size()-i-1;++j){
                if(bigmagaz[j].getPlosh()<bigmagaz[j+1].getPlosh()){
                    magaz temp=bigmagaz[j];
                    bigmagaz[j]=bigmagaz[j+1];
                    bigmagaz[j+1]=temp;}}}}

    ofstream outputFile("instrument.txt",ios::app);
    if(outputFile.is_open()){
        newstore.write(outputFile);
        outputFile.close();
        cout<<"\nДанные записаны"<<endl;
    }else{
        cout<<"\nОшибка"<<endl;}

    cout<<"\nИТОГОВАЯ ИНФОРМАЦИЯ"<<endl;
    cout<<"Всего магазинов: "<<allmagaz.size()<<endl;
    cout<<"Магазинов с площадью > 200 м²: "<<bigmagaz.size()<<endl;

    if(!bigmagaz.empty()){
        cout<<"\nОБНОВЛЕННЫЙ ВЕКТОР БОЛЬШИХ МАГАЗИНОВ"<<endl;
        for(int i=0;i<bigmagaz.size();++i){
            cout<<"Магазин №"<<i+1<<" (площадь: "<<bigmagaz[i].getPlosh()<<" м²):"<<endl;
            bigmagaz[i].outputInfo();}}
}
