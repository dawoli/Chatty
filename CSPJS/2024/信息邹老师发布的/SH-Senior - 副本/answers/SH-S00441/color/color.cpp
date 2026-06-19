#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
ll ja[301100];
ll a[301100];
ll sy[1000005];
ll dp[301100][2];
ll fli[301100];
ll qzh[301100];
struct z{
	ll l,r,mx,mx2;
}tr[813100];
void build(ll now,ll l,ll r){
	tr[now].l=l;
	tr[now].r=r;
	tr[now].mx=tr[now].mx2=0;
	if(l==r)return;
	ll mid=(l+r)/2;
	build(now*2,l,mid);
	build(now*2+1,mid+1,r);
	return;
}
void add(ll now,ll l,ll zhi,ll zhi2){
	if(tr[now].r<l||tr[now].l>l)return;
	if(tr[now].l==tr[now].r&&tr[now].l==l){
		tr[now].mx=zhi;
		tr[now].mx2=zhi2;
		return;
	}
	add(now*2,l,zhi,zhi2);
	add(now*2+1,l,zhi,zhi2);
	tr[now].mx=max(tr[now*2].mx,tr[now*2+1].mx);
	tr[now].mx2=max(tr[now*2].mx2,tr[now*2+1].mx2);
}
ll find1(ll now,ll l,ll r){
	if(tr[now].r<l||tr[now].l>r)return 0;
	if(tr[now].l>=l&&tr[now].r<=r)return tr[now].mx;
	return max(find1(now*2,l,r),find1(now*2+1,l,r));
}
ll find2(ll now,ll l,ll r){
	if(tr[now].r<l||tr[now].l>r)return 0;
	if(tr[now].l>=l&&tr[now].r<=r)return tr[now].mx2;
	return max(find2(now*2,l,r),find2(now*2+1,l,r));
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	ll T;
	cin>>T;
	while(T--){
		cin>>n;
		build(1,1,n);
		memset(sy,0,sizeof(sy));
		memset(dp,0,sizeof(dp));
		memset(fli,0,sizeof(fli));
		memset(qzh,0,sizeof(qzh));
		for(ll i=1;i<=n;i++)cin>>ja[i];
		ll jn=0;
		ll jans=0;
		for(ll i=1;i<=n;i++){
			jn++;
			a[jn]=ja[i];
			if(i>1&&ja[i-1]==ja[i]){
				jn--;
				jans+=ja[i];
			}
		}
		ll ans=0;
		for(ll i=1;i<=jn;i++){
			qzh[i]=qzh[i-1];
			/*cout<<a[i]<<endl;
			dp[i][0]=max(max(dp[i-1][0],dp[i-1][1]),dp[i][0]);
			dp[i][1]=max(max(dp[i-1][0],dp[i-1][1]),dp[i][1]);
			if(i>1&&a[i+1]==a[i-1]&&i<jn)fli[i]=a[i+1];
			if(!sy[a[i]]){
				sy[a[i]]=i;
				continue;
			}
			dp[i][1]=max(dp[i][1],dp[sy[a[i]]][1]+a[i]+fli[sy[a[i]]]);
			dp[i][0]=max(dp[i][0],dp[sy[a[i]]][0]+a[i]);
			sy[a[i]]=i;
			ans=max(ans,dp[i][0]);
			ans=max(ans,dp[i][1]+fli[i]);
			//cout<<ans<<" "<<fli[i]<<endl;*/
			if(!sy[a[i]]){
				sy[a[i]]=i;
				continue;
			}
			dp[i][0]=find2(1,sy[a[i]]+1,sy[a[i]]+1)+a[i]+qzh[sy[a[i]]];
			dp[i][1]=find1(1,sy[a[i]]+1,sy[a[i]]+1)+a[i]+qzh[sy[a[i]]];
			qzh[i]=max(dp[i][0],max(dp[i][1],qzh[i-1]));
			ans=max(ans,max(dp[i][0],dp[i][1]));
			//add(1,i,dp[i][0],dp[i][1]);
			add(1,i,a[i],a[i]);
			sy[a[i]]=i;
		}
		cout<<ans+jans<<endl;
	}
	return 0;
}
