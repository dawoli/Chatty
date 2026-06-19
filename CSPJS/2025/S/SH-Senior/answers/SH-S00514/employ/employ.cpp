#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
int n,m;
string s;
int a[505],c[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin >> s;
	int sum = 0;
	for(int i = 0;i<n;i++){
		a[i+1] = s[i]-'0';
		sum++;
	}
	for(int i = 1;i<=n;i++) scanf("%d",&c[i]);
	if(n<=10){
		int tmp[20];
		for(int i = 1;i<=n;i++) tmp[i] = i;
		int ans = 0;
		do{
			int num = 0;
			for(int i = 1;i<=n;i++){
				if(a[i] == 0 || num >= c[tmp[i]]) num++;
			}
			if(n-num >= m) ans++;
		}while(next_permutation(tmp+1,tmp+n+1));
		printf("%d",ans);
		/*
		sort(c+1,c+n+1);
		ll ans = 0;
		for(int x = 0;x<(1<<sum);x++){
			if(__builtin_popcount(x) < m) continue;
			ll res = 1;
			int now = 0,yes = __builtin_popcount(x);
			for(int i = n;i>=1;i--){
				if(a[i] == 0) continue;
				now++;
				int need = i-1-yes;
				int num = n-(upper_bound(c+1,c+n+1,need)-c)+1;
				if(x & (1<<(now-1)) == 1) ans = ans*(num-now+1)%mod,yes--;
				else ans = ans*(num-1)%mod;
			}
			ans += res;
		}
		for(int i = 1;i<=n-sum;i++) ans=ans*i%mod;
		printf("%lld",ans);*/
	}
	return 0;
}
/*
3 2
101
1 1 2

10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
