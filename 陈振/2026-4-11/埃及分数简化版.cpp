// Problem URL:  
// Finish Time: 2026/4/11 22:01:05 AC
// Start Time: 2026/4/11 21:23:37

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
template<typename T=int,bool simp=true>class frac
{
	int _a,_b;
public:
	frac(int _a=0,int _b=1):_a(_a),_b(_b) { if(simp)simplify(); }
	int &num() { return _a; }
	int &den() { return _b; }
	double val() { return (double)_a/_b; }
	string str() { return to_string(_a)+"/"+to_string(_b); }
	string latex() { return "\\frac{"+to_string(_a)+"}{"+to_string(_b)+"}"; }
	bool operator<(const frac &x)const { return _a*x._b<_b*x._a; }
	bool operator==(const frac &x)const { return _a*x._b==_b*x._a; }
	bool operator>(const frac &x)const { return _a*x._b>_b*x._a; }
	bool operator<=(const frac &x)const { return _a*x._b<=_b*x._a; }
	bool operator>=(const frac &x)const { return _a*x._b>=_b*x._a; }
	frac operator+(const frac &x)const { return frac(_a*x._b+_b*x._a,_b*x._b); }
	frac operator-(const frac &x)const { return frac(_a*x._b-_b*x._a,_b*x._b); }
	frac operator*(const frac &x)const { return frac(_a*x._a,_b*x._b); }
	frac operator/(const frac &x)const { return frac(_a*x._b,_b*x._a); }
	frac operator+=(const frac &x) { return *this=*this+x; }
	frac operator-=(const frac &x) { return *this=*this-x; }
	frac operator*=(const frac &x) { return *this=*this*x; }
	frac operator/=(const frac &x) { return *this=*this/x; }
	frac &simplify()
	{
		int g=__gcd(_a,_b);
		_a/=g,_b/=g;
		if(_b<0)_a=-_a,_b=-_b;
		return *this;
	}
};
frac<> a,b;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>a.num()>>a.den();
	a.simplify();
	while(a.num()!=1)
	{
		b.den()=ceil((double)a.den()/a.num());
		b.num()=1;
		cout<<b.str()<<' ';
		a=a-b;
	}
	cout<<a.str();
	return 0;
}