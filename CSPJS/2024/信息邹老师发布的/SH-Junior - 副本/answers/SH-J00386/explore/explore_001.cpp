#include<bits/stdc++.h>
using namespace std;
int ans[1001];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
struct node{
	int x;
	int y;
	int step;
	int d;
};
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		long long mp[101][101]={0};
		bool vis[101][101]={0};
		int p=1;
		int n,m,k;
		int x,y,d;
		char s;
		cin>>n>>m>>k>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>s;
				if(s=='.'){
					mp[i][j]=0;
				}
				else{
					mp[i][j]=1;
				}
			}
		}
		queue<node>q;
		node zht;
		zht.x=x;
		zht.y=y;
		zht.step=0;
		zht.d=d;
		vis[x][y]=1;
		q.push(zht);
		while(1){
			if(q.front().step==k){
				break;
			}
			node temp;
			int nx=q.front().x,ny=q.front().y;
			nx+=dx[q.front().d];
			ny+=dy[q.front().d];
			if(mp[ny][nx]!=1 and ny>=1 and ny<=n and nx>=1 and nx<=m){
				temp.x=nx;
				temp.y=ny;
				temp.d=q.front().d;
				temp.step=q.front().step;
				q.push(temp);
				if(vis[nx][ny]==0){
					p++;
				}
				vis[nx][ny]=1;
				q.pop();
			}
			else{
				q.front().d=(q.front().d+1)%4;
			}
			q.front().step+=1;
		}
		ans[i-1]=p;
	}
	for(int i=0;i<=t-1;i++){
		cout<<ans[i]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
