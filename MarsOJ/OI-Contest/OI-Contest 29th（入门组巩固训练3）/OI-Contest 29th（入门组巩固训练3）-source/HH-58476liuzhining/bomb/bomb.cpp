#include<bits/stdc++.h>
using namespace std;
int xx[5]={-1,1,0,0};
int yy[5]={0,0,-1,1};
long long T,n,m,b,zy,bs;
char s[1010][1010];

//void dfs(int x,int y){
//	if(x==n&&y==m){
//		bs=min(bs,b);
//		b=0;
//		return;
//	}
//	for(int i=1;i<=4;i++){
//		int nx=x+xx[i];
//		int ny=y+yy[i];
//		if(nx<1||nx>n||ny<1||ny>m||s[nx][ny]=='*'){
//			continue;
//		}
//		b++;
//		dfs(nx,ny);
//	}
//	return;
//}

int main(){
	freopen("r","bomb.in",stdin);
	freopen("w","bomb.out",stdout);
	scanf("%lld%c",&T,&s[0][0]);
	while(T--){
		scanf("%lld%lld%c",&n,&m,&s[0][0]);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m+1;j++){
				scanf("%c",&s[i][j]);
			}
		}
		zy=0;bs=0;
		if(n==1){
			for(int j=2;j<=m;j++){
				if(s[1][j]=='$'){
					zy++;
				}
				if(s[1][j]!='*'){
					bs++;
				}
			}
			printf("%lld %lld\n",zy,bs);
			continue;
		}
//		zy=1e9;bs=1e9;
//		dfs(1,1);
//		printf("0 %lld\n",bs);
	}
	return 0;
}

