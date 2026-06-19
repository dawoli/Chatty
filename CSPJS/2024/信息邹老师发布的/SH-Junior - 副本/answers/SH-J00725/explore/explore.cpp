#include<bits/stdc++.h>
using namespace std;
int T,m,n,k,x,y,vis[1002][1002]={},d,dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
char a[1002][1002];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++){
		
		int cnt=1;
		cin>>m>>n>>k;
		cin>>x>>y>>d;
		string s;
		for(int j=1;j<=m;j++){
			cin>>s;
			for(int z=0;z<n;z++){
				a[j][z+1]=s[z];
			}
		}
		vis[x][y]=1;
		for(int j=1;j<=k;j++){
			int dx=x+dir[d][0]; 
			int dy=y+dir[d][1]; 
			if(dx>=1&&dx<=m&&dy>=1&&dy<=n&&a[dx][dy]=='.'){
				if(vis[dx][dy]==0){
					cnt++;
					vis[dx][dy]=1;
				}
				x=dx;
				y=dy;
			}else{
				d=(d+1)%4;
			}
		}
		cout<<cnt<<endl;
		for(int j=1;j<=m;j++){
			for(int z=1;z<=n;z++){
				vis[j][z]=0;
			}
		}
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
