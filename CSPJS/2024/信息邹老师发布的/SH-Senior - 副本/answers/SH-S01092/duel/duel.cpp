#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=100009;
ll r[N],n,ans,cnt[N],fight[N],now,mx,mn=N,kll;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	
	cin>>n;
	for(ll i=1;i<=n;++i){
		cin>>r[i];
		mn=min(mn,r[i]);
		mx=max(mx,r[i]);
	}
	now=mn;
	
	for(ll i=1;i<=n;++i) cnt[r[i]]++;
	for(ll i=1;i<=n;++i) fight[r[i]]++;
	ans=n;
	kll=n;
	
	while(now<=mx&&kll>0){
		kll-=fight[now];
		if(kll<=0) break;
		
		ll op=min(kll,cnt[now]);
		ans-=op;
		kll-=op;
		cnt[now]-=op;
		ll num=now+1;
		
		while(op>0){
			ll op2=min(op,fight[num]);
			fight[num]-=op2;
			op-=op2;
			num++;
		}
		
		now++;
	}

	cout<<ans<<endl;
	
	return 0;
}
