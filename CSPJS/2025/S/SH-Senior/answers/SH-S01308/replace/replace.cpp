#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll L = 2e6 + 1, N = 2e5 + 1;
ll n, q, ans;
char s[L], t1[L], t2[L], temp[L];
struct node{
	ll l1, r1, l2, r2;
}si[N];
void init(){
	memset(t1, 0, sizeof(t1));
	memset(t2, 0, sizeof(t2));
	memset(temp, 0, sizeof(temp));
	ans = 0;
}
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (ll i = 1;i <= n;i++){
		if (i == 1){
			cin >> s;
			si[1].l1 = 0;
		}else{
			cin >> s + (si[i - 1].r2 + 1);
			si[i].l1 = si[i - 1].r2 + 1;
		}
		si[i].r1 = strlen(s) - 1;
		cin >> s + (si[i].r1 + 1);
		si[i].l2 = si[i].r1 + 1;
		si[i].r2 = strlen(s) - 1;
	}
	for (ll i = 1;i <= q;i++){
		init();
		cin >> t1 >> t2;
		if (strlen(t1) != strlen(t2)){
			cout << 0 << "\n";
			continue;
		}
		strcpy(temp, t1);
		for (ll j = 1;j <= n;j++){
			for (ll k = 0;k < strlen(t1) - si[j].r1 + si[j].l1;k++){
				bool ok = 1;
				for (ll dt = 0;dt <= si[j].r1 - si[j].l1;dt++){
					if (s[si[j].l1 + dt] != t1[k + dt]){
						ok = 0;
						break;
					}
				}
				if (ok){
					for (ll dd = si[j].l2;dd <= si[j].r2;dd++){
						temp[dd - si[j].l2 + k] = s[dd];
					}
					if (!strcmp(temp, t2)){
						ans++;
						break;
					}
					strcpy(temp, t1);
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
