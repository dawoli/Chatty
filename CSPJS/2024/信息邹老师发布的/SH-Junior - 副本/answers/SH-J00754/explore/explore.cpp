#include<bits/stdc++.h>
using namespace std;
bool vis[1005][1005]={};
int n,m,k;
bool check(int x,int y,char c){
	return (1<=x&&x<=n&&1<=y&&y<=m&&c=='.');
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		char xy[1005][1005]={};
		memset(vis,0,sizeof(vis));
		cin>>n>>m>>k;
		int x0,y0,d0;
		cin>>x0>>y0>>d0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>xy[i][j];
			}
		}
		vis[x0][y0]=1;
		for(int i=1;i<=k;i++){
			if(d0==0){
				if(check(x0,y0+1,xy[x0][y0+1])){
					vis[x0][y0+1]=1;
					y0++;
				}
				else d0=(d0+1)%4;
			}
			else if(d0==1){
				if(check(x0+1,y0,xy[x0+1][y0])){
					vis[x0+1][y0]=1;
					x0++;
				}
				else d0=(d0+1)%4;
			}
			else if(d0==2){
				if(check(x0,y0-1,xy[x0][y0-1])){
					vis[x0][y0-1]=1;
					y0--;
				}
				else d0=(d0+1)%4;
			}
			else if(d0==3){
				if(check(x0-1,y0,xy[x0-1][y0])){
					vis[x0-1][y0]=1;
					x0--;
				}
				else d0=(d0+1)%4;
			}
		}
		int ct=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(vis[i][j])ct++;
			}
		}
		cout<<ct<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
