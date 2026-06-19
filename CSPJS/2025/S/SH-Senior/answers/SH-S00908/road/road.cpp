#include<bits/stdc++.h>
using namespace std;
const int maxm=1e6+10;
const int maxn=1e4+10;
long long lian[maxn][maxn];
bool visit[maxn];
int n,m,k;
deque<int> next;
void bfs(int s,int pos,int e,int score){
	visit[pos]=1;
	if(lian[pos][e]!=0){
		lian[s][e]=score+lian[pos][e];
		return ;
	}
	for(int i=1;i<=n;i++){
		if(lian[pos][i]!=0&&!visit[i]){
			next.push_back(i);
		}
	}
	while(!next.empty()){
		int y=next[1];
		next.pop_front();
		bfs(s,y,e,score+lian[pos][y]);
	}
}
int main(){
	freopen("road1.in","r",stdin);
//	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v;
		long long w;
		cin>>u>>v>>w;
		lian[u][v]=w;
		lian[v][u]=w;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			if(lian[i][j]==0){
				memset(visit,0,sizeof(visit));
				
				bfs(i,i,j,0);
				
			}
		}
	}
	for(int i=1;i<=k;i++){
		long long a[maxn],c;
		cin>>c;
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
//		for(int j=1;)
	}
	cout<<1;
}
