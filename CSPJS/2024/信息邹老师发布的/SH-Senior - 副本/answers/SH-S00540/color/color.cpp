#include<bits/stdc++.h>
#define N 200005
#define M 1000005
#define int long long
#define INF 5114514114514114514ll
#define DEBUG 0
using namespace std;
int n,m,a[N],g[M];
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	m=*max_element(a+1,a+1+n)+1;
	for(int i=1;i<=m;i++)g[i]=-INF;
	g[m+1]=0;
	int v1=0,v2=0,v3=0,tg=0;
	for(int i=1;i<n;i++){
		if(a[i]==a[i+1])v1=a[i];else v1=0;
		if(g[a[i+1]]>-INF)v3=g[a[i+1]]+tg+a[i+1];else v3=0;
		tg+=v1;
		g[a[i]]=max(v2,v3)-tg;
		v2=max(v2+v1,v3);
		if(DEBUG){
		cerr<<v2<<' '<<tg<<' ';
		for(int j=1;j<=m+1;j++)cerr<<g[j]<<'\t';
		cerr<<'\n';
		}
	}
	cout<<v2<<'\n';
}
signed main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int T=1;cin>>T;
	while(T--)solve();
	return 0;
}