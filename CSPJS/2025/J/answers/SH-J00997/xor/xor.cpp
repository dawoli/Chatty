#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=500009;
ll n,k,a[N];
ll s[N],f[N];
//struct p{
//	ll id,d;
//}pr[N];
//bool cmp(const p &x,const p &y){
//	if(x.d<y.d) return 1;
//	if(x.d>y.d) return 0;
//	return x.id<y.id;
//}//优先数值从小到大，其次编号从小到大 
map<ll,ll> mp;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(ll i=1;i<=n;i++) cin>>a[i];
	for(ll i=1;i<=n;i++) s[i]=s[i-1]^a[i];
//	for(ll i=1;i<=n;i++) pr[i]=(p){i,s[i]};
//	sort(pr+1,pr+1+n,cmp);
//	for(ll i=1;i<=n;i++) cout<<pr[i].id<<' '<<pr[i].d<<endl;
	//dp
	mp[0]=-1;
	for(ll i=1;i<=n;i++){
		f[i]=f[i-1];
		//find: s[j-1]=s[i] xor k 找最后一个（id最大） 
//		ll l=1,r=i-1,tofind=s[i]^k;
//		while(l<r){
//			ll mid=ceil((l+r)*1.0/2);
//			//pr[mid]==s[i]^k
//			if(pr[mid].d<=tofind) l=mid;
//			else r=mid-1;
//		}
//		if(pr[l].d!=tofind) continue;
//		ll j=pr[l].id+1;
//		f[i]=max(f[i],f[j]+1);
		ll tofind=s[i]^k;
		if(a[i]==k) f[i]=f[i-1]+1;
		else{
			ll foundad=mp[tofind];
			if(foundad) f[i]=max(f[i],f[foundad]+1);
		}
		mp[s[i]]=i;
	}
	cout<<f[n]<<endl;
//	for(ll i=1;i<=n;i++) cout<<f[i]<<' ';
	return 0;
}
