#include<bits/stdc++.h>
using namespace std;
int t,n,m,sum,ans;
char a[1005][1005];
bool b[1005][1005];
int dx[]={0,0,1,-1};
int dy[]={-1,1,0,0};
struct node{
    int x,y,num,step;
    bool operator <(const node &tmp)const{
        return num>tmp.num||(num==tmp.num&&step>tmp.step);
    }
};
void bfs(){
    priority_queue<node > q;
    q.push((node){1,1,0,0});
    b[1][1]=1;
    while(q.size()){
        node u=q.top();
        q.pop();
        if(u.x==n&&u.y==m){
            cout<<u.num<<' '<<u.step<<endl;
            return;
        }
        for(int i=0;i<=3;i++){
            node v;
            v.x=u.x+dx[i];
            v.y=u.y+dy[i];
            if(b[v.x][v.y]||a[v.x][v.y]=='*') continue;
            v.step=u.step+1;
            if(a[v.x][v.y]=='$') v.num=u.num+1;
            else v.num=u.num;
            b[v.x][v.y]=1;
            q.push(v);
        }
    }
}
int main(){
    freopen("bomb.in","r",stdin);
    freopen("bomb.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>m;
        memset(a,0,sizeof a);
        memset(b,1,sizeof b);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
                b[i][j]=0;
            }
        }
        bfs();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
