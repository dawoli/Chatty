#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
const int M=2*1e5+10;
int n,m,k;int edge[N][4];
int f[11][N];

int cnt;
int h[N];int e[M];int w[M];int nxt[M];
void add(int u,int v,int c){
	++cnt;
	e[cnt]=v;w[cnt]=c;
	nxt[cnt]=h[u];
	h[u]=cnt;
	return ;
}
bool checked[N];
int dis[N][N];
void dijkstra(int s){
	queue<pair<int,int> > q;
	dis[s][s]=0;
	q.push({s,0});
	while(!q.empty()){
		int u=q.front().first;int ds=q.front().second;
		q.pop();
		if(checked[u]) continue;
		for(int i=h[u];i!=-1;i=nxt[i])
			if(dis[s][e[i]]>ds+w[i]){
				dis[s][e[i]]=ds+w[i];
				q.push({e[i],dis[s][e[i]]});
			}
	}
	return ;
}
void solve(){
	for(int i=1;i<=n+k+1;i++)
		dijkstra(i);
}
int main(){
	//I forot how to apply minimum summoned tree
	//So I just performed a dijkstra =(
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		cin>>edge[i][1]>>edge[i][2]>>edge[i][3];
	for(int i=1;i<=k;i++){
		cin>>f[i][0];
		for(int j=1;j<=n;j++)
			cin>>f[i][j];
	}
	int mn=0x7f7f7f7f;
	for(int i=0;i<=pow(2,k)-1;i++){
		cnt=0;
		memset(h,-1,sizeof(h));
		memset(e,0,sizeof(e));
		memset(w,0,sizeof(w));
		memset(nxt,-1,sizeof(nxt));
		memset(dis,0x7f7f7f,sizeof(dis));
		for(int j=1;j<=n;j++){
			add(edge[j][1],edge[j][2],edge[j][3]);
			add(edge[j][2],edge[j][1],edge[j][3]);
		}
		int ans=0;
		for(int j=0;j<=k-1;j++)
			if(i&(int(pow(2,j)))){
				ans+=f[j+1][0];
				for(int l=1;l<=n;l++){
					add(n+j+1,l,f[j+1][l]);
					add(l,n+j+1,f[j+1][l]);
				}
			}
		solve();
		for(int r=1;r<=n+k;r++){
			for(int c=1;c<=n+k;c++)
				cout<<setw(10)<<dis[r][c]<<" ";cout<<endl;
		}
		mn=min(mn,ans);
		cout<<endl;
	}
	cout<<mn<<endl;
	return 0;
}
