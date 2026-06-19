#include<bits/stdc++.h> 
using namespace std;
const int N=1e3+10;
int t,n,m,k,xx,yy,dd;
string s[N];
bool f[N][N];
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
int ans=1;
void dfs(int &x,int &y,int &dd){
//	cout<<ans<<"ans\n"; 
	if(s[x+dx[dd]][y+dy[dd]]=='x'){
		dd=(dd+1)%4;
		return;
	}
	if(x+dx[dd]<=n&&x+dx[dd]>=1&&y+dy[dd]<=m&&y+dy[dd]>=1)
		xx=x+dx[dd],yy=y+dy[dd];
	else dd=(dd+1)%4;
//	cout<<xx<<' '<<yy<<" "<<dd<<'\n';
	if(f[x][y]==0)ans++;
	f[x][y]=1;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		memset(f,0,sizeof(f));
		ans=1;
		cin>>n>>m>>k>>xx>>yy>>dd; 
		for(int i=1;i<=n;i++){
			cin>>s[i];
			s[i]=" "+s[i];
		}
		f[xx][yy]=1;
		for(int i=1;i<=k;i++){
			dfs(xx,yy,dd);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
