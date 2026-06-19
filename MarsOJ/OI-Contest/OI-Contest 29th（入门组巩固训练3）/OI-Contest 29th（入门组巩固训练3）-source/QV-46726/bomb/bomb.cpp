#include <bits/stdc++.h>
using namespace std;
int stp[1010][1010]={},fx[]={0,-1,0,1},fy[]={-1,0,1,0},ans,tx,ty,n,m,t,x,y,k;
deque<pair<pair<int,int>,int> >q;
bool vis[1010][1010]={};
string s[1010]={};
char c='\0';
string read(){
    while(c!='.'&&c!='*'&&c!='$') c=getchar();
    string s="";
    for(;c=='.'||c=='*'||c=='$';c=getchar()) s+=c;
    return s;
}
int read1(){
    while(c<'0'||c>'9') c=getchar();
    int x=0;
    for(;c>='0'&&c<='9';c=getchar()) x=x*10+c-'0';
    return x;
}
void dfs(int x,int y,int now,int sum){
    if(x==n&&y==m){
        ans=now;
        return;
    }
    if(now<ans){
        now++;
        vis[x][y]=true;
        int tx,ty;
        for(int i=0;i<4;i++){
            tx=x+fx[i];
            ty=y+fy[i];
            if(tx&&ty&&tx<=n&&ty<=m&&!vis[tx][ty]&&s[tx][ty-1]!='*'){
                if(s[tx][ty-1]=='.') dfs(tx,ty,now,sum);
                else if(sum<stp[n][m]) dfs(tx,ty,now,sum+1);
                if(ans<n+m-1){
                    vis[x][y]=false;
                    return;
                }
            }
        }
        vis[x][y]=false;
    }
}
int main(){
    freopen("bomb.in","r",stdin);
    freopen("bomb.out","w",stdout);
    t=read1();
    while(t--){
        n=read1();
        m=read1();
        for(int i=1;i<=n;i++) s[i]=read();
        q.push_back(make_pair(make_pair(1,1),0));
        memset(stp,-1,sizeof(stp));
        while(!q.empty()){
            x=q.front().first.first;
            y=q.front().first.second;
            k=q.front().second;
            q.pop_front();
            if(stp[x][y]>-1) continue;
            stp[x][y]=k;
            if(x==n&&y==m){
                while(!q.empty()) q.pop_back();
                break;
            }
            for(int i=0;i<4;i++){
                tx=x+fx[i];
                ty=y+fy[i];
                if(tx&&ty&&tx<=n&&ty<=m&&s[tx][ty-1]!='*'){
                    if(s[tx][ty-1]=='.') q.push_front(make_pair(make_pair(tx,ty),k));
                    else q.push_back(make_pair(make_pair(tx,ty),k+1));
                }
            }
        }
        cout<<stp[n][m]<<" ";
        ans=INT_MAX;
        dfs(1,1,0,0);
        cout<<ans<<endl;
    }
    return 0;
}
