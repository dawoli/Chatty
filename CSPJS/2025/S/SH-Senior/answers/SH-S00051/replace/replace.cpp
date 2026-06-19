#include<bits/stdc++.h>
#define N 300005
typedef long long ll;
using namespace std;
struct PAIRSTR {
	string s1,s2;
	bool operator<(const PAIRSTR&b)const {
		if(s1<b.s1) return 1;
		if(s1>b.s1) return 0;
		return s2<b.s2;
	}
} s[N];
ll n,Q,ans;
map<PAIRSTR,ll> mp;
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>Q;
	if(n<=100&&Q<=100){					//10pts
		for(ll i=1;i<=n;i++) cin>>s[i].s1>>s[i].s2;
		while(Q--){
			string t1,t2;
			cin>>t1>>t2,ans=0;
			for(ll i=1;i<=n;i++){
				if(t1.find(s[i].s1)!=string::npos){
					ll x=t1.find(s[i].s1);
					string t=t1.substr(0,x)+s[i].s2+t1.substr(x+s[i].s1.size(),t1.size());
					if(t==t2) ans++;
				}
			}
			cout<<ans<<"\n";
		}
	}
	else if(Q==1) {
		for(ll i=1; i<=n; i++) {
			cin>>s[i].s1>>s[i].s2;
			if(s[i].s1==s[i].s2) continue;
			if(s[i].s1[0]==s[i].s2[0]) {
				for(size_t j=0; j<s[i].s1.size(); j++) if(s[i].s1[j]==s[i].s2[j]) {
						if(s[i].s1[j+1]!=s[i].s2[j+1]) {
							s[i].s1=s[i].s1.substr(j+1,s[i].s1.size()-1),s[i].s2=s[i].s2.substr(j+1,s[i].s2.size()-1);
							break;
						} else continue;
					}
			}
			if(s[i].s1[s[i].s1.size()-1]==s[i].s2[s[i].s2.size()-1]) {
				for(size_t j=s[i].s1.size()-1; j>=0; j--) if(s[i].s1[j]==s[i].s2[j]) {
						if(s[i].s1[j-1]!=s[i].s2[j-1]) {
							s[i].s1=s[i].s1.substr(0,j-1),s[i].s2=s[i].s2.substr(0,j-1);
							break;
						} else continue;
					}
			}
		}
		while(Q--){
			string t1,t2;
			cin>>t1>>t2,ans=0;
			ll st=-1,ed=-1;
			for(ll i=0; i<t1.size(); i++) {
				if(t1[i]!=t2[i]&&st==-1) st=i;
				if(t1[i]!=t2[i]) ed=i;
			}
			cout<<st<<" "<<ed<<"\n";
			string k1=t1.substr(st,ed-st+1),k2=t2.substr(st,ed-st+1);
			for(ll i=1; i<=n; i++) if(s[i].s1==k1&&s[i].s2==k2) ans++;
			cout<<ans<<"\n";
		}
	} else {
		for(ll i=1; i<=n; i++) {
			cin>>s[i].s1>>s[i].s2;
			if(s[i].s1==s[i].s2) continue;
			if(s[i].s1[0]==s[i].s2[0]) {
				for(size_t j=0; j<s[i].s1.size(); j++) if(s[i].s1[j]==s[i].s2[j]) {
						if(s[i].s1[j+1]!=s[i].s2[j+1]) {
							s[i].s1=s[i].s1.substr(j,s[i].s1.size()-1),s[i].s2=s[i].s2.substr(j,s[i].s2.size()-1);
							break;
						} else continue;
					}
			}
			if(s[i].s1[s[i].s1.size()-1]==s[i].s2[s[i].s2.size()-1]) {
				for(size_t j=s[i].s1.size()-1; j>=0; j--) if(s[i].s1[j]==s[i].s2[j]) {
						if(s[i].s1[j-1]!=s[i].s2[j-1]) {
							s[i].s1=s[i].s1.substr(1,j-1),s[i].s2=s[i].s2.substr(1,j-1);
							break;
						} else continue;
					}
			}
			mp[s[i]]++;
		}
		while(Q--) {
			string t1,t2;
			cin>>t1>>t2,ans=0;
			ll st=-1,ed=-1;
			for(ll i=0; i<t1.size(); i++) {
				if(t1[i]!=t2[i]&&st==-1) st=i;
				if(t1[i]!=t2[i]) ed=i;
			}
			string k1=t1.substr(st,ed-st+1),k2=t2.substr(st,ed-st+1);
			PAIRSTR p= {k1,k2};
			cout<<mp[p]<<"\n";
		}
	}
	//做法错误，求水数据，于16:32放弃 
	return 0;
}
