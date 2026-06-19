#include<bits/stdc++.h>
using namespace std;
long long t,n,m,k,x,y,d,cnt;
char a[1005][1005];
bool vis[1005][1005];
int DFS(long long k,long long x,long long y,long long cnt,long long d){
	if(k==0)return cnt;
	if(d==0){
		if(y+1<=m&&a[x][y+1]=='.'){
			if(!vis[x][y+1]){
				vis[x][y+1]=1;
				DFS(k-1,x,y+1,cnt+1,d);
			}
			else DFS(k-1,x,y+1,cnt,d);
		}
		else DFS(k-1,x,y,cnt,(d+1)%4);
	}
	else if(d==1){
		if(x+1<=n&&a[x+1][y]=='.'){
			if(!vis[x+1][y]){
				vis[x+1][y]=1;
				DFS(k-1,x+1,y,cnt+1,d);
			}
			else DFS(k-1,x+1,y,cnt,d);
		}
		else DFS(k-1,x,y,cnt,(d+1)%4);
	}
	else if(d==2){
		if(y-1>=1&&a[x][y-1]=='.'){
			if(!vis[x][y-1]){
				vis[x][y-1]=1;
				DFS(k-1,x,y-1,cnt+1,d);
			}
			else DFS(k-1,x,y-1,cnt,d);
		}
		else DFS(k-1,x,y,cnt,(d+1)%4);
	}
	else if(d==3){
		if(x-1>=1&&a[x-1][y]=='.'){
			if(!vis[x-1][y]){
				vis[x-1][y]=1;
				DFS(k-1,x-1,y,cnt+1,d);
			}
			else DFS(k-1,x-1,y,cnt,d);
		}
		else DFS(k-1,x,y,cnt,(d+1)%4);
	}
} 
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>m>>k>>x>>y>>d;
		cnt=1;
		memset(a,0,sizeof(a));
		memset(vis,0,sizeof(vis));
		for(int j=1;j<=n;j++){
			for(int q=1;q<=m;q++){
				cin>>a[j][q];
			}
		}
		vis[x][y]=1;
		cout<<DFS(k,x,y,cnt,d)<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
