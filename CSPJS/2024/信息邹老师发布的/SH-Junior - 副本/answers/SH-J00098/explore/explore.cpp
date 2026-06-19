#include<cstdio>
#include<cstring>
using namespace std;
int t,n,m,k,x,y,d,x1,y1,ans;
char c;
bool map[1005][1005],vis[1005][1005];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d%d%d%d",&n,&m,&k,&x,&y,&d);
		memset(map,0,sizeof(map));
		memset(vis,0,sizeof(vis));
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				scanf("%c",&c);
				if(c=='\n'){
					scanf("%c",&c);
				}
				if(c=='.'){
					map[i][j]=true;
				}
			}
		}
		vis[x][y]=true;
		while(k--){
			x1=x;
			y1=y;
			if(d==0){
				y1++;
			}
			if(d==1){
				x1++;
			}
			if(d==2){
				y1--;
			}
			if(d==3){
				x1--;
			}
			if(1<=x1&&x1<=n&&1<=y1&&y1<=m&&map[x1][y1]){
				x=x1;
				y=y1;
				if(!vis[x][y]){
					vis[x][y]=true;
					ans++;
				}
			}
			else{
				d=(d+1)%4;
			}
		}
		printf("%d\n",ans+1);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
