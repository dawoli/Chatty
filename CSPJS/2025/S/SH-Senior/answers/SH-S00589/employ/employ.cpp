#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, a, b) for(int i = (a); i >= (b); i--)
using namespace std;
typedef long long ll;
const int N = 510;
const ll mod = 998244353;
int n, m, c[N], pos[N];
ll fac[N], f[2][N][N], g[N][N], ans;
char s[N];

int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	fac[0] = 1; rep(i, 1, N-5) fac[i] = fac[i-1] * i % mod;
	scanf("%d%d%s", &n, &m, s+1);
	rep(i, 1, n) scanf("%d", &c[i]);
	sort(c+1, c+n+1);
	per(i, n, 1) if(c[i]) pos[c[i]-1] = i;
	pos[n] = n+1; c[n+1] = n+1;
	per(i, n, 0) if(!pos[i]) pos[i] = pos[i+1];
	f[0][0][0] = 1;
	// fprintf(stderr, "%d %d\n", pos[0], pos[1]);
	rep(i, 1, n){
		int t = i&1;
		memset(f[t], 0, sizeof(f[t]));
		memset(g, 0, sizeof(g));
		rep(j, 0, n) rep(k, 0, n) if(f[!t][j][k]){
			auto trans = [&](int j, int k, ll val){
				assert(i-j-1 >= 0);
				if(pos[i-j-1] == pos[i-j]) (f[t][j][k] += val) %= mod;
				else (g[pos[i-j-1]][k] += val) %= mod;
			};
			if(s[i] == '1') (f[t][j+1][k+1] += f[!t][j][k]) %= mod;
			if(s[i] == '0') trans(j, k+1, f[!t][j][k]);
			if(pos[i-j-1]-i+k > 0)
				trans(j, k, f[!t][j][k] * (pos[i-j-1]-i+k) % mod);
		}
		rep(j, 0, n) rep(k, 0, n) if(g[j][k]){
			if(c[j] == c[j+1]){
				(g[j+1][k] += g[j][k]) %= mod;
				if(k) (g[j+1][k-1] += g[j][k] * k) %= mod;
			}
			else{
				(f[t][i-c[j]][k] += g[j][k]) %= mod;
				if(k) (f[t][i-c[j]][k-1] += g[j][k] * k) %= mod;
			}
		}
		// if(i == 2) fprintf(stderr, "%lld\n", g[2][1]);
		// if(i == 2) fprintf(stderr, "%lld\n", f[t][1][0]);
	}
	rep(i, m, n) rep(j, 0, n) if(f[n&1][i][j] && n-pos[n-i]+1==j)
		(ans += f[n&1][i][j] * fac[j]) %= mod;
	printf("%lld\n", ans);
	return 0;
}

// g++ -std=c++14 -O2 -Wall -Wextra -Wno-unused-result -fsanitize=undefined employ.cpp -o employ
// cp employ1.in employ.in && time ./employ && diff employ.out employ1.ans -b