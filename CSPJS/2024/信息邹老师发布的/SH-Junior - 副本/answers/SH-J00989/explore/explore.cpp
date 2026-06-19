#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
int s[N][N];
char a[N][N];
int t;
int n,m,k,x,y,d;
int sum=1;
void solve(){
	memset(s,0,sizeof(s));
	for(int i=1;i<=k;i++){
		int xx=x+dx[d],yy=y+dy[d];
		if(a[xx][yy]=='x'||xx<1||xx>n||yy<1||yy>m) d=(d+1)%4;
		else{
			if(s[xx][yy]==0) sum++;
			x=xx,y=yy,s[xx][yy]=1;
		}
	}
	cout<<sum<<endl;
	sum=1;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>m>>k>>x>>y>>d;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++) cin>>a[i][j];
		solve();
	}
	return 0;
}
