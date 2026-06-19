#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int T,n,m,k,x0,y0,d0,cnt;
char mp[1009][1009];
bool vst[1009][1009];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int move(int x,int y,int d,int k){
    if(!vst[x][y]){
        vst[x][y]=1;
        cnt++;
    }
    if(k==0)return cnt;
    int nx=x+dx[d],ny=y+dy[d];
    if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&mp[nx][ny]=='.') move(nx,ny,d,k-1);
    else{
        for(int i=1;i<4;i++){
            int nx=x+dx[(d+i)%4],ny=y+dy[(d+i)%4];
            if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&mp[nx][ny]=='.'){
                if(k>i) {move(nx,ny,(d+i)%4,k-i-1);break;}
                else return cnt;
            }
        }
    }
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
    cin>>T;
    for(int o=0;o<T;o++){
        cin>>n>>m>>k;
        for(int i=0;i<=n+1;i++)
            for(int j=0;j<=m+1;j++)
                mp[i][j]='x',vst[i][j]=0;

        cin>>x0>>y0>>d0;

        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cin>>mp[i][j];
        cnt=0;
        cout<<move(x0,y0,d0,k)<<endl;
    }
    return 0;
} 
