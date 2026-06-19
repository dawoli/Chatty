#include<bits/stdc++.h>
using namespace std;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
char a[1005][1005]={};
int n,m,k,cnt=1;
int dfs(int x,int y,int d,int sum){
	if(sum==k+1){
		return cnt;
	}
	a[x][y]='l';
	int tx=x+dx[d];
	int ty=y+dy[d];
	if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&a[tx][ty]!='x'){
		if(a[tx][ty]=='.'){
			cnt++;
		}
		dfs(tx,ty,d,sum+1);
	}else{
		dfs(x,y,(d+1)%4,sum+1);
	}
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m>>k;
		int x,y,d;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
			}
		}
		cout<<dfs(x,y,d,1)<<endl;
		cnt=1;
	}
	return 0;
} 
