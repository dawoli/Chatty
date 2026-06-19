#include<bits/stdc++.h>
using namespace std;
int n,m,c,r,num=1,sc;
int a[250];
bool cmp(int a,int b) {
	return a> b;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	int size = n*m;
	cin >> sc;
	a[1] = sc;
	for(int i = 2; i <= size; i++) {
		cin >> a[i];
		if(a[i] > sc) {
			num++;
		}
	}
	c = (num - 1)/n+1;
	if(c == 1) {
		r = num;
	} else if(c%2 != 0) {
		if(num % n == 0) {
			r = num/n;
		} else {
			r=num%n;
		}

	} else if(c%2 == 0) {
		if(num % n == 0) {
			r = 1;
		} else {
			r= n-(num%n)+1;
		}

	}
	cout << c << " " << r;
	return 0;
}
