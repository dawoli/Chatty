#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,cx,cy,cd,a[1001][1001],vis[1001][1001],cnt;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		cnt=1;
		memset(vis,0,sizeof(vis));
		cin>>n>>m>>k;
		cin>>cx>>cy>>cd;
		for(int i=1;i<=n;i++){
			string s;
			cin>>s;
			for(int j=0;j<m;j++){
				if(s[j]=='x')a[i][j+1]=1;
				if(s[j]=='.')a[i][j+1]=0;
			}
		}
		for(int i=1;i<=k;i++){
			int xx=cx+dx[cd],yy=cy+dy[cd];
			if(xx<1||xx>n||yy<1||yy>m||a[xx][yy]==1){
				cd=(cd+1)%4;
				continue;
			}
			if(vis[xx][yy]==0)cnt++;
			vis[xx][yy]=1;
			cx=xx;
			cy=yy;
		}
		cout<<cnt<<endl;
	}
}
