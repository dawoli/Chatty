#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	
	int num;
	cin>>num;
	for(int i=1;i<=num;i++){
		char map[1005][1005];
		bool vis[1005][1005];
		int n,m,k;
		cin>>n>>m>>k;
		for(int f=1;f<=n;f++){
			for(int j=1;j<=m;j++)
				vis[i][j]=0;
		}
		
		
		int x,y,d;
		cin>>x>>y>>d;
		
		for(int j=1;j<=n;j++){
			for(int z=1;z<=m;z++)
				cin>>map[j][z];
		}
		cout<<"OK2"<<endl;
		
		int nx=x,ny=y;
		cout<<"OK5"<<endl;
		//wrong from here...
		for(int j=1;j<=k;j++){
			cout<<"OK4"<<endl;
			vis[nx][ny]=1;
			if(d==0){
				if(nx+1<=m && nx+1>=1 && map[nx+1][ny]=='.') nx++;
			}
			else d=1;
			
			if(d==1){
				if(ny-1<=n && ny-1>=1 && map[nx][ny-1]=='.') ny--;
			}
			else d=2;
			
			if(d==2){
				if(nx-1<=m && nx-1>=1 && map[nx-1][ny]=='.') nx--;
			}
			else d=3;
			
			if(d==3){
				if(ny+1<=n && ny+1>=1 && map[nx][ny+1]=='.') ny++;
			}
			else d=0;
			
			cout<<"OK3"<<endl;
		}
		//...to here
		
		int cnt=0;
		for(int k=1;k<=n;k++){//correct
			for(int j=1;j<=m;j++){
				if(vis[i][j]==1) cnt++;
			}
		}
		cout<<cnt<<endl;
		
		cout<<"OK1"<<endl;
	}
	
	return 0;
}
