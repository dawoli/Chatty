#include<bits/stdc++.h>
using namespace std;
int t,n,m,ac,as;char mp[1001][1001];
int bx[]={0,-1,1,0},by[]={1,0,0,-1};
bool vis[1001][1001];
void dfs(int x,int y,int c,int s){
    if(x==n&&y==m){
        if(c<ac){
            ac=c;
            as=s;
        }
        else if(c==ac){
            as=min(s,as);
        }
        return;
    }
    if(c>ac)return;
    for(int i=0;i<4;i++){
        int dx=x+bx[i],dy=y+by[i];
        if(dx<=0||dx>n||dy<=0||dy>m||mp[dx][dy]=='*'){
            continue;
        }
        if(vis[dx][dy]) continue;
        vis[dx][dy]=1;
        if(mp[dx][dy]=='$'){
            dfs(dx,dy,c+1,s+1);
        }else{
            dfs(dx,dy,c,s+1);
        }
        vis[dx][dy]=0;
    }
    return;
}
int main(){
    freopen("bomb.in","r",stdin);
    freopen("bomb.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        scanf("%d",&m);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                scanf("%c",&mp[i][j]);
            }
        }
        ac=INT_MAX;
        as=INT_MAX;
        dfs(1,1,0,0);
        printf("%d %d\n",ac,as);
    }
    return 0;
}

