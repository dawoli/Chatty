#include<bits/stdc++.h>
using namespace std;

int n,m,t,minn=100;
struct node{int x,y;};
const int dx[4] = {0,0,-1,1};
const int dy[4] = {-1,1,0,0};
char mp[1010][1010];
queue<node>q;
int bfs(int sx,int sy)
{
	int vis[55][55];
    memset(vis,0,sizeof(vis));
    int cnt=0;
    node st;
    st.x=sx,st.y=sy;
    vis[sx][sy]=0;
    q.push(st);
    while(!q.empty()){
        node u=q.front();q.pop();
        for(int i=0;i<4;i++)
        {
            node v;
            v.x=u.x+dx[i],v.y=u.y+dy[i];
            if(v.x<1 || v.x>n|| v.y<1 || v.y>m || mp[v.x][v.y] == '$' || vis[v.x][v.y]!=0)
                continue;
            vis[v.x][v.y]=vis[u.x][u.y]+1;
            if(v.x==n&&v.y==m){
                minn=min(minn,vis[v.x][v.y]);
            }
            q.push(v);
        }
		cnt++;
    }
    if(minn==100)	return -1;
    return minn;
}

int main()
{
	cin>>t;
	while(t--){
		cin>>n>>m;
	    for(int i=1;i<=n;i++){
	        for(int j=1;j<=m;j++)
	        	cin>>mp[i][j];
	    }
	    cout<<0<<" "<<bfs(1,1)<<endl;
	}
    
    return 0;

}
