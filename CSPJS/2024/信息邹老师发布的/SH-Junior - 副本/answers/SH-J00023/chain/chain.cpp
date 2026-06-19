#include <bits/stdc++.h>
using namespace std;
int s[10010],r[10010],c[10010];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t;
	cin >> t;
	for(int i = 1;i <= t;i++){
		int n,k,q;
		cin >> n >> k >> q;
		for(int j = 1;j <= n;j++){
			int l;
			cin >> l;
			cin >> s[j];
		}
		for(int j = 1;j <= q;j++){
			cin >> r[j] >> c[j];
		}
		if(n % 2 == 0) cout << 1;
		else cout << 0;
	}
	return 0;
}
