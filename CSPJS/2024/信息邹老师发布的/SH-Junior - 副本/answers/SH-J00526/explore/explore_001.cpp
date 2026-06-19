#include <bits/stdc++.h>
using namespace std;
string s[1010];
bool vis[1010][1010];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int n,m,k;
bool hefa(int a,int b){
	if(a<1||a>n||b<1||b>m||s[a][b]=='x')return false;
	return true;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	scanf("%d",&T);
	int d,x,y;
	int x1,y1;
	while(T--){
		memset(vis,0,sizeof(vis));
		scanf("%d%d%d",&n,&m,&k);
		scanf("%d%d%d",&x,&y,&d);
		for(int i=1;i<=n;i++){
			cin>>s[i];
			s[i]=" "+s[i];
//			cout<<s[i]<<endl;
		}
		vis[x][y]=true;
		while(k--)
		{
			x1=x+dx[d],y1=y+dy[d];
			if(hefa(x1,y1))x=x1,y=y1;
			else d=(d+1)%4;
			vis[x][y]=true;
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
