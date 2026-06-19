#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2009,B=605,mod=1e9+9;
int n,q,h[N],s1[N],s2[N],cnt,t1[N],t2[N];
unordered_map<int,int> mp;
vector<int> v[N];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	h[0]=1;for(int i=1;i<N;i++) h[i]=h[i-1]*B%mod;
	for(int i=1;i<=n;i++){
		string s,t;cin>>s>>t;
		for(int j=0;j<s.size();j++) s1[i]=(s1[i]*B+s[j])%mod;
		for(int j=0;j<t.size();j++) s2[i]=(s2[i]*B+t[j])%mod;
		if(!mp[s1[i]]) mp[s1[i]]=++cnt;
		v[mp[s1[i]]].push_back(i);
	}
	while(q--){
		string s,t;cin>>s>>t;
		if(s.size()!=t.size()){
			puts("0");
			continue;
		}
		int m=s.size(),l=0,r=m+1,ans=0;
		while(l<m&&s[l]==t[l]) l++;
		while(r-2>=0&&s[r-2]==t[r-2]) r--;
		for(int i=1;i<=m;i++) t1[i]=(t1[i-1]*B+s[i-1])%mod;
		for(int i=1;i<=m;i++) t2[i]=(t2[i-1]*B+t[i-1])%mod;
		for(int i=0;i<=l;i++)for(int j=r;j<=m+1;j++){
			int lb=i+1,rb=j-1,len=rb-lb+1;
			int g1=(t1[rb]-t1[lb-1]*h[len]%mod+mod)%mod;
			int g2=(t2[rb]-t2[lb-1]*h[len]%mod+mod)%mod;
			if(!mp[g1]) continue;
			int key=mp[g1];
			for(int k=0;k<v[key].size();k++){
				if(s2[v[key][k]]==g2) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
