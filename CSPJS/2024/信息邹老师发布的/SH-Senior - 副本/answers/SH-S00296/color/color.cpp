#include <iostream>
#include <cstdio>
#include <fstream>
#include <cstring>
#include <bitset>
using namespace std;
const int MAXN = 2e4 + 5, MAXM = 1e6 + 5;
int T;
int n;
long long currans;
long long a[MAXN], s[MAXN], f[MAXN][2];
bitset<MAXN> g[MAXN][2];
bitset<MAXN> zero;
int h[MAXM], nxt[MAXN];
long long getrange(int l, int r){
	if(l >= r)return 0;
	long long res = s[r] - s[l - 1];
	if(a[l] == a[l - 1]){
		res -= a[l];
	}
	return res;
}
int main(){
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	scanf("%d", &T);
	while(T--){
		memset(h, 0, sizeof(h));
		memset(nxt, 0, sizeof(nxt));
		scanf("%d", &n);
		for(int i = 1;i <= n;i++){
			scanf("%lld", &a[i]);
			nxt[i] = h[a[i]];
			h[a[i]] = i;
			s[i] = s[i - 1];
			if(a[i] == a[i - 1]){
				s[i] += a[i];
			}
		}
		for(int i = 1;i <= n;i++){
			for(int j = 0;j < 2;j++){
				g[i][j] = zero;
			}
		} 
		for(int i = 1;i <= n;i++){
			f[i][0] = f[i][1] = getrange(1, i);
			if(a[i] == a[i - 1]){
				f[i][0] = max(f[i][0], f[i - 1][0] + a[i]);
				f[i][1] = max(f[i][1], f[i - 1][1] + a[i]);
			}else{
				f[i][0] = max(f[i][0], f[i - 1][0]);
				f[i][1] = max(f[i][1], f[i - 1][1]);
			}
			g[i][0] = g[i - 1][0];
			g[i][1] = g[i - 1][1];
			for(int j = nxt[i];j;j = nxt[j]){
				if(j == i - 1)continue;
				for(int k = 0;k < 2;k++){
					currans = f[j - 1][k] + a[j] + getrange(j + 1, i - 1);
					if(a[j] == a[j - 1])currans += a[j];
					if(g[j - 1][k][a[j + 1]])currans += a[j + 1];
					if(currans > f[i][k]){
						f[i][k] = currans;
						g[i][k] = zero;
						g[i][k][a[i - 1]] = 1;
					}else if(currans == f[i][k]){
						g[i][k][a[j - 1]] = 1;
					}
					currans = f[j - 1][!k] + a[j] + getrange(j + 1, i - 1);
					if(a[j + 1] == a[j - 1])currans += a[j - 1];
					if(g[j - 1][!k][a[j]])currans += a[j];
					if(currans > f[i][k]){
						f[i][k] = currans;
						g[i][k] = zero;
						g[i][k][a[i - 1]] = 1;
					}else if(currans == f[i][k]){
						g[i][k][a[i - 1]] = 1;
					}
				}
			}
		}
		printf("%lld\n", max(f[n][0], f[n][1]));
	}
	return 0;
} 
/*
3
3
1 2 1
4
1 2 3 4
8
3 5 2 5 1 2 1 4
*/
