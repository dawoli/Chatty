#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll P=998244353,Q=23255729,N=2e5+5,M=5e6+5;
int n,q;
ll pw[N],qw[N];
pair<ll,ll> gs[M],gt[M];
pair<ll,ll> hs[N],ht[N];
map<pair<ll,ll>,pair<ll,ll>> mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	pw[0]=1;
	qw[0]=1;
	for(int i=1;i<=n;i++){
		pw[i]=pw[i-1]*23%P;
		qw[i]=qw[i-1]*37%Q;
		string s,t;
		cin>>s>>t;
		for(int j=0;j<s.length();j++){
			hs[i].first=(hs[i].first*23%P+s[j])%P;
			hs[i].second=(hs[i].second*37%Q+s[j])%Q;
			ht[i].first=(ht[i].first*23%P+t[j])%P;
			ht[i].second=(ht[i].second*37%Q+t[j])%Q;
		}
		mp[hs[i]]=ht[i];
	}
	while(q--){
		string s,t;
		cin>>s>>t;
		if(s.length()!=t.length()){
			cout<<0<<'\n';
			continue;
		}
		ll ans=0;
		gs[0]={s[0],s[0]},gt[0]={t[0],t[0]};
		for(int i=1;i<s.length();i++){
			gs[i].first=(gs[i-1].first*23%P+s[i])%P;
			gs[i].second=(gs[i-1].second*37%Q+s[i])%Q;
			gt[i].first=(gt[i-1].first*23%P+t[i])%P;
			gt[i].second=(gt[i-1].second*37%Q+t[i])%Q;
		}
		for(int i=1;i<s.length();i++){
			if(gs[s.length()-1].first-gs[i].first*pw[s.length()-i-1]%P==gt[s.length()-1].first-gt[i].first*pw[s.length()-i-1]%P && gs[s.length()-1].second-gs[i].second*qw[s.length()-i-1]%Q==gt[s.length()-1].second-gt[i].second*qw[s.length()-i-1]%Q){
				for(int j=0;j<i;j++){
					if(gs[j]==gt[j] && mp[{gs[i].first-gs[j].first*pw[i-j]%P,gs[i].second-gs[j].second*qw[i-j]%Q}]==mp[{gt[i].first-gt[j].first*pw[i-j]%P,gt[i].second-gt[j].second*qw[i-j]%Q}]){
						ans++;
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
