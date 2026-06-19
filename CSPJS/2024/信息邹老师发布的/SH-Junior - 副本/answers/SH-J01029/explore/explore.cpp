#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t,n,m,k,x,y,d;
char s[1005][1005];
int wl[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
bool vis[1005][1005];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&n,&m,&k);
		scanf("%d%d%d",&x,&y,&d);
		for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
		memset(vis,0,sizeof(vis));
		vis[x][y]=1;
		while(k--){
			int ux=x+wl[d][0],uy=y+wl[d][1];
			if(ux<1 || uy<1 || ux>n || uy>m || s[ux][uy]=='x')d=(d+1)%4;
			else x=ux,y=uy;
			vis[x][y]=1;
		}
		int res=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(vis[i][j])
					res++;
		printf("%d\n",res);
	}
	return 0;
}
