#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int t,n,m,k,x,y,d,ans,dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
char a[N][N];
bool vis[N][N];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d%d%d%d",&n,&m,&k,&x,&y,&d);
		for(int i=0;i<n;i++)scanf("%s",a[i]);
		memset(vis,0,sizeof(vis)),ans=vis[--x][--y]=true;
		while(k--){
			int x1=x+dx[d],y1=y+dy[d];
			if(x1>=0&&x1<n&&y1>=0&&y1<m&&a[x1][y1]=='.'){
				if(!vis[x=x1][y=y1])ans+=vis[x1][y1]=true;
			}else d=(d+1)%4;
		}
		printf("%d\n",ans);
	}
	return 0;
}
