#include<bits/stdc++.h>
using namespace std;
int n,m,k,x,y,d,t,ans;
char ss[1005];
bool a[1005][1005],vis[1005][1005];
int dk[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	for(int ii=0;ii<t;ii++){
		memset(vis,0,sizeof(vis));
		memset(a,0,sizeof(a)); 
		ans=0;
		cin>>n>>m>>k>>x>>y>>d;
		vis[x][y]=1;
		for(int i=1;i<=n;i++){
			cin>>ss;
			for(int j=0;j<m;j++){
				if(ss[j]=='x') a[i][j+1]=1;
			}
		} 
		for(int i=0;i<k;i++){
			if(x+dk[d][0]<=0||x+dk[d][0]>n||y+dk[d][1]<=0||y+dk[d][1]>m||a[x+dk[d][0]][y+dk[d][1]]) d=(d+1)%4;
			else{
				x+=dk[d][0];
				y+=dk[d][1];
			}
			vis[x][y]=1;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(vis[i][j])ans++;
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
} 
