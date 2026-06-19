#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 10,maxm = 1000 + 10;
int t,n,m,p;
int x,y,d;
int ans;
int dx[4] = {0,1,0,-1},dy[4] = {1,0,-1,0};
char jungle[maxn][maxm];
bool vis[maxn][maxm];

void init(){
	ans = 0;
	memset(vis,false,sizeof(vis));
}

void walk(int &x,int &y,int &d){
	int xa = x,ya = y;
	xa += dx[d];
	ya += dy[d];
	if(xa < 1 || xa > n || ya < 1 || ya > m || jungle[xa][ya] == 'x')	d = (d + 1) % 4;
	else{
		x = xa;
		y = ya;
	}
}

int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	scanf("%d",&t);
	while(t --){
		init();
		scanf("%d %d %d",&n,&m,&p);
		scanf("%d %d %d",&x,&y,&d);
		for(int i = 1;i <= n;i ++){
			scanf("%s",jungle[i] + 1);
		}
		vis[x][y] = true;
		ans ++;
		for(int i = 1;i <= p;i ++){
			walk(x,y,d);
			if(!vis[x][y]){
				vis[x][y] = true;
				ans ++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
