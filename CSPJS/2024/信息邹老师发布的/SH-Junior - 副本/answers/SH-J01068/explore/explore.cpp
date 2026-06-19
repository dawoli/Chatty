#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,t,d,k,ans;
char a[1005][1005];
bool flag[1005][1005];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	for(int l=0;l<t;l++){
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) flag[i][j]=false;
		int ans=0;
		flag[x][y]=true;
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j];
		for(int i=0;i<k;i++){
			if(d==0 and a[x][y+1]=='.' and y+1<=m) y++;
			else if(d==1 and a[x+1][y]=='.' and x+1<=n) x++;
			else if(d==2 and a[x][y-1]=='.' and y-1>0 ) y--;
			else if(d==3 and a[x-1][y]=='.' and x-1>0) x--;
			else d=(d+1)%4;
			flag[x][y]=true;
		}
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(flag[i][j]) ans++;
		cout<<ans<<endl;
	}
	return 0;
} 

