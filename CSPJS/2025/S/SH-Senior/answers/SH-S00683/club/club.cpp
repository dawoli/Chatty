#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;
const int N=32;
int f[N][N][N][N];
int g[201][101][101];
int a[100005][4],b[205];
int n;
int dfs(int i,int j,int k,int l){
    if(i>n)
        return 0;
    if(f[i][j][k][l])
        return f[i][j][k][l];
    if(j+1<=n/2)
        f[i][j][k][l]=max(f[i][j][k][l],dfs(i+1,j+1,k,l)+a[i][1]);
    if(k+1<=n/2)
        f[i][j][k][l]=max(f[i][j][k][l],dfs(i+1,j,k+1,l)+a[i][2]);
    if(l+1<=n/2)
        f[i][j][k][l]=max(f[i][j][k][l],dfs(i+1,j,k,l+1)+a[i][3]);
    return f[i][j][k][l];
}
int calc(int i,int j,int k){
    if(i>n)
        return 0;
    if(g[i][j][k])
        return g[i][j][k];
    if(j+1<=n/2)
        g[i][j][k]=max(g[i][j][k],calc(i+1,j+1,k)+a[i][1]);
    if(k+1<=n/2)
        g[i][j][k]=max(g[i][j][k],calc(i+1,j,k+1)+a[i][2]);
    return g[i][j][k];
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        bool A=1,B=1;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
            if(a[i][3]!=0)
                A=B=0;
            if(a[i][2]!=0)
                A=0;
        }
        if(A){
            for(int i=1;i<=n;i++)   
                b[i]=a[i][1];
            sort(b+1,b+n+1);
            int ans=0;
            for(int i=n;i>n-n/2;i--)
                ans+=b[i];
            printf("%d\n",ans);
        }
        else if(B){
            for(int i=1;i<=n;i++)
                for(int j=0;j<=n/2;j++)
                    for(int k=0;k<=n/2;k++)
                        g[i][j][k]=0;
            printf("%d\n",calc(1,0,0));
        }
        else{
            for(int i=1;i<=n;i++)
                for(int j=0;j<=n/2;j++)
                    for(int k=0;k<=n/2;k++)
                        for(int l=0;l<=n/2;l++)
                            f[i][j][k][l]=0;
            printf("%d\n",dfs(1,0,0,0));
        }
    }
    return 0;
}