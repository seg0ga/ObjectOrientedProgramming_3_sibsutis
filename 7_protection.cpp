#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    string input;
    stack<char> vse;
    stack<char> glasnie;
    stack<char> vrem;  


    cout<<"Введите строку: ";getline(cin,input);

    for (int i=0;i<input.length();i++){vrem.push(input[i]);}

    while (!vrem.empty()){
        char c=vrem.top();
        vrem.pop();
        vse.push(c);

        char bukva=tolower(c);
        if (bukva=='a'||bukva=='e'||bukva=='i'||bukva=='o'||bukva=='u'||bukva=='y'){glasnie.push(c);}}
    
    cout<<"\nПервоначальный стек: ";
    
    string out1,out2;

    while (!vse.empty()){out1+=vse.top()+string(" ");vse.pop();}
    cout<< out1;

    cout<<"\nСтек гласных букв: ";

    while (!glasnie.empty()){out2+=glasnie.top()+string(" ");glasnie.pop();}
    cout<<out2<<endl;}
