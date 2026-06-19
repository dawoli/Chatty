/*
输出后缀表达式
碰到数字就输出
符号入栈，栈中符号顺序，按照优先级从小到大。不符合顺序的符号出栈输出。
括号正常入栈，一旦成对，括号内符号出栈输出
最后栈中剩余符号顺序出栈输出
*/
#include<bits/stdc++.h>
using namespace std;
stack <char> s;
//指定优先级
int grade(char c) {
	//定义符号优先级
	if (c == '*' || c == '/') return 2;
	else if (c == '+' || c == '-') return 1;
	else return 0;
}
int main() {
	char str[1010]={};
	//输入
	cin >> str;
	//中缀表达式转后缀表达式
	for (int i = 0; str[i]; i++) {
		//是字母则直接输出
		if (str[i] >= 'a' && str[i] <= 'z') {
			cout<<str[i];
		} else {//不是字母
			//遇到左括号时直接入栈
			if (str[i]=='(') s.push(str[i]);
			else if (str[i]==')') {
				while (s.top()!='(') {
					cout<<s.top();
					s.pop();
				}
				s.pop();//左括号出栈
			} else {//处理不符合优先级的运算符
				while (s.empty()!=1 && grade(str[i]) <= grade(s.top())) {
					cout<<s.top();
					s.pop();
					//栈空跳出循环
					if (s.empty()) break; 
				}
				s.push(str[i]);//此时运算符可入栈
			}
		}
	}
	//输出栈中剩余符号
	while (s.empty()!=1) {
		cout<<s.top();
		s.pop();
	}
	return 0;
}
