#include<bits/stdc++.h>
using namespace std;
const int maxn=5005;
typedef long long ll;
const ll mod=998244353;
int n,a[maxn];
int s[maxn];
ll f[maxn];
ll g[maxn][maxn];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		s[i]=s[i-1]+a[i];
	}
	sort(a+1,a+n+1);
	f[1]=f[2]=0;
	for(int i=0;i<a[1];i++)g[1][i]=1;
	for(int i=2;i<=n;i++)
	  for(int j=s[i]-1;j>=0;j--){
	  	if(j-a[i]>=0)g[i][j]=(g[i-1][j]%mod+g[i-1][j-a[i]-1]%mod)%mod;
	  	else g[i][j]=(g[i-1][j]%mod+g[i-1][0]%mod)%mod;
	  }
	for(int i=3;i<=n;i++)
	  f[i]=(f[i-1]%mod+g[i-1][a[i]]%mod)%mod,printf("%lld ",f[i]);
	return 0;
}
