#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	while(t!=0){
		t--;
		int n,m,k,x,y,d;
		char Map[1005][1005];
		bool vis[1005][1005];
		cin>>n>>m>>k>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				vis[i][j]=false;
			}
		}
		vis[x][y]=true;
		for(int i=0;i<=m+1;i++){
			Map[0][i]='x';
			Map[n+1][i]='x';
		}
		for(int i=0;i<n+1;i++){
			Map[i][0]='x';
			Map[i][m+1]='x';
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>Map[i][j];
			}
		}
		long long int ans=0;
		while(k!=0){
			k--;
			int x1,y1;
			if(d==0){
				x1=x;
				y1=y+1;
			}
			else if(d==1){
				x1=x+1;
				y1=y;
			}
			else if(d==2){
				x1=x;
				y1=y-1;
			}
			else{
				x1=x-1;
				y1=y;
			}
			if(Map[x1][y1]!='x'){
				x=x1;
				y=y1;
				vis[x][y]=true;
			}
			else{
				d=(d+1)%4;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(vis[i][j]==true){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
