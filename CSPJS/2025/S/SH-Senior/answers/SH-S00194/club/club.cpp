#include<bits/stdc++.h>
using namespace std;
const int N=200+1;
struct per{
    int a,b,c,i;
} a[N];
int fen[N];
bool cmpa(per a1,per b1){
    return a1.a<b1.a;
}
bool cmpb(per a1,per b1){
    return a1.b<b1.b;
}
bool cmpc(per a1,per b1){
    return a1.c<b1.c;
}
int f[N][N][N];
void solve(){
    int n;
    cin>>n;
    int ans=0;
    //cout<<"---";
    for(int i=1;i<=n;i++){
        cin>>a[i].a>>a[i].b>>a[i].c;
        a[i].i=i;
    }
    for(int i=0;i<=n/2;i++){
        for(int j=0;j<=n/2;j++){
            for(int k=0;k<=n/2;k++){
                f[i][j][k]=0;
            }
        }
    }
    for(int i=0;i<=n/2;i++){
        for(int j=0;j<=n/2;j++){
            for(int k=0;k<=n/2;k++){
                f[i][j][k]=max((i==0?0:(f[i-1][j][k]+a[i+j+k].a)),max((j==0?0:f[i][j-1][k]+a[i+j+k].b),(k==0?0:f[i][j][k-1]+a[i+j+k].c)));
            }
        }
    }
    for(int i=0;i<=n/2;i++){
        for(int j=0;j<=n/2;j++){
            ans=max(ans,f[i][j][n-i-j]);
        }
    }
    cout<<ans<<'\n';
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}