#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
const ll mul=998244353;
const int N=200099;
const int L=5000009;
int n,q;
int len[N],df[N],lf[N],rg[N];
ll pw[L];
ll h1[N],h2[N];
ll hs1[L],hs2[L];
string s1,s2;
ll get1(int l,int r){
	return (hs1[r]-hs1[l-1]*pw[r-l+1]%mod+mod)%mod;
}
ll get2(int l,int r){
	return (hs2[r]-hs2[l-1]*pw[r-l+1]%mod+mod)%mod;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	pw[0]=1;
	for(int i=1;i<L;i++)
		pw[i]=pw[i-1]*mul%mod;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		len[i]=s1.size();
		if(s1!=s2){
			for(int j=0;j<len[i];j++)
				if(s1[j]!=s2[j]){
					lf[i]=j+1;
					break;
				}
			for(int j=len[i]-1;j>=0;j--)
				if(s1[j]!=s2[j]){
					rg[i]=j+1;
					break;
				}
			df[i]=rg[i]-lf[i]+1;
		}
		for(int j=0;j<len[i];j++){
			h1[i]=(h1[i]*mul+s1[j])%mod;
			h2[i]=(h2[i]*mul+s2[j])%mod;
		}
	}
	int d,l,r,le;
	while(q--){
		cin>>s1>>s2; le=s1.size();
		for(int i=1;i<=le;i++){
			hs1[i]=(hs1[i-1]*mul+s1[i-1])%mod;
			hs2[i]=(hs2[i-1]*mul+s2[i-1])%mod;
		}
		for(int j=0;j<le;j++)
			if(s1[j]!=s2[j]){
				l=j+1;
				break;
			}
		for(int j=le-1;j>=0;j--)
			if(s1[j]!=s2[j]){
				r=j+1;
				break;
			}
		d=r-l+1;
		int ans=0;
		for(int i=1;i<=n;i++){
			if(d!=df[i]) continue;
			if(lf[i]>l) continue;
			if(len[i]-rg[i]>le-r) continue;
			if(get1(l-lf[i]+1,r+len[i]-rg[i])==h1[i]
			 &&get2(l-lf[i]+1,r+len[i]-rg[i])==h2[i])
				ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
