#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+9,M=1e6+9;
int T,n,a[N],sum[N],lt[M],pre[N],f[N][2],maxn0,maxn1,ans;
void solve(){
	maxn0=maxn1=0;ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==a[i-1]) sum[i]=sum[i-1]+a[i];
		else sum[i]=sum[i-1];
	}
	for(int i=1;i<=n;i++){
		pre[i]=lt[a[i]];
		lt[a[i]]=i;
	}
	pre[n+1]=0;
	for(int i=1;i<=n;i++) lt[a[i]]=0;
	for(int i=1;i<=n;i++){
		f[i][0]=max(sum[i]+maxn1,(pre[i+1]?f[pre[i+1]][1]+sum[i]-sum[pre[i+1]+1]+a[i+1]:0));
		f[i][1]=max(sum[i]+maxn0,(pre[i+1]?f[pre[i+1]][0]+sum[i]-sum[pre[i+1]+1]+a[i+1]:0));
		maxn0=max(maxn0,f[i][0]-sum[i+1]);
		maxn1=max(maxn1,f[i][1]-sum[i+1]);
	}
	sum[n+1]=sum[n];
	for(int i=1;i<=n;i++) ans=max(ans,max(f[i][0],f[i][1])+sum[n]-sum[i+1]);
	cout<<ans<<'\n';
	for(int i=1;i<=n+1;i++) f[i][0]=f[i][1]=0;
}
signed main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T--) solve();
	return 0;
} 
