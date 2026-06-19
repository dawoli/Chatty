#include<bits/stdc++.h>
using namespace std;
int e[5010][5010],dis[10010];
bool book[10010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,x,y,z,mins,u,cnt=0;
	cin>>n>>m>>k;
	if(!k){
		memset(e,0x3f,sizeof(e));
		for(int i=1;i<=n;i++) e[i][i]=0;
		for(int i=1;i<=m;i++){
			cin>>x>>y>>z;
			e[x][y]=e[y][x]=z; 
		}
		for(int i=1;i<=n;i++){
			dis[i]=e[1][i];
		}
		book[1]=1;
		for(int i=1;i<n;i++){
			mins=INT_MAX;
			for(int j=1;j<=n;j++){
				if(!book[j]&&dis[j]<mins){
					mins=dis[j];
					u=j;
				}
			}
			book[u]=1;
			cnt+=mins;
			k++;
			if(k==n-1) break;
			for(int j=1;j<=n;j++){
				if(!book[j]&&dis[j]>e[u][j]){
					dis[j]=e[u][j];
				}
			}
		}
		cout<<cnt;
		return 0;
	}
	cout<<0;
	return 0;
}

