#include<bits/stdc++.h>
using namespace std;
char t,tt;
char ch[1005][1005];
bool flag[1005][1005];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t; tt=t-'0';
	while(tt--){
		int n,m,k; cin>>n>>m>>k;
		int x,y,d; cin>>x>>y>>d;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				cin>>ch[i][j];
				flag[i][j]=0;
			}
		int dx=x,dy=y,ans=1;
		for(int i=1;i<=k;i++){
			flag[x][y]=1;
			if(d==0) dx=x,dy=y+1;
			if(d==1) dx=x+1,dy=y;
			if(d==2) dx=x,dy=y-1;
			if(d==3) dx=x-1,dy=y;
			
			if(dx>=1&&dx<=n&&dy>=1&&dy<=m&&ch[dx][dy]=='.'){
				x=dx,y=dy;
				if(flag[x][y]==0) ans++;
			}
			else d=(d+1)%4;
		}
		cout<<ans<<endl;
	}
	return 0;
}
