#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d;
char s[1005][1005];
bool f[1005][1005];
int xm(int x,int d){
	if(d==0||d==2) return x;
	else if(d==1) return x+1;
	else return x-1;
}
int ym(int y,int d){
	if(d==1||d==3) return y;
	else if(d==0) return y+1;
	else return y-1;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&n,&m,&k);
		scanf("%d%d%d",&x,&y,&d);
		y--;
		for(int i=1;i<=n;i++){
			scanf("%s",s[i]);
			for(int j=0;j<m;j++){
				f[i][j]=0;
			}
		}
		f[x][y]=1;
		while(k--){
			int xx=xm(x,d);
			int yy=ym(y,d);
			if(xx>=1&&xx<=n&&yy>=0&&yy<m&&s[xx][yy]=='.') x=xx,y=yy,f[x][y]=1;
			else d=(d+1)%4;
		}
		int ans=0;
		for(int i=1;i<=n;i++) for(int j=0;j<m;j++) if(f[i][j]) ans++;
		printf("%d\n",ans);
	}
	return 0;
}
