#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q;
const int N=2e5+5;
const int M=5e6+5;
int s1[N],s2[N];
int a[N];
int t1[N],t2[N];
map<pair<int,int>,int>mp;
const int mod=998244353;
int myget(string x){
	int ret=0;
	int len=x.size();
	for(int i=0;i<len;i++){
		ret=ret*27+x[i]-'a'+1;
		ret%=mod;
	}
	return ret;
}
int ksm(int a,int b){
	int ret=1;
	while(b){
		if(b&1){
			ret*=a;
			ret%=mod;
		}
		a*=a;
		a%=mod;
		b>>=1;
	}
	return ret;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string l,r;
		cin>>l>>r;
		s1[i]=myget(l);
		s2[i]=myget(r);
		pair<int,int>p;
		p.first=s1[i];
		p.second=s2[i];
		mp[p]++;
	}
	while(q--){
		int ans=0;
		string l,r;
		cin>>l>>r;
		int len=l.size();
		int mx=0;
		int mn=len;
		for(int i=0;i<len;i++){
			if(l[i]!=r[i]){
				mx=max(mx,i);
				mn=min(mn,i);
			}
			t1[i+1]=t1[i]*27+1+(l[i]-'a');
			t2[i+1]=t2[i]*27+1+(r[i]-'a'); 
		}
		if(len>100000){
			cout<<0<<'\n';
			continue;
		}
		for(int i=0;i<=mn;i++){
			for(int j=mx;j<len;j++){
				int l=t1[j+1]-t1[i]*ksm(27,j-i+1);
				int r=t2[j+1]-t2[i]*ksm(27,j-i+1);
				l=(l%mod+mod)%mod;
				r=(r%mod+mod)%mod;
				ans+=mp[make_pair(l,r)];
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
