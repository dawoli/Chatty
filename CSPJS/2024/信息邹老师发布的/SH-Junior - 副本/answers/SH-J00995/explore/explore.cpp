#include<bits/stdc++.h>
using namespace std;
int t;
int n,m,k;
int x0,y0,d0;
char a[1005][1005];
int vis[1005][1005];
void dfs(int x,int y,int d,int step){
	if(step>=k){
		return;
	}
	int x_=x,y_=y;
	if(d==0){
		y_=y+1;
	}
	else if(d==1){
		x_=x+1;
	}
	else if(d==2){
		y_=y-1;
	}
	else{
		x_=x-1;
	}
	if(x_<=0 or y_<=0 or x_>n or y_>m or a[x_][y_]=='x'){
		d=(d+1)%4;
		x_=x;
		y_=y;
	}
	vis[x_][y_]=1;
	dfs(x_,y_,d,step+1);
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n>>m>>k;
		cin>>x0>>y0>>d0;
		for(int l=1;l<=n;l++){
			for(int r=1;r<=m;r++){
				vis[l][r]=0;
				cin>>a[l][r];
			}
		}
		vis[x0][y0]=1;
		dfs(x0,y0,d0,0);
		int ans=0;
		for(int l=1;l<=n;l++){
			for(int r=1;r<=m;r++){
				if(vis[l][r]==1){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
