#include<bits/stdc++.h>
using namespace std;
struct edge {
	int start,end,weight;
} e[1050005];
bool cmp(edge x,edge y) {
	return x.weight<y.weight;
}
int fa[10015];
int find(int x) {
	if(fa[x]==x) return x;
	else return (fa[x]=find(fa[x]));
}
int main() {
	//½â×¢ÊÍ£¡£¡£¡£¡£¡£¡£¡
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++) {
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		e[i].start=u;
		e[i].end=v;
		e[i].weight=w;
	}
	if(k!=0) {
		int aaa;
		for(int i=1; i<=k; i++) {
			cin>>aaa;
			for(int j=1; j<=n; j++) {
				int w;
				scanf("%d",&w);
				e[++m].start=n+i;
				e[m].end=j;
				e[m].weight=w;
			}
		}
		n+=k;
	}
	int ans=0;
	sort(e+1,e+1+m,cmp);
	for(int i=1; i<=n; i++) fa[i]=i;
	for(int i=1; i<=m; i++) {
		int f_1=find(e[i].start),f_2=find(e[i].end);
		if(f_1==f_2) continue;
		fa[f_1]=f_2;
		ans+=e[i].weight;
	}
	cout<<ans;
	return 0;
}
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4
*/
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
0 1 8 2 4
0 1 3 2 4
*/
	/*if(k==0){
		int ans=0;
		sort(e+1,e+1+m,cmp);
		for(int i=1;i<=m;i++) printf("%d %d %d\n",e[i].start,e[i].end,e[i].weight);
		for(int i=1;i<=n;i++) fa[i]=i;
		for(int i=1;i<=m;i++){
			int f_1=find(e[i].start),f_2=find(e[i].end);
			if(f_1==f_2) continue;
			printf("%d %d\n",f_1,f_2);
			fa[f_1]=e[i].end;
			ans+=e[i].weight;
		}
		cout<<ans;
		return 0;
	}*/
