#include<bits/stdc++.h>
using namespace std;
pair<int,int>nxt(int x,int y,int d) {
	if(d==0)return {x,y+1 };
	else if(d==1)return {x+1,y };
	else if(d==2)return {x,y-1 };
	else return {x-1,y }; }
int main() {
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	bool mp[1001][1001],vis[1001][1001];
	cin>>t;
	while(t--) {
		memset(vis,0,sizeof vis);
		int n,m,k,x,y,d,cnt=0;
		cin>>n>>m>>k>>x>>y>>d;
		x--,y--;
		vis[x][y]=1;
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				char c;
				cin>>c;
				if(c=='.')mp[i][j]=0;
				else mp[i][j]=1; } }
		for(int i=0; i<k; i++) {
			pair<int,int>t=nxt(x,y,d);
			if(t.first>=0&&t.first<n&&t.second>=0&&t.second<m&&mp[t.first][t.second]==0) {
				x=t.first,y=t.second;
				if(vis[t.first][t.second]==0)cnt++,vis[t.first][t.second]=1; }
			else d=(d+1)%4; } 
		cout<<cnt+1<<endl; }
	fclose(stdin);
	fclose(stdout);
	return 0; }
