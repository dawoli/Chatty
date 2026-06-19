#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll biao=1e5+10;
ll a[biao];
ll cnt[biao];
vector<ll> v;

int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	ll n;
	cin>>n;
	
	bool judge=1;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		cnt[a[i]]++;
	}
		
	for(ll i=1;i<=1e5;i++){
		if(!cnt[i]) continue;
		
		ll tmp=cnt[i];
		while(!v.empty() && tmp>0){
			if(tmp-cnt[v.back()]<0){
				cnt[v.back()]-=tmp;
				tmp=0;
			}
			else{
				tmp-=cnt[v.back()];
				cnt[v.back()]=0;
				v.pop_back();
			}
		}
		
		v.push_back(i);
	}
	
	//for(ll i=0;i<v.size();i++) cout<<v[i]<<" ";
	//cout<<endl;
	
	ll ans=0;
	for(ll i=1;i<=1e5;i++) ans+=cnt[i];
	
	cout<<ans;
	
	return 0;
} 
