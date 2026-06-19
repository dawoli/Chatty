#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505;
int n,m,c[N];
char s[N];
int p[N],sum,rtn,ans;
bool vst[N];
inline void check(){
	rtn=sum=0;
	for(int i=1;i<=n;++i){
		if(s[i]=='1'&&sum<c[p[i]]) rtn++;
		else sum++;
	}
	if(rtn>=m){
		ans++;
		ans%=998244353;
	}
}
inline void dfs(int x){
	if(x==n+1) check();
	for(int i=1;i<=n;++i){
		if(vst[i]) continue;
		p[x]=i;
		vst[i]=1;
		dfs(x+1);
		vst[i]=0;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>s[i];
	for(int i=1;i<=n;++i) cin>>c[i];
	dfs(1);
	cout<<ans;
	return 0;
}
