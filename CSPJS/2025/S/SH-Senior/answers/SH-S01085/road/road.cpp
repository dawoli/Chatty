#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e4+10,M=1e6+10;
int n,m,k,ans;
int c[15],a[15][N];
struct node {
	int u,v,w,id;
} p[M];
int f[N];
bool cmp(node x,node y) {
	return x.w<y.w;
}
int find(int x) {
	if(x!=f[x]) return f[x]=find(f[x]);
	return x;
}
void solve() {
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++) {
		cin>>p[i].u>>p[i].v>>p[i].w,p[i].id=i;
		if(p[i].u>p[i].v) swap(p[i].u,p[i].v);
	}

	sort(p+1,p+m+1,cmp);
	int is=0;
	for(int i=1; i<=k; i++) {
		cin>>c[i];
		is|=c[i];
		for(int j=1; j<=n; j++)
			cin>>a[i][j],is|=a[i][j];
	}
	if(k==0) {
		for(int i=1; i<=n; i++)
			f[i]=i;
		for(int i=1; i<=m; i++) {
			if(find(p[i].u)!=find(p[i].v)) {
				ans+=p[i].w;
				f[find(p[i].u)]=p[i].v;
			}
		}
		cout<<ans<<"\n";
		return;
	}
	if(!is) {
		cout<<"0\n";
		return ;
	}
	for(int i=1; i<=n; i++)
		f[i]=i;
	for(int i=1; i<=m; i++) {
		if(find(p[i].u)!=find(p[i].v)) {
			ans+=p[i].w;
			f[find(p[i].u)]=p[i].v;
		}
	}
	cout<<ans<<"\n";
}

int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	ios::sync_with_stdio;
//	cin.tie(0);cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--)
		solve();
	return 0;
}

