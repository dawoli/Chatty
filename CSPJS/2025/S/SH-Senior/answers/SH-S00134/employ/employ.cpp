#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 998244353;
int qpow(int a,int b){
	int res = 1;
	for( ; b; b >>= 1){
		if(b & 1) res = (res * a) % MOD;
		a = (a * a) % MOD;
	}
	return res;
}
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
int n,m;
char s[510];
int cnt[510],cc[510];
int f[2][510][510][2],fac[510],ifac[510]; //j: already ok,k: up left to decide
int A(int x,int y){
	if(x < 0 || y < 0 || x < y) return 0;
	return fac[x] * ifac[x - y] % MOD;
}
int c[510],p[510];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	fac[0] = 1;
	for(int i = 1; i <= 505; i++) fac[i] = fac[i - 1] * i % MOD;
	ifac[505] = qpow(fac[505],MOD - 2);
	for(int i = 504; i >= 0; i--) ifac[i] = ifac[i + 1] * (i + 1) % MOD;
	read(n),read(m);
	scanf("%s",s + 1);
	for(int i = 1; i <= n; i++) read(c[i]),p[i] = i;
	if(n <= 10){
		int ans = 0;
		do{
			int gu = 0;
			for(int i = 1; i <= n; i++){
				if(s[i] == '0'){
					gu++;
				}
				else{
					if(gu >= c[p[i]]) gu++;
				}
			}
			if(n - gu >= m) ans++;
		}
		while(next_permutation(p + 1,p + n + 1));
		printf("%lld",ans);
		return 0;
	}
	bool flag = 1;
	for(int i = 1; i <= n; i++) flag &= (s[i] == '1');
	if(m == n){
		for(int i = 1; i <= n; i++) flag &= (c[i] >= 1);
		if(flag){
			int ans = 1;
			for(int i = 1; i <= n; i++) (ans *= i) %= MOD;
			printf("%lld",ans);
			return 0;
		}
		printf("0");
		return 0;
	}
	if(m == 1){
		int ans = 1;
		for(int i = 1; i <= n; i++) cnt[c[i]]++;
		for(int i = 1; i <= n; i++) cnt[i] += cnt[i - 1];
		int ooo = 0;
		for(int i = 1; i <= n; i++){
			if(s[i] == '0') continue;
			int x = i - 1;
			(ans *= (cnt[x] - ooo)) %= MOD;
			ooo++;
		}
		int ccc = 0;
		for(int i = 1; i <= n; i++) if(s[i] == '0') ccc++;
		(ans *= fac[ccc]) %= MOD;
		int ALL = fac[n];
		ans = (ALL - ans + MOD) % MOD;
		printf("%lld",ans);
		return 0;
	}
	return 0;
}
/*
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 998244353;
int qpow(int a,int b){
	int res = 1;
	for( ; b; b >>= 1){
		if(b & 1) res = (res * a) % MOD;
		a = (a * a) % MOD;
	}
	return res;
}
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
int n,m;
char s[510];
int cnt[510],cc[510];
int f[2][510][510][2],fac[510],ifac[510]; //j: already ok,k: up left to decide
int A(int x,int y){
	if(x < 0 || y < 0 || x < y) return 0;
	return fac[x] * ifac[x - y] % MOD;
}
signed main(){
	fac[0] = 1;
	for(int i = 1; i <= 505; i++) fac[i] = fac[i - 1] * i % MOD;
	ifac[505] = qpow(fac[505],MOD - 2);
	for(int i = 504; i >= 0; i--) ifac[i] = ifac[i + 1] * (i + 1) % MOD;
	read(n),read(m);
	scanf("%s",s + 1);
	for(int i = 1,x; i <= n; i++) read(x),cnt[x]++,cc[x]++;
	for(int i = 1; i <= n; i++) cnt[i] += cnt[i - 1];
	f[0][0][0][0] = 1;
	int ccc = 0;
	for(int i = 1; i <= n; i++){
		memset(f[i & 1LL],0,sizeof(f[i & 1LL]));
		for(int j = 0; j < i; j++){
			for(int k = 0; k < i; k++){
				for(int pp = 0; pp < 2; pp++){
					if(!f[i & 1LL ^ 1LL][j][k][pp]) continue;
					printf("? %lld %lld %lld %lld %lld\n",i - 1,j,k,pp,f[i & 1LL ^ 1LL][j][k][pp]);
					int p = i - j;
					if(s[i] == '0'){
						for(int kk = 0; kk <= k && kk <= cc[p]; kk++){
							printf("!! %lld %lld\n",kk,k);
							int coef = A(cc[p],kk);
							(f[i & 1LL][j][k - kk][0] += f[i & 1LL ^ 1LL][j][k][pp] * coef % MOD) %= MOD;
						}
					}
					else{
						for(int kk = 0; kk <= k && kk <= cc[p]; kk++){
							int coef = A(cc[p],kk) * f[i & 1LL ^ 1LL][j][k][pp] % MOD;
							int sum = j - (k - kk) + i - 1 - j - ccc;
							int lft = cnt[p] - sum;
							(f[i & 1LL][j][k - kk][0] += coef * lft % MOD) %= MOD;
						}
						(f[i & 1LL][j + 1][k + 1][1] += f[i & 1LL ^ 1LL][j][k][pp]) %= MOD;
					}
				}
			}
		}
		if(s[i] == '0') ccc++;
	}
	int ans = 0;
	for(int j = m; j <= n; j++){
		for(int k = 0; k <= n; k++){
			for(int pp = 0; pp < 2; pp++){
				if(!f[n & 1LL][j][k][pp]) continue;
				printf("? %lld %lld %lld %lld %lld\n",n,j,k,pp,f[n & 1LL][j][k][pp]);
				int lft = n - j + pp;
				int qq = cnt[n] - (lft <= 0 ? 0 : cnt[lft - 1]);
				int coef = A(qq,k);
				(ans += coef * f[n & 1LL][j][k][pp] % MOD) %= MOD;
			}
		}
	}
	printf("%lld",ans * fac[ccc] % MOD);
	return 0;
}
*/
