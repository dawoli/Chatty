#include <bits/stdc++.h>
using namespace std;
#define int long long
int t, n, cnta, cntb, cntc, ans, ktot, a[214514], b[214514], c[214514], st[214514][5], cha_ab[214514], cha_bc[214514], cha_ac[214514], chatot[214514];
signed main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%lld", &t);
	while(t--){
		ans = 0;
		cnta = 0;
		cntb = 0;
		cntc = 0;
		ktot = 0;
		scanf("%lld", &n);
		for(int i = 1; i <= n; i++){
			scanf("%lld %lld %lld", &st[i][1], &st[i][2], &st[i][3]);
			cha_ab[i] = st[i][1] - st[i][2];
			cha_bc[i] = st[i][2] - st[i][3];
			cha_ac[i] = st[i][1] - st[i][3];
			if(st[i][1] >= max(st[i][2], st[i][3])){
				ans += st[i][1];
				cnta++;
				a[cnta] = i;
			} else if(st[i][2] >= max(st[i][1], st[i][3])){
				ans += st[i][2];
				cntb++;
				b[cntb] = i;
			} else if(st[i][3] >= max(st[i][2], st[i][1])){
				ans += st[i][3];
				cntc++;
				c[cntc] = i;
			}
		}
		if(cnta > n / 2){
			for(int i = 1; i <= cnta; i++){
				chatot[++ktot] = min(abs(cha_ab[a[i]]), abs(cha_ac[a[i]]));
			}
			sort(chatot + 1, chatot + ktot + 1);
			for(int i = 1; i <= (cnta - (n / 2)); i++){
				ans -= chatot[i];
			}
		} else if(cntb > n / 2){
			for(int i = 1; i <= cntb; i++){
				chatot[++ktot] = min(abs(cha_ab[b[i]]), abs(cha_bc[b[i]]));
			}
			sort(chatot + 1, chatot + ktot + 1);
			for(int i = 1; i <= (cntb - (n / 2)); i++){
				ans -= chatot[i];
			}
		} else if(cntc > n / 2){
			for(int i = 1; i <= cntc; i++){
				chatot[++ktot] = min(abs(cha_bc[c[i]]), abs(cha_ac[c[i]]));
			}
			sort(chatot + 1, chatot + ktot + 1);
			for(int i = 1; i <= (cntc - (n / 2)); i++){
				ans -= chatot[i];
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
