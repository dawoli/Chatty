#include<bits/stdc++.h>
using namespace std;
struct node{
    int x,y,step;
};
queue<node>q;
int t,n,m,a[1001][1001],vis[1001][1001],cm;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int main(){
    freopen("bomb.in","r",stdin);
    freopen("bomb.out","w",stdout);
    cin>>t;
    while(t--){
        cm=0;
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                char x;
                cin>>x;
                if(x=='$')a[i][j]=1,cm++;
                if(x=='*')a[i][j]=2;
            }
        }
        if(n==1){
            cout<<cm<<' '<<m-1<<endl;
            continue;
        }
        if(cm==0){
            cout<<0<<' ';
            q.push({1,1,0});
            while(!q.empty()){
                node t=q.front();
                q.pop();
                if(t.x==n&&t.y==m){
                    cout<<t.step<<endl;
                    break;
                }
                vis[t.x][t.y]=1;
                for(int i=0;i<4;i++){
                    int xx=t.x+dx[i];
                    int yy=t.y+dy[i];
                    if(xx<1||xx>n||yy<1||yy>m)continue;
                    if(vis[xx][yy]==1)continue;
                    if(a[xx][yy]==2)continue;
                    q.push({xx,yy,t.step+1});
                }
            }
        }
    }
}
