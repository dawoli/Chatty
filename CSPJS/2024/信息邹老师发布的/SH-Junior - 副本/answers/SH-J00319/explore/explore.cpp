#include<bits/stdc++.h>
using namespace std;
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
int ans[1020][1020];
bool Hash[1020][1020];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		memset(Hash,false,sizeof(Hash));
		memset(ans,0,sizeof(ans));
		int n,m,k,sum=1,x,y,d;
		cin>>n>>m>>k>>x>>y>>d;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				char ab;
				cin>>ab;
				if(ab=='x') ans[i][j]=1;
			}
		Hash[x][y]=true;
		while(k--){
			int nx=x+dx[d],ny=y+dy[d];
			if(nx<1||ny<1||nx>n||ny>m||ans[nx][ny]){
				d=(d+1)%4;
				continue;
			}
			if(!Hash[nx][ny]) sum++;
			Hash[nx][ny]=true;
			x=nx,y=ny;
		}
		cout<<sum<<endl;
	}
	return 0;
}
//676
//756
//32
//116
//198
