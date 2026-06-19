#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=509;
const ll MOD=998244353;
ll n,m,c[N],ans;
string s;		
map<ll,ll> mp,mp1;
ll tmp=1;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(ll i=1;i<=n;i++){
		cin>>c[i];
		if(!mp[c[i]]) mp[c[i]]=1;
		else mp[c[i]]=mp[c[i]]*(mp[c[i]]+1);
	}
	for(int i=1;i<=n;i++){
		if(!mp1[c[i]]) tmp*=mp[c[i]],mp1[c[i]]=1;
	}
	sort(c+1,c+1+n);
	bool falg=1;
	for(ll i=0;i<s.size();i++){
		if(s[i]!='1') falg=0;
	}
	for(ll i=1;i<=n;i++)
	if(falg){
		ans=1;
		for(ll i=1;i<=n;i++) ans=ans*i%MOD;
		cout<<ans<<endl;
		return 0;
	}
	do{
		ll cnt=0;
		for(ll i=0;i<s.size();i++){
			if(s[i]=='1'&&cnt<c[i+1]) cnt++;
		}
		if(cnt>=m){
			(ans+=tmp)%=MOD;
		}
	}while(next_permutation(c+1,c+1+n));
	cout<<ans%MOD<<endl;
	return 0;
}

