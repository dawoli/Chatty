#include<bits/stdc++.h>
using namespace std;
stack<double> s;
int main() {
	double a=0,sum=0;
	cin>>a;
	s.push(a);
	double b=0,x=0; char c;
	//符号与数字成组输入
	while (cin>>c, cin>>b) {
		if (c=='+') {
			s.push(b);
		} else if (c=='-') {
			s.push(-b);
		} else if (c=='*') {
			x=s.top();
			s.pop();
			s.push(x*b);
		} else {
			x=s.top();
			s.pop();
			s.push(x/b);
		}
	}
	while (s.empty()!=1) {
		sum=sum+s.top();
		s.pop();
	}
	cout<<fixed<<setprecision(2)<<sum;
	return 0;
}

