#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d;
char mp[1010][1010];
bool vis[1010][1010];
bool check_new(int x,int y){
	if(x>=1&&x<=n&&y>=1&&y<=m)return true;
	return false;
}
void handle(){
	while(k--){
		switch(d){
			case 0:
				if(check_new(x,y+1)){
					if(mp[x][y+1]!='x'){
						y=y+1;
						vis[x][y]=true;
					}else{
						d=(d+1)%4;
					}
				}else{
					d=(d+1)%4;
				}
				break;
			case 1:
				if(check_new(x+1,y)){
					if(mp[x+1][y]!='x'){
						x=x+1;
						vis[x][y]=true;
					}else{
						d=(d+1)%4;
					}
				}else{
					d=(d+1)%4;
				}
				break;
			case 2:
				if(check_new(x,y-1)){
					if(mp[x][y-1]!='x'){
						y=y-1;
						vis[x][y]=true;
					}else{
						d=(d+1)%4;
					}
				}else{
					d=(d+1)%4;
				}
				break;
			case 3:
				if(check_new(x-1,y)){
					if(mp[x-1][y]!='x'){
						x=x-1;
						vis[x][y]=true;
					}else{
						d=(d+1)%4;
					}
				}else{
					d=(d+1)%4;
				}
				break;
		}
	}
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&n,&m,&k);
		scanf("%d%d%d",&x,&y,&d);
		for(int i=1;i<=1005;i++)
			for(int j=1;j<=1005;j++)
				vis[i][j]=0;
		vis[x][y]=true;
		for(int i=1;i<=n;i++)scanf("%s",&mp[i][1]);
		handle();int ans=0;
		for(int i=1;i<=1005;i++)
			for(int j=1;j<=1005;j++)
				if(vis[i][j])ans++;
		printf("%d\n",ans);
	}
	return 0;
}

