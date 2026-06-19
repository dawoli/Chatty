#include <bits/stdc++.h>
using namespace std;
int n,a[200010],buc[1000010];
int lst[200010];
typedef long long ll;
ll F,dp[200010];
ll BIT[200010];
ll query(int x){
	ll tmp=0;for(;x;x-=x&(-x))tmp=max(tmp,BIT[x]);return tmp;
}
void add(int x,ll val){
	for(;x<=n;x+=x&(-x))BIT[x]=max(BIT[x],val);
}
void solve(){
	scanf("%d",&n);F=0;
	memset(buc,0,sizeof(buc));
	memset(dp,0,sizeof(dp));
	memset(BIT,0,sizeof(BIT));
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		lst[i]=buc[a[i]];buc[a[i]]=i;
	}
	for(int i=2;i<=n;i++){
		if(lst[i]==i-1)F+=a[i];
		else if(lst[i]){
			dp[i]=a[i]+query(lst[i]+1);
			add(i,dp[i]);
		}
	}
	for(int i=1;i<n;i++){
		dp[n]=max(dp[n],dp[i]);
	}
	printf("%lld\n",F+dp[n]);
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T;scanf("%d",&T);while(T--)solve();
	return 0;
}
