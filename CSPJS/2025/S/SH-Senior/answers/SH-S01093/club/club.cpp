#include <bits/stdc++.h>
using namespace std;
#define int long long
int t, n, a[100005], b[100005], c[100005];
vector<int>tmp[5];
signed main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--){
		tmp[1].clear();
		tmp[2].clear();
		tmp[3].clear();
		cin >> n;
		for (int i = 1; i <= n; i++){
			cin >> a[i] >> b[i] >> c[i];
		}
		int cnta = 0, cntb = 0, cntc = 0, ans = 0; 
		for (int i = 1; i <= n; i++){
			if (a[i] >= b[i] && a[i] >= c[i]){
				cnta++;
				ans += a[i];
				tmp[1].push_back(min(a[i] - b[i], a[i] - c[i]));
			}
			else if (b[i] > a[i] && b[i] >= c[i]){
				cntb++;
				ans += b[i];
				tmp[2].push_back(min(b[i] - c[i], b[i] - a[i]));
			}
			else{
				cntc++;
				ans += c[i];
				tmp[3].push_back(min(c[i] - a[i], c[i] - b[i]));
			}
		}
		if (cnta <= n / 2 && cntb <= n / 2 && cntc <= n / 2){
			cout << ans << endl;
			continue;
		}
		int p;
		if (cnta > n / 2){
			p = 1;
		}
		else if (cntb > n / 2){
			p = 2;
		}
		else{
			p = 3;
		}
		sort(tmp[p].begin(), tmp[p].end());
		for (int i = 0; i < max(cnta, max(cntb, cntc)) - n / 2; i++){
			ans -= tmp[p][i];
		}
		cout << ans << endl;
	}
	return 0;
} 
