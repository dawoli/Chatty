#include<bits/stdc++.h>
using namespace std;
int n,m,k,arr[20][100009],c[20],siz[200009];
int fa[200009],cnt,tt;
long long ans,minn=1e18;

struct Edge{
	int u,v,w;
}e[1000009],edge[100009],de[100009];

int popcount(int x){
	int res=0;
	while(x) res+=x%2,x/=2;
	return res;
}

bool cmp(Edge a,Edge b){
	return a.w<b.w;
}

int find(int a){
	if(fa[a]==a) return a;
	return fa[a]=find(fa[a]);
}

void merge(int u,int v,int w){
//	cout<<"start\n";
	int a=find(u),b=find(v);
	if(a==b) return;
	if(siz[a]>siz[b]) swap(a,b);
	cnt++,ans+=w;
	fa[a]=b,siz[b]+=siz[a];
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++) scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) scanf("%d",&arr[i][j]);
		for(int j=1;j<=n;j++){
			de[++tt].u=n+i,de[tt].v=j,de[tt].w=arr[i][j];
		}
	}
	sort(de+1,de+tt+1,cmp);
	for(int used=0;used<(1<<k);used++){
		int num=popcount(used);
		int tot=0;
		ans=cnt=0;
		for(int i=1;i<=n+k;i++) fa[i]=i,siz[i]=1;
//		for(int i=1;i<=m;i++) edge[i]=e[i];
		for(int i=1;i<=k;i++){
			if(!(used&(1<<(i-1)))) continue;
			ans+=c[i];
		}
		for(int i=1;i<=tt;i++){
			if(used&(1<<(de[i].u-n-1))) edge[++tot]=de[i];
		}
//		sort(edge+1,edge+tot+1,cmp);
		for(int x=0,y=0;(x<m||y<tot)&&cnt<n+num-1;){
			Edge ee;
			if(x<m&&y<tot){
				if(e[x+1].w<edge[y+1].w) ee=e[++x];
				else ee=edge[++y];
			}
			else if(x<m) ee=e[++x];
			else ee=edge[++y];
//			cout<<3<<endl;
//			cout<<ee.u<<endl;
//			cout<<fa[ee.u]<<endl;
			merge(ee.u,ee.v,ee.w);
//			cout<<4<<endl;
			if(ans>minn) break;
		}
//		cout<<ans<<endl;
		minn=min(minn,ans);
	}
	printf("%lld",minn);
	return 0;
}
