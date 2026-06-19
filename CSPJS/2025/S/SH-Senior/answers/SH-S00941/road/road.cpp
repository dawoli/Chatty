#include<bits/stdc++.h>
using namespace std;
int n,m,k/*,tp1,tp2,tep*/;
long long cnt;
struct side{
	int w,u,v;
}sides[1100001];
int c[11];
int a[11][10001];
int fa[10011];
int _find(int x){
	return fa[x]==x? x:_find(fa[x]);
}
bool cmp(side _n_,side _m_){
	return _n_.w<_m_.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)scanf("%d%d%d",&sides[i].u,&sides[i].v,&sides[i].w);
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)scanf("%d",&a[i][j]);
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			sides[m+j].u=n+i;
			sides[m+j].v=j;
			sides[m+j].w=a[i][j];
		}
		m+=n;
	}
	n+=k;
	for(int i=1;i<=n;i++)fa[i]=i;
	sort(sides+1,sides+1+m,cmp);
	for(int i=1;i<=m;i++){
		int tep1=_find(sides[i].u),tep2=_find(sides[i].v);
		if(tep1!=tep2){
			cnt+=sides[i].w;
			fa[tep1]=tep2;
		}
	}
	printf("%lld",cnt);
	return 0;
}
