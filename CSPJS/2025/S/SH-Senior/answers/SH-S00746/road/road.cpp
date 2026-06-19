#include<bits/stdc++.h>
using namespace std;
#define int long long
const int Maxn=2e6+10;
struct node{int u,v,w;}a[Maxn];
int n,m,k,c[15],i,j,p,cnt,fa[20005],ans=1e16;
bool cmp(node xx,node yy){
	return xx.w<yy.w;
}
int find(int t){
	if(fa[t]==t) return t;
	else return fa[t]=find(fa[t]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k; cnt=m;
	for(i=1;i<=m;i++) cin>>a[i].u>>a[i].v>>a[i].w;
	for(i=1;i<=k;i++){
		cin>>c[i];
		for(j=1;j<=n;j++){
			a[++cnt].u=n+i; a[cnt].v=j;
			cin>>a[cnt].w;
		}
	}
	if(n==1){
		cout<<0<<endl; return 0;
	}
	sort(a+1,a+cnt+1,cmp);
	for(p=0;p<(1<<k);p++){
		int tot=0,sum=0;
		for(i=1;i<=n;i++) fa[i]=i;
		for(i=1;i<=k;i++){
			if(p&(1<<(i-1))) fa[n+i]=n+i,sum+=c[i];
			else fa[n+i]=0,tot++;
		}
		for(i=1;i<=cnt;i++){
			if((!fa[a[i].u])||(!fa[a[i].v])) continue;
			int x=find(a[i].u),y=find(a[i].v);
			if(x!=y){
				fa[x]=y;
				sum+=a[i].w;
				tot++;
				if(tot==n+k-1) break;
			}
		}
		if(tot==n+k-1) ans=min(ans,sum);
	}
	cout<<ans<<endl;
	return 0;
}
