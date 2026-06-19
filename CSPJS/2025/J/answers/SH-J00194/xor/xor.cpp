#include<bits/stdc++.h>
using namespace std;
int n,k,a[500002],c,d[500001],f[500001],s=0;
int main() {
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> c;
		a[i] = c^(a[i-1]);
//		cout << c << " " << a[i] << endl;
	}
//	for (int i = 0 ; i < n+1; i++) cout << a[i] << " ";
//	cout << endl; 
	for (int i = 0; i < n; i++) {
		c = k^a[i];
		for (int j = i+1; j <= n; j++) {
			if (a[j] == c) {
				d[i] = j;
				break;
			}
		}
	}
//	for (int i = 0 ; i < n; i++) cout << d[i] << " ";
//	cout << endl; 
	for (int i = 0; i < n; i++) {
		if (d[i]) f[d[i]-1] = i+1;
	}
	for (int i = n-1; i >= 0; i--) {
		if (f[i]) {
			i = f[i]-1;
			s++;
		}
	}
	cout << s;
	cin >> n; 
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
