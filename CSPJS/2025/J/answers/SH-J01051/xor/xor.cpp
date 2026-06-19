#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
int a[N];
signed main(){
	freopen ("xor.in", "r", stdin);
	freopen ("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	int r = 0, cnt = 0;
	for (int i = 1; i <= n; i++){
		int p = 0;
		for (int j = i; j <= n; j++){
			p ^= a[j];
			if (p == k){
				if (i > r){
					cnt++;
					r = j;
				}
				else if(i <= r && j < r) r = j;
				break;
			}
		}
	}
	cout << cnt;
	return 0;
}
