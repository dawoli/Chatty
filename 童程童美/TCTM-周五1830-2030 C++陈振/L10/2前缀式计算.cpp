#include<bits/stdc++.h>
using namespace std;
char c[1010][1010];
stack<double> s;
void fun(char str[]) {
	switch (str[0]) {
		double a,b;
	case '+':
		a=s.top();s.pop();
		b=s.top();s.pop();
		s.push(a+b);
		break;
	case '-':
		a=s.top();s.pop();
		b=s.top();s.pop();
		s.push(a-b);
		break;
	case '*':
		a=s.top();s.pop();
		b=s.top();s.pop();
		s.push(a*b);
		break;
	case '/':
		a=s.top();s.pop();
		b=s.top();s.pop();
		s.push(a/b);
		break;
		default:
			s.push(atof(str));
	}
}
int main() {
	int k=0;
	while (cin>>c[k])k++;
	for (int i=k-1; i>=0; i--) {
		fun(c[i]);
	}
	cout<<fixed<<setprecision(2)<<s.top();
	return 0;
}
