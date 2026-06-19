#include <bits/stdc++.h>
using namespace std;
bool cmp(long long a,long long b){
	return a > b;
}
int main(){
	long long n,m;
	cin >> n >>m;
	long long c = n*m+1;
	long long a[c];
	for(long long i = 0;i < n * m;i++) cin >> a[i];
	long long temp = a[0];
	sort(a,a+n*m,cmp);
	long long t = 0;
	for(long long i = 0;i < n*m;i++) if(a[i] == temp) t = i+1;
	long long x = t/n;
	long long y = (t-x*n)%m;
	if(y == 0){
		if(x % 2 == 0)
			y = 1;
		else y = m;
		cout << x << ' ' << y;
		return 0;
	}
	if(y != 0){
		x++;
		if(x % 2 == 0) y = m+1-y;
	}
	cout << x << ' ' << y;
}
