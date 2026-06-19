#include<bits/stdc++.h>
using namespace std;
const int maxn = 500 + 10,mod = 998244353;
int n,m,ans;
int c[maxn],p[maxn],f[maxn];
char s[maxn];

bool check(){
	int res = 0;
	for(int i = 1;i <= n;i ++){
		if(i - 1 - res < c[p[i]] && s[i] == '1')	res ++;
	}
	return res >= m;
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d %d",&n,&m);
	scanf("%s",s + 1);
	for(int i = 1;i <= n;i ++){
		scanf("%d",&c[i]);
	}
	f[0] = 1;
	for(int i = 1;i <= n;i ++){
		f[i] = (1LL * f[i - 1] * i) % mod;
	}
	for(int i = 1;i <= n;i ++){
		p[i] = i;
	}
	for(int i = 1;i <= f[n];i ++){
		if(check())	ans ++;
		next_permutation(p + 1,p + n + 1);
	}
	printf("%d",ans);
	return 0;
} 
