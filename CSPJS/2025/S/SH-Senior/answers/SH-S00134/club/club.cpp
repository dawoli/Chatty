#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1e18 + 7;
char buf[1<<21],*p1,*p2;
#define gc() getchar()
template <typename T>
inline void read(T& x){
	int f = 1;
	x = 0;
	char ch = gc();
	while(!isdigit(ch)){
		if(ch == '-') f = -1;
		ch = gc();
	}
	while(isdigit(ch)){
		x = (x << 1) + (x << 3) + ch - '0';
		ch = gc();
	}
	x *= f;
}
int T,n;
int a[100010][3],id[100010],cnt[3],b[100010],tot = 0;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	read(T);
	while(T--){
		read(n);
		for(int i = 1; i <= n; i++) for(int j = 0; j < 3; j++) read(a[i][j]);
		cnt[0] = cnt[1] = cnt[2] = 0;
		int ans = 0;
		for(int i = 1; i <= n; i++){
			int mx = -INF;
			for(int j = 0; j < 3; j++){
				if(a[i][j] > mx){
					mx = a[i][j],id[i] = j;
				}
			}
			cnt[id[i]]++;
			ans += mx;
		}
		if(cnt[0] <= n / 2 && cnt[1] <= n / 2 && cnt[2] <= n / 2){
			printf("%lld\n",ans);
			continue;
		}
		int op;
		if(cnt[0] > n / 2) op = 0;
		else if(cnt[1] > n / 2) op = 1;
		else op = 2;
		tot = 0;
		int k = cnt[op] - (n / 2);
		for(int i = 1; i <= n; i++){
			if(id[i] == op){
				int lft = -INF;
				for(int j = 0; j < 3; j++) if(j != op) lft = max(lft,a[i][j]);
				b[++tot] = lft - a[i][op];
			}
		}
		sort(b + 1,b + tot + 1);
		for(int i = tot - k + 1; i <= tot; i++) ans += b[i];
		printf("%lld\n",ans);
	} 
	return 0;
}
