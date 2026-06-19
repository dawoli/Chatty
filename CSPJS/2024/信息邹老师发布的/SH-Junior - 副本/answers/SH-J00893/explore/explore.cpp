#include <bits/stdc++.h>
using namespace std;
int mapp[1010][1010];
int di[4]={0,1,0,-1},dj[4]={1,0,-1,0};
void dfs(int xs,int ys,int ds,int k,int n,int m){
    int kk=0;
    if(kk==k){
        return;
    }
    int x=xs+di[ds];
    int y=ys+dj[ds];
    if(x>=1 && x<=n && y>=0 && y<m){
            mapp[x][y]=1;
    }else{
        ds=(ds+1)%4;
        kk++;
    }
    dfs(x,y,ds,k,n,m);

}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        int xs,ys,ds;
        cin>>xs>>ys>>ds;
        int epd=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<m;j++){
                mapp[i][j]=0;
            }
        }
        dfs(xs,ys,ds,k,n,m);
        for(int i=1;i<=n;i++){
            for(int j=0;j<m;j++){
                if(mapp[i][j]=1){
                    epd++;
                }
            }
        }
        cout<<epd<<endl;
    }
    return 0;
}
