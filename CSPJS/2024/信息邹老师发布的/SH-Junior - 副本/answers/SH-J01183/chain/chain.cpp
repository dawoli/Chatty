#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

LL T, n, k, q, l[100005], r, c;
vector<LL> s[100005];
bool isc(LL x, LL y){
//	printf("x = %lld, y = %lld\n", x, y);
	for(LL i = y - 1; i >= max(0LL, y - k + 1); -- i){
//		printf("i = %d, %d\n", i);
		if(s[x][i] == 1)
			return true;
	}
	return false;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	
	cin >> T;
	while(T --){
		cin >> n >> k >> q;
		for(LL i = 1; i <= n; ++ i){
			cin >> l[i];
			for(LL j = 1; j <= l[i]; ++ j){
				LL t;
				cin >> t;
				s[i].push_back(t);
			}
		}
		
		while(q --){
			cin >> r >> c;
			if(r == 1){
				bool flag = false;
				for(LL i = 1; i <= n; ++ i)
					for(LL j = 0; j < l[i]; ++ j)
						if(s[i][j] == c && isc(i, j)){
							flag = true;
							break;
						}
				if(flag)
					cout << 1 << endl;
				else
					cout << 0 << endl;
			}
			cout << 1 << endl;
		}
	}
	return 0;
}
