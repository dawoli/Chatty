#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int t,n,m,k;
int st,en,d;
char s[N][N];
int a[N][N],ans;
int dxy[5][3]={{0,1},{1,0},{0,-1},{-1,0}};
bool check(int x,int y){
	if(x<=n&&x>=1&&y<=m&&y>=1&&s[x][y]=='.')return 1;
	return 0;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		memset(a,0,sizeof(a));
		ans=0;
		scanf("%d%d%d%d%d%d",&n,&m,&k,&st,&en,&d);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>s[i][j];
			}
		}
		int x=st,y=en;
		a[x][y]=1,ans=1;
		while(k--){
			int xx=x+dxy[d][0],yy=y+dxy[d][1];
			if(check(xx,yy)){
				x=xx,y=yy;
				if(a[xx][yy]!=1)a[xx][yy]=1,ans++;
			}else d=(d+1)%4;
		}
		printf("%d\n",ans);
	}
	return 0;
}
