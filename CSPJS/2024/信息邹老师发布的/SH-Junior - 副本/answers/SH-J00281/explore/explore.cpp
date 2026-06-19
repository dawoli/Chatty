#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d;
int visited[1005][1005]={0};
char forest[1005][1005];
int direct[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n>>m>>k>>x>>y>>d;
		int ans=1;
		visited[x][y]=1;
		for(int j=1;j<=n;j++){
			for(int p=1;p<=m;p++){
				cin>>forest[j][p];
			}
		}
		for(int j=0;j<k;j++){
			if(1<=x+direct[d][0]&&x+direct[d][0]<=n&&1<=y+direct[d][1]&&y+direct[d][1]<=m&&forest[x+direct[d][0]][y+direct[d][1]]=='.'){
				x+=direct[d][0];
				y+=direct[d][1];
				if(!visited[x][y]){
					ans++;
					visited[x][y]=1;
				}
			}
			else d=(d+1)%4;
		}
		cout<<ans<<endl;
		for(int j=1;j<=n;j++){
			for(int p=1;p<=m;p++){
				visited[j][p]=0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
