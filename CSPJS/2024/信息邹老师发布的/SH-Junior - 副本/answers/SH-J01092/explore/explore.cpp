#include<bits/stdc++.h>
using namespace std;
int l[1005][1005]={};
int xl[4]={0,1,0,-1};
int yl[4]={1,0,-1,0};
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T; 
	cin>>T;
	while(T--){
		int n,m,k,x,y,d,nx,ny;
		string tmp;
		cin>>n>>m>>k>>x>>y>>d;
		for(int i=0;i<=n+1;i++){
			for(int j=0;j<=m+1;j++){
				l[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++){
			cin>>tmp;
			for(int j=1;j<=m;j++){
				if(tmp[j-1]=='x') l[i][j]=0;
				else l[i][j]=1;
			}
		}
		l[x][y]=-1;
//		for(int i=0;i<=n+1;i++){
//			for(int j=0;j<=m+1;j++){
//				cout<<l[i][j]<<" ";
//			}
//			cout<<endl;
//		}
		while(k--){
			nx=x+xl[d];
			ny=y+yl[d];
			if(l[nx][ny]!=0){
				x=nx;
				y=ny;
				l[x][y]=-1;
			}
			else{
				d=(d+1)%4;
			}
		}
//		for(int i=0;i<=n+1;i++){
//			for(int j=0;j<=m+1;j++){
//				cout<<l[i][j]<<" ";
//			}
//			cout<<endl;
//		}
		int ans=0;
		for(int i=0;i<=n+1;i++){
			for(int j=0;j<=m+1;j++){
				if(l[i][j]==-1){
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
