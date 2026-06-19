#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,q;
ll aj[301100],qj[301100];
ll a[301100],bh[301100];
string s[1130];
map<ll,ll> mp;
ll dfs(ll now,ll js,ll lun){
	if(now==0)return bh[1];
	vector<ll> v,vj;
	for(ll i=1;i<=now;i+=2){
		if(s[js][i/2]=='0'){
			if(a[i]>=lun){
				v.push_back(a[i]);
				vj.push_back(bh[i]);
			}
			else{
				v.push_back(a[i+1]);
				vj.push_back(bh[i+1]);
			}
		}
		else{
			if(a[i+1]>=lun){
				v.push_back(a[i+1]);
				vj.push_back(bh[i+1]);
			}
			else{
				v.push_back(a[i]);
				vj.push_back(bh[i]);
			}
		}
	}
	for(ll i=0;i<v.size();i++){
		a[i+1]=v[i];
		bh[i+1]=vj[i];
	}
	return dfs(now/2,js+1,lun+1);
}
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	srand(time(NULL));
	cin>>n>>q;
	for(ll i=1;i<=n;i++)cin>>aj[i];
	for(ll i=1;i<=q;i++){
		cin>>qj[i];
		ll ji=1;
		while(ji<qj[i]){
			ji*=2;
		}
		qj[i]=ji;
	}
	ll jgs=0;
	while(1){
		jgs++;
		cin>>s[jgs];
		mp[s[jgs].size()]=jgs;
		if(s[jgs].size()==1)break;
	}
	ll T;
	cin>>T;
	while(T--){
		ll x[5];
		cin>>x[0]>>x[1]>>x[2]>>x[3];
		ll ans=0,jans=0;
		for(ll i=1;i<=q;i++){
			jans++;
			for(ll ii=1;ii<=n;ii++)a[ii]=aj[ii]^x[ii%4],bh[ii]=i;
			for(ll o=n+1;o<=qj[i];o++)a[i]=rand()%n,bh[i]=i;
			ans^=(jans*dfs(qj[i],mp[qj[i]],1ll));
		}
		cout<<ans<<endl;
	}
	return 0;
}
