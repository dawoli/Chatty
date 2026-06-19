#include<bits/stdc++.h>
#define LL long long
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
using namespace std;

const LL N = 1e5 + 10;

struct Node{
	LL sc, idx;
};
Node a[3][N];

LL aa[N][3];

LL T, n;
LL cl[N];

bool cmp(Node A, Node B){
	return A.sc > B.sc;
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	cin >> T;
	while(T--){
		cin >> n;
		for(LL i = 1ll; i <= n; i++){
			for(LL j = 1ll; j <= 3ll; j++){
				cin >> a[j][i].sc;
				aa[i][j] = a[j][i].sc;
				a[j][i].idx = i;
			}
		}
		memset(cl, 0ll, sizeof cl);
		LL ans = 0ll;
		for(LL i = 1ll; i <= 3ll; i++)
			sort(a[i] + 1ll, a[i] + n + 1ll, cmp);
		for(LL i = 1ll; i <= 3ll; i++){
			if(i == 1ll){
				for(LL j = 1ll; j <= n / 2ll; j++){
					ans += a[i][j].sc;
					cl[a[i][j].idx] = i;
				}
				continue;
			}
			LL cnt = 0ll;
			for(LL j = 1ll; j <= n; j++){
				if(cl[a[i][j].idx] != 0ll){
					if(a[i][j].sc > aa[j][cl[a[i][j].idx]]){
						ans -= aa[j][cl[a[i][j].idx]];
						ans += a[i][j].sc;
						cl[a[i][j].idx] = i;
						cnt++;
					}
					continue;
				}
				else if(cnt < (n / 2ll)){
					ans += a[i][j].sc;
					cl[a[i][j].idx] = i;
					cnt++;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
