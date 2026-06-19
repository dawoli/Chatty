#include <bits/stdc++.h>
using namespace std;

int T,ans=1;

struct node{
	int x,y,d;
};

int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	
	cin>>T;
	while(T--){
		int n,m,k;
		cin>>n>>m>>k;
		int sx,sy,sd;
		cin>>sx>>sy>>sd;
		char mp[1005][1005];
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>mp[i][j];
		
 		queue<node> q;
		q.push({sx,sy,sd});
		while(!q.empty()){
			node now=q.front();
			q.pop();
			
			for(int i=1;i<=k;i++){
				int nx=now.x;
				int ny=now.y;
				int nd=now.d;
				
				if(nd==0){
					if(nx<1 || nx>n || ny+1<1 || ny+1>m || mp[nx][ny+1]=='x'){
						nd=(nd+1)%4;
						q.push({nx,ny,nd});
						continue;
					}
					else{
						ans++,ny++;
						q.push({nx,ny,nd});
						continue;
					}
				}
				if(nd==1){
					if(nx+1<1 || nx+1>n || ny<1 || ny>m || mp[nx+1][ny]=='x'){
						nd=(nd+1)%4;
						q.push({nx,ny,nd});
						continue;
					}
					else{
						ans++,nx++;
						q.push({nx,ny,nd});
						continue;
					}
				}
				if(nd==2){
					if(nx<1 || nx>n || ny-1<1 || ny-1>m || mp[nx][ny-1]=='x'){
						nd=(nd+1)%4;
						q.push({nx,ny,nd});
						continue; 
					}
					else{
						ans++,ny--;
						q.push({nx,ny,nd});
						continue;
					}
				}
				if(nd==3){
					if(nx-1<1 || nx-1>n || ny<1 || ny>m || mp[nx-1][ny]=='x'){
						nd=(nd+1)%4;
						q.push({nx,ny,nd});
						continue;
					}
					else{
						ans++,nx--;;
						q.push({nx,ny,nd});
						continue;
					}
				}
			}
			
		}
	}
	cout<<ans<<endl;
	return 0;
}
