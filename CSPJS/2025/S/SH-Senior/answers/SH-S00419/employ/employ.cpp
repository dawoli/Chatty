#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
const int mod = 998244353;
int n, m, cnt, tot;
int ans;
int c[1010], res[1010];
int a[1010];
bool vis[1010];
void solve(){
	for(int i=1; i<=n; ++i) res[i] = i;
	do{
		for(int i=1; i<=n; ++i){
			if(a[i] == 0){
				cnt++;	
				continue;
			}
			if(cnt<c[res[i]]) tot++;
			else cnt++;
		}
		if(tot>=m) ans++;
		cnt = 0, tot = 0;
	}while(next_permutation(res+1, res+n+1));
}
int read(){
	int x=0, f=1;
	char c=' ';
	for(; !isdigit(c); c=getchar()){
		if(c=='-') f=-1;
	}
	for(; isdigit(c); c=getchar()){
		x = (x<<3)+(x<<1)+(c^48);	
	}
	return x*f;
}
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout); 
	n = read(), m = read();
	for(int i=1; i<=n; ++i){
		scanf("%1d", &a[i]);
	}
	for(int i=1; i<=n; ++i){
		c[i] = read();	
	}
	solve();
	printf("%d", ans);
	return 0;
}

