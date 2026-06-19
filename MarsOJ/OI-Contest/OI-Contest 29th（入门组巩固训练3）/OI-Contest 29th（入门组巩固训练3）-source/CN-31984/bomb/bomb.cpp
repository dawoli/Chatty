#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int n,m;
bool flag;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
bool vis[1005][1005];
char a[1005][1005];
void dfs(int x,int y,int num){
    if(x==n && y==m){
        flag=true;
        return;
    }
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(!vis[nx][ny]){
            if(a[nx][ny]=='*'){
                continue;
            }
            if(a[nx][ny]=='$'){
                if(num==0)  continue;
                vis[nx][ny]=true;
                dfs(nx,ny,num-1);
                vis[nx][ny]=false;
            }
            else{
                vis[nx][ny]=true;
                dfs(nx,ny,num);
                vis[nx][ny]=false;
            }
            if(flag)    break;
        }
    }
    return;
}
int res;
void dfs2(int x,int y,int num,int stp){
    //printf("%d %d %d\n",x,y,stp);
    if(x==n && y==m){
       // cout << "end" << endl;
        res=min(res,stp);
        flag=true;
        return;
    }
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(!vis[nx][ny]){
            if(a[nx][ny]=='*'){
                continue;
            }
            if(a[nx][ny]=='$'){
                if(num==0)  continue;
                vis[nx][ny]=true;
                dfs2(nx,ny,num-1,stp+1);
                vis[nx][ny]=false;
            }
            else{
                vis[nx][ny]=true;
                dfs2(nx,ny,num,stp+1);
                vis[nx][ny]=false;
            }
        }
    }
    return;
}
bool check(int x){
    flag=false;
    dfs(1,1,x);
    return flag;
}
void f(){
    cin >> n >> m;
    res=INT_MAX;
    int l=0,r=0;
    memset(vis,true,sizeof(vis));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> a[i][j];
            if(a[i][j]=='$'){
                r++;
            }
            vis[i][j]=false;
        }
    }
    while(l<=r){
        int mid=l+(r-l)/2;
        //printf("%d %d %d\n",l,r,mid);
        if(check(mid)){
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    dfs2(1,1,l,0);
    printf("%d %d\n",l,res);
}
int main(){
    freopen("bomb.in","r",stdin);
    freopen("bomb.out","w",stdout);
    int t;
    cin >> t;
    while(t--)  f();
    return 0;
}
