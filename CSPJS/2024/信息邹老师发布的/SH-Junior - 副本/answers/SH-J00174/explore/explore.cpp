#include<bits/stdc++.h> 
using namespace std;
int t,n,m,k,x,y,d,ans;
string s[1002];
bool vst[1002][1002];
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n>>m>>k>>x>>y>>d;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)vst[i][j]=0;
		vst[x][y]=1;ans=1;
		s[0]="";
		for(int i=-2;i<m;i++)s[0]=s[0]+"x";
		s[n+1]=s[0];
		for(int i=1;i<=n;i++){
			cin>>s[i];s[i]="x"+s[i]+"x";
		}
		for(int i=0;i<k;i++){
			int nx=x+dx[d],ny=y+dy[d];
			if(s[nx][ny]!='x')x=nx,y=ny;
			else d=(d+1)%4;
			if(!vst[x][y])vst[x][y]=1,ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
