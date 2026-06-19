#include <bits/stdc++.h>
using namespace std;
int a[500005];

int main(){
	freopen("xor.in", r, stdin);
	freopen("xor.out", w, stdout);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	cout << floor(n / 2);
	return 0;
} 
