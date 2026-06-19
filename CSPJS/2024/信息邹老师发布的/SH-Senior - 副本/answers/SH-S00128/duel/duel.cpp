#include<bits/stdc++.h>
#define int long long
using namespace std;
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
int n;
int a[100010];
signed main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	n = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	sort(a + 1,a + n + 1);
	int l = 1,ans = n;
	for(int i = 1; i <= n; i++){
		if(a[l] < a[i]) ans--,l++;
	}
	printf("%lld",ans);
	return 0;
}
