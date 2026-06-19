#include<bits/stdc++.h>
using namespace std;
int t,cover[1005][1005];
string mapp[1005];
int n,m;
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
void dfs(int last,int x,int y,int d){
	if(last==0){
		return;
	}
	int xx=x+dx[d],yy=y+dy[d];
	if(xx<n&&xx>=0&&yy<m&&yy>=0&&mapp[xx][yy]=='.'){
		cover[xx][yy]=1;
		dfs(last-1,xx,yy,d);
	}else{
		d=(d+1)%4;
		dfs(last-1,x,y,d);
	}
	return;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	
	cin>>t;
	while(t--){
		int k,x0,y0,d0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cover[i][j]=0;
			}
		}
		cin>>n>>m>>k>>x0>>y0>>d0;
		for(int i=0;i<n;i++){
			cin>>mapp[i];
		}
		x0-=1;
		y0-=1;
		cover[x0][y0]=1;
		dfs(k,x0,y0,d0);
		long long sum=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				sum+=cover[i][j];
			}
		}
		cout<<sum<<"\n";
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}

