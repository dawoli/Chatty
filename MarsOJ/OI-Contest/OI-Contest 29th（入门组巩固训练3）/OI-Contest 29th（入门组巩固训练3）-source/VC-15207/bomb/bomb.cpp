#include<bits/stdc++.h>
using namespace std;
int n,m,t;
char f[1005][1005];
int h[1005][1005],k[1005][1005],dir[4][2]={1,0,0,1,-1,0,0,-1};
struct node{int x,y,c,l;};
struct anss{int c,l;};
anss bfs(){
    queue<node> q;
    node tmp;
    q.push(node{1,1,0,0});
    anss ans={INT_MAX,INT_MAX};
    while(!q.empty()){
        tmp=q.front();
        q.pop();
        for (int i=0;i<4;i++){
            int nx=tmp.x+dir[i][0];
            int ny=tmp.y+dir[i][1];
            if (nx<1 || ny<1 || nx>n || ny>m) continue;

            if (nx==n && ny==m) {
                if (tmp.c<ans.c) ans=anss{tmp.c,tmp.l+1};
                else if (tmp.c==ans.c && tmp.l<ans.l) ans=anss{tmp.c,tmp.l+1};
                continue;
            }
            if (f[nx][ny]=='.' && tmp.c<=h[nx][ny]) {
                if (tmp.c<h[nx][ny] || (tmp.c==h[nx][ny] && tmp.l+1<k[nx][ny])){
                    q.push(node{nx,ny,tmp.c,tmp.l+1});
                    h[nx][ny]=tmp.c;
                    k[nx][ny]=tmp.l+1;
                }
            }
            else if (f[nx][ny]=='$' && tmp.c+1<=h[nx][ny]) {
                if (tmp.c+1<h[nx][ny] || (tmp.c+1==h[nx][ny] && tmp.l+1<k[nx][ny])){
                    q.push(node{nx,ny,tmp.c+1,tmp.l+1});
                    h[nx][ny]=tmp.c+1;
                    k[nx][ny]=tmp.l+1;
                }
            }
        }
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("bomb.in","r",stdin);
    freopen("bomb.out","w",stdin);
    cin>>t;
    while(t--){
        cin>>n>>m;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++) {cin>>f[i][j];h[i][j]=INT_MAX;k[i][j]=INT_MAX;}
        anss ans=bfs();
        cout<<ans.c<<" "<<ans.l<<"\n";
    }
    return 0;
}
