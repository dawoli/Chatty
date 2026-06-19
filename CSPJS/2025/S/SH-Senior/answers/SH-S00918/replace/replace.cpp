#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=200015;
const int P=131,mod=998244353;
int hsh_a[N],hsh_b[N];
int p[N];
int ha[N],hb[N];
int l[N];
int query_a(int l,int r){
	l++,r++;
	return (ha[r]-ha[l-1]*p[r-l+1]%mod+mod)%mod;
}
int query_b(int l,int r){
	l++,r++;
	return (hb[r]-hb[l-1]*p[r-l+1]%mod+mod)%mod;
}
map<int,bool>mp;
int hsh_p(int x,int y){
	return (x*114514ll%mod+y*1919810ll%mod+x*y%mod+(x-y+mod)%mod)%mod;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	p[0]=1;
	for(int i=1;i<=200005;i++){
		p[i]=p[i-1]*P%mod;
	}
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string a,b;
		cin>>a>>b;
		l[i]=a.size();
		hsh_a[i]=0,hsh_b[i]=0;
		for(int j=0;j<a.size();j++){
			hsh_a[i]=(hsh_a[i]*P%mod+a[j])%mod;
			hsh_b[i]=(hsh_b[i]*P%mod+b[j])%mod;
		}
		mp[hsh_p(hsh_a[i],hsh_b[i])]=1;
	}
	while(q--){
		string a,b;
		cin>>a>>b;
		if(a.size()!=b.size()){
			cout<<0<<endl;
			continue;
		}
		int len=a.size();
		for(int i=1;i<=len;i++){
			ha[i]=(ha[i-1]*P%mod+a[i-1])%mod;
			hb[i]=(hb[i-1]*P%mod+b[i-1])%mod;
		}
		int ans=0;
		for(int j=0;j<len;j++){
			if(j>0&&query_a(0,j-1)!=query_b(0,j-1))break;
			for(int k=len-1;k>=j;k--){
				if(k<len-1&&query_a(k+1,len-1)!=query_b(k+1,len-1))break;
				if(mp.count(hsh_p(query_a(j,k),query_b(j,k)))){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
