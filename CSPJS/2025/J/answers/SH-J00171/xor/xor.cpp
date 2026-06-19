#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node{
	ll l,r;
};
ll n,k,a[500010],sum[500010],cnt;
node seg[5000010];
bool cmp(node x,node y){
	if (x.l<y.l)  return 1;
	else  return ((x.r-x.l+1)<(y.r-y.l+1));
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for (int i=1;i<=n;i++)  cin>>a[i];
	for (int i=1;i<=n;i++)  sum[i]=sum[i-1]^a[i];
	for (ll len=0;len<n;len++){
		for (ll l=1;l+len<=n;l++){
			ll r=l+len;
			if ((sum[r]^sum[l-1])==k){
				node p;
				p.l=l,p.r=r;
				seg[cnt++]=p;
			}
		}
	}
	if (cnt==0){
		cout<<0;
		return 0;
	}
	sort(seg,seg+cnt,cmp);
	ll pre=seg[0].r,ans=1;
	for (int i=1;i<cnt;i++){
		if (seg[i].l<=pre)  continue;
		pre=seg[i].r;
		ans++;
	}
	cout<<ans;
	return 0;
}
