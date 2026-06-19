#include<bits/stdc++.h>
using namespace std;
int n,m,ma,mi,d[4][2]={1,0,0,1,-1,0,0,-1},t;
char a[1005][1005];
struct node{
    int x,y,z,val;
};
queue<node> q;
int main(){
    freopen("bomb.in","r",stdin);
    freopen("bomb.out","w",stdout);
    cin>>t;
    while(t--){
        ma=INT_MAX;
        mi=INT_MAX;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)cin>>a[i][j];
        }
        q.push({1,1,0,0});
        while(!q.empty()){
            node t=q.front();
            q.pop();
            if(t.x==n&&t.y==m){
                if(ma>t.z){
                    ma=t.z;
                    mi=t.val;
                }
                else if(ma==t.z){
                    m=min(mi,t.val);
                }
                continue;
            }
            for(int i=0;i<=3;i++){
                int nx=t.x+d[i][0];
                int ny=t.y+d[i][1];
                if(a[nx][ny]=='.'){
                    q.push({nx,ny,t.z,t.val+1});
                }else if(a[nx][ny]=='$'){
                    q.push({nx,ny,t.z+1,t.val+1});
                }
            }
            a[t.x][t.y]='*';
        }
        printf("%d %d\n",ma,mi);
    }
    return 0;
}
