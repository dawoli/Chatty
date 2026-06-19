#include<bits/stdc++.h>
using namespace std;
int a[10000000];
int main () {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin>> a[i];
	cout << (n/a[2]+1)*(n/a[2]+1)%998244353;
	return 0;
}
