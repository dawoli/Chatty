#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int n,m,k;
struct edge{
	int to,we;
};int a[1010][1010];
int c[1010],sum,minn=1e9;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	priority_queue<int>q;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		a[u][v]=w;
		a[v][u]=w;
	}for(int i=1;i<=k;i++){
		cin>>c[i];
		sum+=c[i];
		for(int j=1;j<=n;j++){
			int y;
			cin>>y;
			sum+=y;
			a[n+i][j]=y;
			a[j][n+i]=y;
		}minn=min(minn,sum);
	}cout<<minn;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
