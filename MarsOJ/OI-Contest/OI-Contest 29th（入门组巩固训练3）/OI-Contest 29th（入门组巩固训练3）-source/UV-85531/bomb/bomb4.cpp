#include<bits/stdc++.h>
using namespace std;
int t,n,m,ac,as;char mp[1001][1001];
int bx[]={0,-1,1,0},by[]={1,0,0,-1};
bool vis[1001][1001];
struct node{
    int x,y;
    int c,s;
    int f;
};
int main(){
    freopen("bomb.in","r",stdin);
    freopen("bomb.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>mp[i][j];
            }
        }
        queue<node> q;
        q.push(node{1,1,0,0,-1});
        ac=INT_MAX;
        as=INT_MAX;
        memset(vis,0,sizeof(vis));
        while(!q.empty()){
            node tmp=q.front();
            q.pop();
            if(tmp.x==n&&tmp.y==m){
                if(tmp.c<ac){
                    ac=tmp.c;
                    as=tmp.s;
                }else if(tmp.c==ac){as=min(tmp.s,as);}
                continue;
            }
            if(tmp.c>ac)continue;
            for(int i=0;i<4;i++){
                int dx=tmp.x+bx[i],dy=tmp.y+by[i];
                if(dx<=0||dx>n||dy<=0||dy>m||mp[dx][dy]=='*'){
                    continue;
                }

                if(vis[dx][dy]) continue;
                //if(i==tmp.f)continue;
                //vis[dx][dy]=1;
                if(mp[dx][dy]=='$'){
                    q.push(node{dx,dy,tmp.c+1,tmp.s+1,3-i});
                }else{
                    q.push(node{dx,dy,tmp.c,tmp.s+1,3-i});
                }

            }
            vis[tmp.x][tmp.y]=1;
        }
        cout<<ac<<' '<<as<<endl;
    }
    return 0;
}

