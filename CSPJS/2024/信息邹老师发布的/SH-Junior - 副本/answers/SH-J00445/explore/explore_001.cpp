#include<bits/stdc++.h>
#define N 1005
using namespace std;
int t,ans=1,error;
int n,m,k;
int x,y,d;
int a[N][N];
char p;
int xd[4]={0,1,0,-1},yd[4]={1,0,-1,0};
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		ans=1;
		error=0;
		scanf("%d%d%d",&n,&m,&k);
		scanf("%d%d%d",&x,&y,&d);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				scanf("%c",&p);
				if(p=='x') a[i][j]=0;
				if(p=='.') a[i][j]=1;
			}
		}
		while(k--){
			int xa=x+xd[d],ya=y+yd[d];
			if(!a[xa][ya] || xa<1 || xa>n || ya<1 || ya>m){
				d=(d+1)%4;
				error++;
			}
			else{
				ans++;
				x=xa;
				y=ya;
				error=0;
			}
			if(error>=4) break;
		}
		printf("%d\n",ans);
	}
	return 0;
}
