#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d,ans,dx[4]={0,1,0,-1},dy[4]={1,0,-1,0},b[1010][1010];
char a[1010][1010];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		ans=1;
		scanf("%d%d%d",&n,&m,&k);
		scanf("%d%d%d",&x,&y,&d);
		memset(b,0,sizeof(b));
		for(int i=0;i<n;i++)scanf("%s",&a[i]);
		while(k--){
			if(x+dx[d]>=0&&x+dx[d]<n&&y+dy[d]>=0
			&&y+dy[d]<m&&a[x+dx[d]][y+dy[d]]=='.'){
				x+=dx[d],y+=dy[d];
				if(b[x][y]==0)ans++;
				b[x][y]=1;
			}
			else d=(d+1)%4;
		}
		printf("%d\n",ans);
	}
	return 0;
}
