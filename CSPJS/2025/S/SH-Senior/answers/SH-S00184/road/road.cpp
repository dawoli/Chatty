#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=10015,M=2020005;
int head[N],cnt=0,val[11];
	int n,m,k;
	int pp=0;
bool cal[11];
struct edge{
	int v,w,u;
}e[M];
struct group{
	int fa,num;
}a[N];
void add(int u,int v,int w){
	e[++cnt].v=v;
	e[cnt].w=w;
	e[cnt].u=u;
//	head[u]=cnt;
}
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int search(int x){
	if (a[x].fa==x)
		return x;
	else search(a[x].fa);
}
void connect(int x,int y){
	int xx=search(x),yy=search(y);
	a[xx].fa=yy;
	a[yy].num+=a[xx].num;
}
int scs(){
	for(int i=1;i<=n;i++){
		a[i].fa=i;
		a[i].num=1;
	}
	int ans=0;
	for(int i=1;i<=cnt;i++){
		if(a[search(e[i].v)].num==n+pp)break;//nÎªµãÊı 
		if(search(e[i].v)==search(e[i].u))continue;
		if(e[i].v>n)
		if(cal[e[i].v-n]==0)continue;
		if(e[i].u>n)
		if(cal[e[i].u-n]==0)continue;
		ans+=e[i].w;
		connect(e[i].v,e[i].u);
	}
	return ans;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
	//	add(v,u,w);
	}
	for(int i=1;i<=k;i++){
		cin>>val[i];
		for(int j=1;j<=n;j++){
			int w;
			cin>>w;
			add(n+i,j,w);
		}
	}
	sort(e+1,e+cnt+1,cmp);
	int ans=0;
	int aa=1e15;
	for(int i=0;i<(1<<k);i++){
		ans=0;pp=0;
		for(int j=1;j<=k;j++){
			cal[j]=0;
		}
		for(int j=1;j<=k;j++){
			if(i&(1<<(j-1)))cal[j]=1,ans+=val[j],pp++;
		}
		ans+=scs();
		aa=min(aa,ans);
	}
	cout<<aa;
	return 0;
}
