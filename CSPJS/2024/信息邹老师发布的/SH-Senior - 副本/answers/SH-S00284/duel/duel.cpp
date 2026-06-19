#include<bits/stdc++.h>
using namespace std;

#define int long long

const int maxn = 1e5 + 9;

int n, r[maxn], c[maxn];
//bool flag[maxn], a[maxn];


signed main(){
	
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	
	cin >> n;
	int l = n;
	int m = 0;
	for(int i = 1; i <= n; i++){
		cin >> r[i];
		c[r[i]]++;
		m = max(m, r[i]);
	}
	
	for(int i = 1; i <= m; i++){
		//cout << c[i];
		if(c[i] == 0){
			continue;
		}
		for(int j = i + 1; j <= m; j++){
			if(c[j] != 0){
				int t = min(c[i], c[j]);
				l -= t;
				c[i] -= t;
				//cout << i << " " << j << " " << c[i] << " " << c[j] << " " << t << " " << l << endl;
				break;
			}
		}
	}
	
	cout << l;
	
	
	return 0;
}
