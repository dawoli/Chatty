#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll biao=1e6+10;
string s1[biao],s2[biao],sa,sb;
ll n,q;

void solve(){
	while(q--){
		cin>>sa>>sb;
		if(sa.size()!=sb.size()){
			cout<<0<<'\n';
			continue;
		}
		ll loca=0,locb=0;
		for(ll i=0;i<sa.size();i++){
			if(sa[i]=='b') loca=i;
			if(sb[i]=='b') locb=i;
		}
		ll ans=0;
		for(ll i=1;i<=n;i++){
			ll loc1=0,loc2=0;
			for(ll j=0;j<s1[i].size();j++){
				if(s1[i][j]=='b') loc1=j;
				if(s2[i][j]=='b') loc2=j;
			}
			if(loc1-loc2!=loca-locb) continue;
			if(loc1<loca && loc2<locb){
				if(sa.size()-loca+1>s1[i].size()-loc1+1 && sb.size()-locb+1>s2[i].size()-loc2+1){
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>q;
	bool judge=1;
	for(ll i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		ll cnt1=0,cnt2=0;
		for(ll j=0;j<s1[i].size();j++){
			if(!judge) break;
			if(s1[i][j]!='a' && s1[i][j]!='b') judge=0;
			if(s2[i][j]!='a' && s2[i][j]!='b') judge=0;
			if(s1[i][j]=='b') cnt1++;
			if(s2[i][j]=='b') cnt2++;
			if(cnt1>1 || cnt2>1) judge=0;
		}
	}
	if(judge){
		solve();
		return 0;
	}
	while(q--){
		cin>>sa>>sb;
		if(sa.size()!=sb.size()){
			cout<<0<<'\n';
			continue;
		}
		ll ans=0;
		for(ll i=1;i<=n;i++){
			for(ll j=0;j+s1[i].size()-1<sa.size();j++){
				string ta=sa,tb=sb;
				if(sa.substr(j,s1[i].size())!=s1[i]) continue;
				for(ll k=0;k<s1[i].size();k++) ta[k+j]=s2[i][k];
//				cout<<ta<<" "<<tb<<'\n';
				if(ta==tb) ans++;
			}
		}
		cout<<ans<<'\n';
	}
	
	return 0;
} 
