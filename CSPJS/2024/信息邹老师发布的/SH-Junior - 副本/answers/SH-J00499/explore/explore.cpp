#include<bits/stdc++.h>
using namespace std;

int T;

const int maxn=1e3+5;

bool a[maxn][maxn];
bool vis[maxn][maxn];
int n,m;

bool inmap(int x,int y){
	if(a[x][y]||x<1||x>n||y<1||y>m)return false;
	return true;
}

int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		int k;
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++)vis[i][j]=false;
		}
		int x,y,d;
		scanf("%d%d%d",&x,&y,&d);
		getchar();
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				char c=getchar();
				if(c=='x')a[i][j]=true;
				else a[i][j]=false;
			}
			getchar();
		}
		vis[x][y]=true;
		int cnt=0;
		while(cnt<k){
			cnt++;
			int nxtx,nxty;
			if(d==0){
				nxtx=x,nxty=y+1;
				if(!inmap(nxtx,nxty)){d=1;continue;}
			}else if(d==1){
				nxtx=x+1,nxty=y;
				if(!inmap(nxtx,nxty)){d=2;continue;}
			}else if(d==2){
				nxtx=x,nxty=y-1;
				if(!inmap(nxtx,nxty)){d=3;continue;}
			}else{
				nxtx=x-1,nxty=y;
				if(!inmap(nxtx,nxty)){d=0;continue;}
			}
			x=nxtx,y=nxty;
			vis[nxtx][nxty]=true;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(vis[i][j])ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
} 
