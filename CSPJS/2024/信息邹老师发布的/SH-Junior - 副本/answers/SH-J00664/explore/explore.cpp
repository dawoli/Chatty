#include <iostream>
using namespace std;

int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    bool a[1005][1005],b[1005][1005];
    int ans[10];
    int T,n,m,k;
    int x,y,d;
    cin>>T;
    for (int i=1;i<10;i++){
        ans[i]=0;
    }
    for (int z=1;z<=T;z++){
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for (int i=0;i<=n+1;i++){
            for (int j=0;j<=m+1;j++){
                a[i][j]=0;
                b[i][j]=0;
            }
        }
        char c;
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                cin>>c;
                if (c=='.'){
                    b[i][j]=1;
                }
            }
        }
        a[x][y]=1;
        for (int i=1;i<=k;i++){
            if (d==0){
                if (b[x][y+1]){
                    a[x][y+1]=1;
                    y++;
                }
                else{
                    d=(d+1)%4;
                }
            }
            else if (d==1){
                if (b[x+1][y]){
                    a[x+1][y]=1;
                    x++;
                }
                else{
                    d=(d+1)%4;
                }
            }
            else if (d==2){
                if (b[x][y-1]){
                    a[x][y-1]=1;
                    y--;
                }
                else{
                    d=(d+1)%4;
                }
            }
            else if (d==3){
                if (b[x-1][y]){
                    a[x-1][y]=1;
                    x--;
                }
                else{
                    d=(d+1)%4;
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                if (a[i][j]){
                    ans[z]++;
                }
            }
        }
    }
    for (int i=1;i<=T;i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}
