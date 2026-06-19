#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
const int N=2e4+10;
vector<int> g[N];
long long dis[N];
int a[N][N],build[15],c[15][N];
int n,m,k;
void cons(int x){
	memset(dis,0x7f,sizeof dis);
	int st=1;
	for(int i=1;i<=n;i++){
		dis[i]=a[st][i];
	}
	sort(dis+1,dis+1+n);
	dis[1]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[j]=min(dis[j],dis[i]+a[i][j]);
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		a[u][v]=a[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		cin>>build[i];
		for(int j=1;j<=n;j++) cin>>c[i][j];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++){
			for(int l=1;l<=n;l++){
				a[i][l]=min(a[i][l],c[k][i]+c[k][l]);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//			for(int l=1;l<n;l++){
//				cout<<a[i][l]<<" ";
//			}
//	}
	cons(1);
	long long sum=0;
	for(int i=1;i<=n;i++){
		sum+=dis[i];
	}
	cout<<sum;
	return 0;
}

