#include <iostream> 
#include <fstream> 
 
using namespace std; 
 
class StudentOld { 
public:
    char name[50]; 
    double grades[10];};

class StudentNew { 
public:
    char name[50]; 
    double grades[10]; 
    double average;

    void calcaverage(){
        double sum=0;
        for(int i=0;i<10;i++) {
            sum+=grades[i];}
        average=sum/10;}
    
    void writefile(ofstream& out){
        out.write((char*)this, sizeof(StudentNew));}
    
    void vivod(){
        cout<<name<<" - "<<average<<endl;}
}; 
 
int main() { 
    ifstream in("students.bin", ios::binary); 
    if (!in){ 
        cout << "Файл не найден!" << endl; 
        return 1;} 
 
    StudentOld sOld; 
    int count = 0; 
     
    while (in.read((char*)&sOld,sizeof(StudentOld))){ 
        count++;}
    in.close(); 

    in.open("students.bin", ios::binary); 
    StudentNew* students=new StudentNew[count]; 
    
    for(int i = 0; i < count; i++){
        in.read((char*)&sOld, sizeof(StudentOld));
        for(int j=0;j<50;j++){ 
            students[i].name[j]=sOld.name[j];}
        for(int j=0;j<10;j++){
            students[i].grades[j]=sOld.grades[j];}
        students[i].calcaverage();
    }
    in.close();
    
    ofstream out("students.bin", ios::binary); 
     
    cout << "Остались студенты со средним баллом >= 3.5:" << endl; 
    for (int i = 0; i < count; i++) { 
        if (students[i].average >= 3.5) { 
            students[i].writefile(out);
            students[i].vivod();}} 
    out.close();}
