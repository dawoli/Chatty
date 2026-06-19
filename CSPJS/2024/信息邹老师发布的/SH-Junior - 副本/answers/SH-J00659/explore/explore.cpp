#include<bits/stdc++.h>
using namespace std;
int n,m,k,T,ans=0;
int a[1005][1005],v[1005][1005];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int dfs(int step,int x,int y,int d){
	if(!v[x][y])ans++,v[x][y]=1;
	if(step==k)return ans;
	int next=a[x+dx[d]][y+dy[d]];
	if(x+dx[d]>=1 && x+dx[d]<=n && y+dy[d]>=1 && y+dy[d]<=m && next==0){
		dfs(step+1,x+dx[d],y+dy[d],d);
	}
	else dfs(step+1,x,y,(d+1)%4);
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		memset(a,0,sizeof(a));
		memset(v,0,sizeof(v)); 
		scanf("%d%d%d",&n,&m,&k);
		int x,y,d;
		scanf("%d%d%d",&x,&y,&d);
		char ch;
		for(int i=1;i<=n;i++)
		  for(int j=1;j<=m;j++){
		  	cin>>ch;
		  	if(ch=='x')a[i][j]=1;
		  }
		ans=0;
		printf("%d\n",dfs(0,x,y,d));
	}
	return 0;
}
