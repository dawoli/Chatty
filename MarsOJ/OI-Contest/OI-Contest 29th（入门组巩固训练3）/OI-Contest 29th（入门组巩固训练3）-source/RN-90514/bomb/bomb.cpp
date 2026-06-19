#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,n,m,a[1005][1005][2],dirs[4][2]={1,0,-1,0,0,1,0,-1};
struct node{
    int x,y,stp,bob;
};
int main(){
    freopen("bomb.in","r",stdin);
    freopen("bomb.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n>>m;
        memset(a,0x3f,sizeof(a));
        string s[n+1];
        queue<node> q;
        for(int i=0;i<n;i++)
            cin>>s[i];
        if(s[0][0]=='.'){
            q.push(node{0,0,0,0});
            a[0][0][0]=0,a[0][0][1]=0;
        }else{
            q.push(node{0,0,0,1});
            a[0][0][0]=0,a[0][0][1]=1;
        }
        while(!q.empty()){
            node tmp=q.front();q.pop();
            if(tmp.x==n-1&&tmp.y==m-1){
                cout<<tmp.bob<<" "<<tmp.stp<<"\n";
                break;
            }
            for(int i=0;i<4;i++){
                int nx=tmp.x+dirs[i][0],ny=tmp.y+dirs[i][1];
                if(nx>=0&&nx<n&&ny>=0&&ny<m){
                    if(s[nx][ny]=='$'){
                        if(a[nx][ny][1]>tmp.bob+1||a[nx][ny][1]==tmp.bob+1&&a[nx][ny][0]>tmp.stp+1){
                            a[nx][ny][0]=tmp.stp+1;a[nx][ny][1]=tmp.bob+1;
                            q.push(node{nx,ny,tmp.stp+1,tmp.bob+1});
                        }
                    }else if(s[nx][ny]=='.'){
                        if(a[nx][ny][1]>tmp.bob||a[nx][ny][1]==tmp.bob&&a[nx][ny][0]>tmp.stp+1){
                            a[nx][ny][0]=tmp.stp+1;a[nx][ny][1]=tmp.bob;
                            q.push(node{nx,ny,tmp.stp+1,tmp.bob});
                        }
                    }
                }
            }

        }
    }
    return 0;
}
