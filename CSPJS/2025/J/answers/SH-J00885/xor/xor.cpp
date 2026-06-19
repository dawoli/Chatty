#include<bits/stdc++.h>

using namespace std;

int n, k, f = 1, c1, c0;
int a[500005];

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 0; i < n; i ++){
		cin >> a[i];
		f = min(a[i], f);
		c1 += a[i];
		c0 += (a[i] + 1) % 2;
	}
	if(f && k == 0){
		cout << n / 2 << endl;
	}
	else if(k == 0){
		cout << c0 + c1 / 2;
	}
	else if(k == 1){
		cout << min(c1, c0) + max(0, c1 - c0);
    }
	return 0;
}
