#include<bits/stdc++.h>
using namespace std;
map<int,int> mp;
int n,k,a[500010],g[500010],f[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;++i)	cin>>a[i];
	for(int i=1;i<=n;++i)	a[i]^=a[i-1],g[i]=-1;
	for(int i=1;i<=n;++i){
		int v=a[i]^k;
		if(v==0)	g[i]=mp[v];
		else if(mp[v])	g[i]=mp[v];
		mp[a[i]]=i;
	} 
	memset(f,-0x3f,sizeof(f));
	f[0]=0;
	int maxn=0;
	for(int i=1;i<=n;++i){
		if(g[i]>=0)	f[i]=max(maxn,f[g[i]]+1),maxn=max(maxn,f[i]);
		else		f[i]=maxn;
	}
	cout<<f[n]<<endl;
}
