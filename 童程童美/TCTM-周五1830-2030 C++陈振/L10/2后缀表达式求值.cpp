#include<bits/stdc++.h>
using namespace std;
char c[1001][10];
stack<double> s;
//用栈实现后缀表达式运算
void fun(char str[]) {
	switch (str[0]) {
		double a,b;
		case '+':
			a=s.top();s.pop();
			b=s.top();s.pop();
			s.push(b+a); break;
		case '-':
			a=s.top();s.pop();
			b=s.top();s.pop();
			s.push(b-a); break;
		case '*':
			a=s.top();s.pop();
			b=s.top();s.pop();
			s.push(b*a); break;
		case '/':
			a=s.top();s.pop();
			b=s.top();s.pop();
			s.push(b/a); break;
		default:
			//字符串数字转浮点数入栈
			s.push(atof(str));
	}
}
int main() {
	int k=0;
	//输入
	while (cin>>c[k])k++;
	//处理所有的数字和符号
	for (int i=0; i<=k-2; i++) {
		fun(c[i]);
	}
	//输出结果
	cout<<s.top();
	return 0;
}
