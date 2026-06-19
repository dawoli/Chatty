#include<bits/stdc++.h>
using namespace std;
stack <long long>s;
long long x;
int main(){
	string str;
	getline(cin,str);
	for(int i=0;i<str.length();i++){
		if(str[i]>='0'&&str[i]<='9')
			x=x*10+(str[i]-'0');
		if(str[i]==' '){
			s.push(x);
			x=0;
		}
		switch (str[i]) {
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
		}
	} 
	cout<<s.top();
	return 0;
}
