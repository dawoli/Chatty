#include<bits/stdc++.h>
using namespace std;
char a[1005][1005];
int t,n,m;
struct node{
    int x,y,b,s;
};
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
pair<int,int> bfs(){
	int mnb=1000001,mns=1000001;
	queue<node>q;
	bool vis[1005][1005]={false};
    q.push({1,1,0,0});
    vis[1][1]=true;
    while(q.size()){
        node now=q.front();
        q.pop();
        if(now.x==n&&now.y==m){
        	if(now.b<mnb){
                mnb=now.b;
                mns=now.s;
            }else if(now.b==mnb&&now.s<mns)mns=now.s;
            continue;
		}for(int i=0;i<4;i++){
            int nx=now.x+dx[i];
            int ny=now.y+dy[i];
			if(nx>0&&nx<=n&&ny>0&&ny<=m&&a[nx][ny]!='*'&&!vis[nx][ny]){
                if(a[nx][ny]=='.'){
                    vis[nx][ny]=true;
                    q.push({nx,ny,now.b,now.s+1});
                }if(a[nx][ny]=='$'){
                    vis[nx][ny]=true;
                    q.push({nx,ny,now.b+1,now.s+1});
                }
            }
        }
    }return {mnb,mns};
}signed main(){
	freopen("bomb.in","r",stdin);
	freopen("bomb.out","w",stdout); 
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;i++){
        	for(int j=1;j<=m;j++)cin>>a[i][j];
        }cout<<bfs().first<<' '<<bfs().second<<'\n';
    }
}
