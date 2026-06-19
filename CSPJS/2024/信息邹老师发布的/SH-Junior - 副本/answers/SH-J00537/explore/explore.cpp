#include<bits/stdc++.h>
using namespace std;
char mp[1005][1005];
bool vis[1005][1005];
int main(){
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		int n,m,k;
		cin>>n>>m>>k;
		int x0,y0,d0;
		int ans=0;
		cin>>x0>>y0>>d0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>mp[i][j];
				if(mp[i][j]=='.')vis[i][j]=false;
			} 
		}
		int cnt=0;
		while(k){
			if(d0==0){
				if(y0+1>m||mp[x0][y0+1]=='x') {
					d0=(d0+1)%4;
					k--;
					break; 
				}else {
				y0+=1;
				vis[x0][y0]=true;
				k--;
			  }
			}
			if(d0==1){
				if(x0+1>n||mp[x0+1][y0]=='x') {
					d0=(d0+1)%4; 
					k--;
					break;
				}else {
				x0+=1;
				vis[x0][y0]=true;
				k--;
			  }
			}
			if(d0==2){
				if(y0-1<1||mp[x0][y0-1]=='x') {
					d0=(d0+1)%4; 
					k--;
					break;
				}else {
				y0-=1;
				vis[x0][y0]=true;
				k--;
			  }
			}
			if(d0==3){
				if(x0-1<1||mp[x0-1][y0]=='x') {
					d0=(d0+1)%4;
					k--;
					break; 
				}else {
				x0-=1;
				k--;
				vis[x0][y0]=true;
			  }
			}
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++){
					if(vis[i][j]&&mp[i][j]=='.') ans++;
				}
			}
	}
	cout<<ans<<endl;
  }
  return 0;
}
