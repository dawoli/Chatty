#include<bits/stdc++.h>
using namespace std;

const int N=1e4+20,M=4e6+10;
int n,k,m;
/*
struct edge{
	int u,v,w;
	int m;
}e[M];
bool cmp(edge x,edge y){return x.w<y.w;}
int f[N];
int w[20];
bool used[20];
int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
void merge(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx!=fy) f[fx]=fy;
}

int main(){
//	freopen("road.in","r",stdin);
//	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	int idx=m,idx2=0;
	for(int i=1;i<=k;i++){
		int x;
		cin>>x;
		for(int j=1;j<=n;j++){
			idx++;
			idx2++;
			e[idx].u=idx2+n;
			e[idx].v=j;
			cin>>e[idx].w;
			e[idx].m+=idx;
		}
	}
	sort(e+1,e+1+idx,cmp);
	int cnt=0;
	int ans=0;
	int k=n-1;
	cout<<idx<<"\n";
	for(int i=1;i<=N-5;i++) f[i]=i;
	for(int i=1;i<=n;i++) cout<<f[i]<<" ";
	cout<<"\n";
	for(int i=1;i<=idx;i++){
		cout<<e[i].u<<"("<<find(e[i].u)<<") "<<e[i].v<<"("<<find(e[i].v)<<") "<<" "<<e[i].w<<"\n";
		if(find(e[i].u)!=find(e[i].v)){
			cout<<"used\n";
			merge(e[i].u,e[i].v);
			ans+=e[i].w;
			cnt++;
			if(cnt==k-1) break;
		}
	}
	cout<<ans;
} 

4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
int head[N],w[M],e[M],ne[M];
int dis[N];
bool vis[N],used[20];
int mw[20];
int idx=0;
long long ans=0;
int a[20][N];
void add(int x,int y,int z){
	++idx;
	e[idx]=y;
	w[idx]=z;
	ne[idx]=head[x];
	head[x]=idx;
}
void prim(){
	memset(dis,0x3f,sizeof dis);
	dis[1]=0;
	for(int p=0;p<n;p++){
		int u=0,mins=INT_MAX;
		for(int j=1;j<=n;j++){
			if(dis[j]<mins&&vis[j]==0){
				mins=dis[j];
				u=j;
			}
		}
		vis[u]=1;
		ans+=dis[u];
//		for(int i=1;i<=n;i++) cout<<dis[i]<<" ";
//		cout<<"\n";
//		for(int i=1;i<=n;i++) cout<<vis[i]<<" ";
//		cout<<"\n";
//		cout<<ans<<" ";
		for(int i=head[u];i!=-1;i=ne[i]){
			int v=e[i];
			if(dis[v]>w[i])
				dis[v]=w[i];
		}
//		for(int i=1;i<=n;i++) cout<<dis[i]<<" ";
//		cout<<"\n";
		for(int v=1;v<=n;v++){
			if(v==u) continue;
			for(int j=1;j<=k;j++){
				int nw=a[j][u]+a[j][v];
				if(used[j]==0) nw+=mw[j];
//				cout<<"nw:"<<u<<" "<<j<<" "<<i<<" "<<nw<<"\n";
				if(dis[v]>=nw){
					dis[v]=nw;
					used[j]=1;
				}
			}
		}
	}
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	memset(a,0x3f,sizeof a);
	memset(head,-1,sizeof head);
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		add(x,y,z);
		add(y,x,z);
	}
//	for(int i=1;i<=m*2;i++) cout<<w[i]<<" ";
//	cout<<"\n\n";
	for(int i=1;i<=k;i++){
		int x;
		cin>>x;
		mw[i]=x;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
//	for(int i=1;i<=k;i++){
//		for(int j=1;j<=n;j++){
//			cout<<a[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
//	cout<<"\n";
//	for(int i=1;i<=k;i++) cout<<mw[i]<<" ";
//	cout<<"\n";
	prim();
	cout<<ans;
	return 0;
}
