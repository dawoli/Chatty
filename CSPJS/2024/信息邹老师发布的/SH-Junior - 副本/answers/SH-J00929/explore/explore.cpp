#include<bits/stdc++.h>
using namespace std;
char forest[1005][1005];
int x,y,d;
void go(){
	if(d==0&&(forest[x][y+1]=='.'||forest[x][y+1]=='1')){
		y++;
		forest[x][y]='1';
	}else if(d==1&&(forest[x+1][y]=='.'||forest[x+1][y]=='1')){
		x++;
		forest[x][y]='1';
	}else if(d==2&&(forest[x][y-1]=='.'||forest[x][y-1]=='1')){
		y--;
		forest[x][y]='1';
	}else if(d==3&&(forest[x-1][y]=='.'||forest[x-1][y]=='1')){
		x--;
		forest[x][y]='1';
	}else{
		d=(d+1)%4;
	}
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	scanf("%d\n", &T);
	int n,m,k,cnt=0;
	for(int tt=1;tt<=T;tt++){
		scanf("%d %d %d\n",&n,&m,&k);
		scanf("%d %d %d\n",&x,&y,&d);
		for(int fx=1;fx<=n;fx++){
			for(int fy=1;fy<=m;fy++){
				scanf("%c",&forest[fx][fy]);
			}
			scanf("\n");
		}
		forest[x][y]='1';
		for(int i=1;i<=k;i++){
			go();
		}
		for(int fx=1;fx<=n;fx++){
			for(int fy=1;fy<=m;fy++){
				if(forest[fx][fy]=='1'){
					cnt++;
				}
				forest[fx][fy]='x';
			}
		}
		printf("%d\n",cnt);
		cnt=0;
	}
	return 0;
}
