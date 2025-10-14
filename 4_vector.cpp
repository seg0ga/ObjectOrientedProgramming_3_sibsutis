#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Manufacturer {
    private:
    string country;
    string type;
    int year;
    string segment;

public:
Manufacturer(string c, string e, int y, string m) {
    country = c;
    type = e;
    year = y;
    segment = m;}

    string getCountry() { return country; }
    string getType() { return type; }
    int getYear() { return year; }
    string getSegment() { return segment; }

    void setCountry(string c) { country = c; }
    void setType(string e) { type = e; }
    void setYear(int y) { year = y; }
    void setSegment(string m) { segment = m; }

    void outputInfo() {
        cout<< "Страна: " << country << endl;
        cout<< "Тип оборудования: " << type << endl;
        cout<< "Год основания: " << year << endl;
        cout<< "Рыночный сегмент: " << segment << endl;
        cout<< "-----------------------------" << endl;}};


int main() {
    vector<Manufacturer> originalVector;
    
    int originalSize;
    cout<<"Введите размер исходного вектора: ";
    cin>>originalSize;
    cin.ignore();
    
    for (int i=0;i<originalSize;++i){
        string country, type, segment;
        int year;
        
        cout<<"\nПроизводитель #"<<i+1<<":\n";
        cout<<"Страна: ";
        getline(cin,country);
        cout<<"Тип оборудования: ";
        getline(cin,type);
        cout<<"Год основания: ";
        cin>>year;
        cin.ignore();
        cout<<"Рыночный сегмент: ";
        getline(cin,segment);
        originalVector.push_back(Manufacturer(country, type, year, segment));}
    
    cout<<"\nИСХОДНЫЙ ВЕКТОР"<<endl;
    for (int i=0;i<originalVector.size();++i){
        cout<<"Элемент "<<i+1<<":"<< endl;
        originalVector[i].outputInfo();}
    
    vector<Manufacturer> newVector;
    
    for (int i=0;i<originalVector.size();++i){
        if (originalVector[i].getYear()>1900){
            newVector.push_back(originalVector[i]);}}
    
    cout<<"\nНОВЫЙ ВЕКТОР"<<endl;
    if (newVector.empty()){
        cout<<"Новый вектор пуст!"<<endl;
    }else{
        cout<<"Новый вектор содержит "<<newVector.size()<<" элементов:"<<endl;
        for (int i=0;i<newVector.size();++i){
            cout<<"Элемент "<<i+1<<":"<<endl;
            newVector[i].outputInfo();}}
    
    if (!newVector.empty()){
        for (int i=0;i<newVector.size()-1;++i){
            for (int j=0;j<newVector.size()-i-1;++j){
                if (newVector[j].getYear()>newVector[j+1].getYear()){
                    Manufacturer temp=newVector[j];
                    newVector[j]=newVector[j + 1];
                    newVector[j+1]=temp;}}}
        
        cout<<"\nОТСОРТИРОВАННЫЙ ВЕКТОР"<<endl;
        for (int i=0;i<newVector.size();++i){
            cout<<"Элемент "<<i+1<<" (год "<<newVector[i].getYear()<<"):"<<endl;
            newVector[i].outputInfo();}
        
        cout<<"\nВСТАВКА НОВОГО ОБЪЕКТА"<<endl;
        string country, type, segment;
        int year;
        
        cout<<"Введите данные нового производителя:\n";
        cout<<"Страна: ";
        getline(cin,country);
        cout<<"Тип оборудования: ";
        getline(cin,type);
        cout<<"Год основания: ";
        cin>>year;
        cin.ignore();
        cout<<"Рыночный сегмент: ";
        getline(cin,segment);
        
        Manufacturer newManufacturer(country, type, year, segment);
        int insertPosition=0;
        while (insertPosition<newVector.size()&&newVector[insertPosition].getYear()<year){insertPosition++;}
        
        if (insertPosition==newVector.size()){
            newVector.push_back(newManufacturer);
        }else{
            newVector.insert(newVector.begin()+insertPosition,newManufacturer);}
        
        cout<<"\nВЕКТОР ПОСЛЕ ВСТАВКИ"<<endl;
        for (int i=0;i<newVector.size();++i){
            cout<<"Элемент "<<i+1<<" (год "<<newVector[i].getYear()<<"):"<<endl;
            newVector[i].outputInfo();}}
    
    cout<<"\nИНФОРМАЦИЯ О ВЕКТОРАХ"<<endl;
    cout<<"Исходный вектор: "<<originalVector.size()<<" элементов"<<endl;

    cout<<"Новый вектор: "<<newVector.size()<<" элементов" <<endl;
    
    if (!newVector.empty()){
        cout<<"Первый элемент нового вектора: "<<newVector.front().getCountry()<<endl;
        cout<<"Последний элемент нового вектора: "<<newVector.back().getCountry()<<endl;}}
