#include<bits/stdc++.h>
using namespace std;
const int N = 105;
int n, m, a[N];
int sum, e = 1;
int l = 0;
int r = 0;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	sum = n*m;
	for(int i = 1; i <= sum; ++i) {
		cin >> a[i];
		if(a[i] > a[1]) ++e; 
	}
	if(n!= 0 && e%n == 0) l = e/n;
	else if(n != 0) l = e/n + 1;
	if(n != 0) r = e%n;
	if(r == 0) r = n;
	if(l%2 == 0) r = n-r+1;
	cout << l << " " << r << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
