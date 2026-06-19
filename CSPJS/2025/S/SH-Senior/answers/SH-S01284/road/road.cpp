#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100009;
int n,m,k;
struct ed{
	int id,s,t,v;
}e[100000009];
int tp[100009],c[100009];
int dis[100009];
bool vst[N];
int cnt=0;
bool cmp(ed &x,ed &y){
	return x.v<y.v;
}
int fa[N];
struct nd{
	int x;
	int y;
};
int fnd(int x){
	if(fa[x]==x)return x;
	return fa[x]=fnd(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>e[++cnt].s>>e[cnt].t>>e[cnt].v,e[cnt].id=cnt;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>tp[j];
		for(int j=1;j<=n;j++)for(int q=1;q<=n;q++){
			e[++cnt].s=j;
			e[cnt].t=q;
			e[cnt].v=tp[j]+tp[q]+c[i];
			e[cnt].id=cnt;
		}
	}
	sort(e+1,e+cnt+1,cmp);
	int ans=0;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=cnt;i++){
		if(fnd(e[i].t)!=fnd(e[i].s)){
			if(e[i].id>m){
				if(vst[(e[i].id-m-1)/(n*n)+1])e[i].v-=c[(e[i].id-m-1)/(n*n)+1];
				else vst[(e[i].id-m-1)/(n*n)+1]=1;
			}
			cout<<e[i].id<<" "<<e[i].t<<" "<<e[i].s<<" "<<e[i].v<<endl;
			ans+=e[i].v;
			fa[e[i].t]=e[i].s;
		}
	}
	cout<<ans;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
