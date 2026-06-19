/*
朝向：0向上 1向右 2向下 3向左
一次操作: 
	默认下一步往既定方向走
	如果下一步为空地则往前走，为障碍则向右转但不前进 
*/ 
#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d,ans;
string mp[1005];
int wx[4]={0,1,0,-1};
int wy[4]={1,0,-1,0};
int vis[1005][1005];
void search(int sx,int sy){
	int tx=sx,ty=sy,dir=d;
	vis[tx][ty]=1;
	for(int i=1;i<=k;i++){
		if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&
		   tx+wx[dir]>=1&&tx+wx[dir]<=n&&
		   ty+wy[dir]>=1&&ty+wy[dir]<=m&&
		   mp[tx][ty]=='.'&&mp[tx+wx[dir]][ty+wy[dir]]=='.')
		{
			tx+=wx[dir],ty+=wy[dir];
			vis[tx][ty]=1;
		}
		else{
			dir=(dir+1)%4;
		}
	}
}
int main(){
//	freopen("D:\\9_CSP-J\\CSP-J\\explore\\explore5.in","r",stdin);
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++) vis[i][j]=0;
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++){
			string s;
			cin>>s;
			s=" "+s;
			mp[i]=s;
		}
		search(x,y);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				if(vis[i][j])ans++;
			}
		cout<<ans<<endl;
	} 
	return 0;
}
