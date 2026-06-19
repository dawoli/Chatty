#include<bits/stdc++.h>
using namespace std;
char fi[1001][1001];
bool f[1001][1001];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;scanf("%d",&T);
	while(T--){
		int n,m,k;scanf("%d %d %d",&n,&m,&k);
		int x,y;scanf("%d %d",&x,&y);
		f[x][y]=true;
		int d;scanf("%d",&d);
		char temp;
		for(int i=1;i<=n;i++){
			scanf("%c",&temp);
			for(int j=1;j<=m;j++)
				scanf("%c",&fi[i][j]);
		}
		while(k--){
			switch(d){
				case 0:{
					if(y+1<=m && fi[x][y+1]!='x'){
						y++;
						f[x][y]=true;
					}
					else d=(d+1)%4;
					break;
				}
				case 1:{
					if(x+1<=n && fi[x+1][y]!='x'){
						x++;
						f[x][y]=true;
					}
					else d=(d+1)%4;
					break;
				}
				case 2:{
					if(1<=y-1 && fi[x][y-1]!='x'){
						y--;
						f[x][y]=true;
					}
					else d=(d+1)%4;
					break;
				}
				case 3:{
					if(1<=x-1 && fi[x-1][y]!='x'){
						x--;
						f[x][y]=true;
					}
					else d=(d+1)%4;
					break;
				}
			}
		}
		int cnt=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(f[i][j]) cnt++;
		printf("%d\n",cnt);
	}
	return 0;
}
