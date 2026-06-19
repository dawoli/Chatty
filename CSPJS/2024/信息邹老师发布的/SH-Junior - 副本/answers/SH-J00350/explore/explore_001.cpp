#include <cstdio>
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t,n,m,k,x,y,d;
	scanf("%d",&t);
	for(int a=0;a<t;a++){
		scanf("%d %d %d",&n,&m,&k);
		scanf("%d %d %d",&x,&y,&d);
		x--;
		y--;
		char map[n][m];
		for(int i=0;i<n;i++){
			scanf("%s",map[i]);
		}
		//ok
		map[x][y]='6';
		for(int i=0;i<k;i++){
			if(y!=m-1&&d==0&&map[x][y+1]!='x') y++;
			else if(y!=0&&d==2&&map[x][y-1]!='x') y--;
			else if(x!=n-1&&d==1&&map[x+1][y]!='x') x++;
			else if(x!=0&&d==3&&map[x-1][y]!='x') x--;
			else d=(d+1)%4;
			map[x][y]='6';
			
		}
		int ans=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(map[i][j]=='6') ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
