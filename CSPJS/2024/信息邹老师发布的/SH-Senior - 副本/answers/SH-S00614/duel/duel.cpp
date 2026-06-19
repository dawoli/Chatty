#include<bits/stdc++.h>
#define lowbit(i) (i&(-i))
using namespace std;
typedef long long ll;
ll n,a[100010],b[100010],c[100010],d[100010],cnt,ans;
void add(ll i,ll x){
	for(ll pos=i;pos<=n;pos+=lowbit(pos))c[pos]+=x;
}
ll query(ll x){
	ll res=0;
	for(ll pos=x;pos;pos-=lowbit(pos))res+=c[pos];
	return res;
}
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%lld",&n);
	ans=n;
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]),b[i]=a[i];
	sort(b+1,b+n+1);
	ll e=unique(b+1,b+n+1)-b-1;
	for(int i=1;i<=n;i++)a[i]=lower_bound(b+1,b+e+1,a[i])-b;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		d[query(a[i])]++;
		add(a[i]+1,1);
	}
	for(int i=0;i<n;i++){
		ans-=min(cnt,d[i]);
		cnt=max(cnt,d[i]);
	}
	printf("%lld\n",ans);
	return 0;
}
