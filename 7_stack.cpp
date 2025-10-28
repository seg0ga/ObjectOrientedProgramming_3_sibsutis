#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string stroka;
    stack<char> stack;
    bool star=false;
    int starPol=0;
    bool symetrichno=true;

    cout<<"Введите строку: ";
    getline(cin,stroka);

    for (int i=0;i<stroka.length();i++) {
        char c=stroka[i];
        if (c=='*'){starPol=i;star=true;break;}
        stack.push(c);}

    if (star==false){cout<<"Символ * отсутствует"<<endl;return 0;}
    
    for (int i=starPol+1;i<stroka.length();i++){
        if (stack.empty()||stroka[i]!=stack.top()){
            symetrichno=false;
            break;}
        stack.pop();}

    if (symetrichno&&stack.empty()){cout<<"Строка симметрична"<<endl;
    }else{cout<<"Строка не симметрична"<<endl;}}
