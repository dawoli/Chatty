#include <bits/stdc++.h>
using namespace std;
struct node{
    int x,y,d,step,cnt;
};
char c[1010][1010];
bool flag[1010][1010];
int n,m,k;
int x_0,y_0,d_0;
int ans=-1;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
void bfs(){
    queue<node> q;
    q.push({x_0,y_0,d_0,k});
    while(!q.empty()){
        node tmp=q.front();
        q.pop();
        if(tmp.step<=0 && tmp.cnt>=ans){ans=tmp.cnt;continue;}
        int x1=tmp.x,y1=tmp.y,d1=tmp.d;
        int xnow=x1+dx[d1],ynow=y1+dy[d1];
        if(xnow>=1 && xnow<=n && ynow>=1 && ynow<=m && tmp.step!=0 && c[xnow][ynow]=='.'){
            q.push({xnow,ynow,d1,tmp.step-1,tmp.cnt+1});
        }
        else{
            for(int i=0;i<4;i++){
                d1=(d1+1)%4;tmp.step--;
                int xnow=x1+dx[d1],ynow=y1+dy[d1];
                if(tmp.step<=0 && tmp.cnt>=ans){ans=tmp.cnt;break;}
                if(xnow>=1 && xnow<=n && ynow>=1 && ynow<=m && tmp.step!=0 && c[xnow][ynow]=='.'){
                    q.push({xnow,ynow,d1,tmp.step-1,tmp.cnt+1});
                    break;
                }
            }
        }
    }
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        memset(flag,false,sizeof(flag));
        cin>>n>>m>>k;
        cin>>x_0>>y_0>>d_0;
        for(int j=1;j<=n;j++)for(int k=1;k<=m;k++)cin>>c[j][k];
        bfs();
        cout<<ans+1<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
