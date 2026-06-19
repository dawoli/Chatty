#include<bits/stdc++.h>
using namespace std;
#define operator c
int num1,num2;
char oper;
int operation(int number1,char operator,int number2){
    if(operator=='+')return number1+number2;
    if(operator=='-')return number1-number2;
    if(operator=='*')return number1*number2;
    if(operator=='/')return number1/number2;
    if(operator=='%')return number1%number2;
}
int main(){
    cin>>num1>>oper>>num2;
    cout<<operation(num1,oper,num2);
    return 0;
}
