#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1e16 + 7;
int read(){
	int x = 0,f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		x = (x << 1) + (x << 3) + ch - '0';
		ch = getchar();
	}
	return x * f;
}
int T,n,V;
int a[200010],f[200010],s[200010],g[1000010];
struct Bit{
	int bit[1000010];
	void init(){
		memset(bit,0xcf,sizeof(bit));
	}
	void upd(int i,int v){
		while(i <= V){
			bit[i] = max(bit[i],v);
			i += (i & (-i));
		}
	}
	int psq(int i){
		if(i <= 0) return -INF;
		int res = -INF;
		while(i){
			res = max(res,bit[i]);
			i -= (i & (-i));
		}
		return res;
	}
}B1,B2;
signed main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	T = read();
	while(T--){
		B1.init(),B2.init();
		n = read();
		V = 0;
		for(int i = 1; i <= n; i++) a[i] = read(),g[a[i]] = -INF,V = max(V,a[i]);
		a[n + 1] = -1;
		s[0] = s[1] = 0;
		for(int i = 2; i <= n; i++) s[i] = s[i - 1] + ((a[i] == a[i - 1]) ? a[i] : 0);
		int ans = 0;
		f[0] = 0;
		for(int i = 1; i <= n; i++){
			f[i] = max(s[i],B1.psq(a[i + 1] - 1) + s[i]);
			f[i] = max(f[i],B2.psq(V - a[i + 1]) + s[i]);
			f[i] = max(f[i],g[a[i + 1]] + s[i] + a[i + 1]);
			g[a[i]] = max(g[a[i]],f[i] - s[i + 1]);
			B1.upd(a[i],g[a[i]]);
			B2.upd(V - a[i] + 1,g[a[i]]);
			ans = max(ans,f[i]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
