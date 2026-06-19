#include<bits/stdc++.h>
using namespace std;
int n,m,vis[1010][1010],k,T,sx,sy,d,Cnt;
char a[1010][1010];
const int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
struct node{
	int x,y,d;
};
queue<node>q;
void solve(){
	cin>>n>>m>>k;
	cin>>sx>>sy>>d;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	q.push({sx,sy,d});
	while(!q.empty()){
		node tmp=q.front();
		if(k<0)
			break;
		vis[tmp.x][tmp.y]=1;
		q.pop();
		int cnt=0,nd=tmp.d;
		while(cnt<=4){
			int nx=tmp.x+dx[nd],ny=tmp.y+dy[nd];
			if(nx>0&&ny>0&&nx<=n&&ny<=m&&a[nx][ny]!='x'){
				if(tmp.d!=nd)
					q.push({tmp.x,tmp.y,nd});
				else
					k--,q.push({nx,ny,tmp.d});
				break;
			}
			k--;
			cnt++;
			nd=(nd+1)%4;
		}
		
		if(cnt>4)
			break;
	}
	if(!q.empty())
		q.pop();
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			ans+=vis[i][j],vis[i][j]=0;
	cout<<ans<<"\n";
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--)
		solve();
}
