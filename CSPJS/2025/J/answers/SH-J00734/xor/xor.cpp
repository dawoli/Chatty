#include <bits/stdc++.h>
using namespace std;
int n,m,a[500010],tot = 1;
struct seg{int l,r;}s[1000010];
bool cmp(seg a,seg b){return a.r == b.r ? a.l < b.l : a.r < b.r;}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> a[i];
	for (int i = 1;i <= n;i++){
		for (int j = i;j <= n;j++){
			int tmp = 0;
			for (int k = i;k <= j;k++) tmp ^= a[k];
			if (tmp == m) s[tot].l = i,s[tot++].r = j;
		}
	}
	sort(s+1,s+tot,cmp);
	int last = -1,cnt = 0;
	for (int i = 1;i < tot;i++){
		if (s[i].l <= last) continue;
		last = s[i].r;
		cnt++;
	}
	cout << cnt;
}
