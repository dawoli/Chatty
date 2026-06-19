#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1005;
int dx[10]={0,1,0,-1};
int dy[10]={1,0,-1,0};
int t,n,m,startd,startx,starty,can[N][N],vis[N][N],ans;
ll k;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		ans=1;
		scanf("%d%d%lld",&n,&m,&k);
		scanf("%d%d%d",&startx,&starty,&startd);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				char c;cin>>c;
				if(c=='.') can[i][j]=1;
				else can[i][j]=0;
				vis[i][j]=0;
			}
		vis[startx][starty]=1;
		while(k--){
			int a=startx+dx[startd];
			int b=starty+dy[startd];
			if(can[a][b]==0 || a<1 || a>n || b>m || b<1){startd=(startd+1)%4;continue;}
			if(can[a][b]==1){
				if(vis[a][b]==0) ans++,vis[a][b]=1;
				startx=a,starty=b;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
