//explore.cpp
#include<bits/stdc++.h>
using namespace std;
int mp[1001][1001];
int n,m,k;
int ans,nx,ny,nf,dn;
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
bool check(int xt,int yt){
    if(xt<1||xt>n||yt<1||yt>m||mp[xt][yt]==1){
        return false;
    }
    return true;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>dn;
    for(int mm=0;mm<dn;mm++){
        cin>>n>>m>>k;
        cin>>nx>>ny>>nf;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                char t;
                cin>>t;
                mp[i][j]=(t=='.')?0:1;
            }
        }
        ans=1;
        int visit[1001][1001]={};
        visit[nx][ny]=1;
        for(int i=0;i<k;i++){
            int xt=nx+dx[nf],yt=ny+dy[nf];
            if(check(xt,yt)){
                nx=xt;ny=yt;
                if(!visit[nx][ny])
                    ans++;
                visit[nx][ny]=1;
            }else{
                nf=(nf+1)%4;
            }
        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}