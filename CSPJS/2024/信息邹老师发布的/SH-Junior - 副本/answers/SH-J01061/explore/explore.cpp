#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,m,k,sx,sy,d;
int b[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int v[1005][1005];
char a[1005][1005];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		memset(v,0,sizeof v);
		cin>>n>>m>>k;
		cin>>sx>>sy>>d;
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>a[i][j];
		int x=sx,y=sy;
		v[x][y]=1;
		while(k--){
			if(x+b[d][0]>=1&&x+b[d][0]<=n&&y+b[d][1]>=1&&y+b[d][1]<=m){
				if(a[x+b[d][0]][y+b[d][1]]=='.')x+=b[d][0],y+=b[d][1];
				else d=(d+1)%4;
			}
			else d=(d+1)%4;
			v[x][y]=1;
		}
		int res=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(v[i][j])res++;
		cout<<res<<endl;
	}
	return 0;
} 
