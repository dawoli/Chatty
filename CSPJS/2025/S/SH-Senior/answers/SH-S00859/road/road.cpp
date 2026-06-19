#include<bits/stdc++.h>
using namespace std;
int c[10010][10010],dc[10010][10010],cmin[10010][10010];
int x,y,z;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){

			c[i][j]=1e9;
			dc[i][j]=1e9;
	}}
	for(int i=1;i<=m;i++){
		cin>>x>>y>>z;
		c[x][y]=z;
		c[y][x]=z;
		dc[x][y]=z;
		dc[y][x]=z;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(c[i][j]!=1e9){
				dc[i][j]=1e9;
			}
			for(int k=1;k<=n;k++){
				cmin[i][j]=min(dc[i][j],dc[i][k]+dc[k][j]);
			}
			if(cmin[i][j]!=1e9)
					cout<<cmin[i][j]<<"\n";
		}
	}
	
	return 0;
} 
