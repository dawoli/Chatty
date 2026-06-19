#include<bits/stdc++.h>
using namespace std;
stack<char> s;
char a[1010], b[1010];
int main() {
	//输入入栈及出栈顺序
	cin>>a>>b;
	int l=strlen(a);
	int num=0;//出栈元素的下标
	for (int i=0;i<l;i++) {
		//1)安排一个字符入栈
		s.push(a[i]);
		//2)验证栈顶字符和出栈字符相等
		while(!s.empty()&&s.top()==b[num]){
			s.pop(); //出栈
			num++;//下标加1，验证下一元素
		}
	}
	if(s.empty())
		cout<<"right";
	else
		cout<<"error";
	return 0;
}  

