#include <iostream> 
#include <fstream> 
#include <string> 
 
using namespace std; 
 
class Student { 
public: 
    char name[50]; 
    double grades[10];}; 
 
int main() { 
    ifstream in("students.txt",ios::in); 
    ofstream out("students.bin",ios::binary); 
    if (!in) { 
        cout << "Ошибка открытия файла students.txt!" << endl;} 
     
    int n; 
    in>>n; 
    in.ignore(); 
 
    cout<<"Вывод информации о студентах:\n\n"<<endl; 
    for (int i=0;i<n;i++){ 
        Student s; 
        in.getline(s.name,50); 
        for (int j=0;j<10;j++) { 
            in>>s.grades[j];} 
         
        in.ignore(); 
        double sum=0; 
        for (int j=0;j<10;j++) { 
            sum+=s.grades[j];} 
             
        double average=sum/10; 
         
        cout<<"Студент: "<<s.name<<"\n"; 
        cout<<"Оценки: "; 
        for (int j=0;j<10;j++){ 
            cout<<s.grades[j]<<" ";} 
 
        cout<<"\nСредний балл: "<<average<<"\n\n"; 
 
        out.write((char*)&s,sizeof(Student));} 
     
    in.close(); 
    out.close(); 
    cout<<"Бинарный файл создан..."<<endl;} 
