#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=100005;
int t,n,a[maxn][5];
struct M{
    int a,b,c,res,nxt,sunshi;
}club[5][maxn];
int ctot[5];
void handle(int k){
    int maxx=-1,mpos=0,maxxx=-1,mmpos=0;
    for(int j=1;j<=3;j++)if(a[k][j]>maxx){maxx=a[k][j];mpos=j;}
    for(int j=1;j<=3;j++){
        if(j==mpos)continue;
        if(a[k][j]>maxxx){maxxx=a[k][j];mmpos=j;}
    }
    // for(int j=1;j<=3;j++){
    //     if(a[k][j]>maxx){maxx=a[k][j];mpos=j;}
    //     else if(a[k][j]>maxxx){maxxx=a[k][j];mmpos=j;}
    // }
    club[mpos][++ctot[mpos]]={a[k][1],a[k][2],a[k][3],a[k][mpos],mmpos,maxxx-maxx};
}
void handle2(int k){// k is club number
    sort(club[k]+1,club[k]+1+ctot[k],[](M a,M b){if(a.sunshi==b.sunshi)return a.res>b.res;return a.sunshi<b.sunshi;});
    // for(int i=1;i<=ctot[k];i++)printf("p %d a=%d b=%d c=%d sunshi=%d\n",i,club[k][i].a,club[k][i].b,club[k][i].c,club[k][i].sunshi);
    for(int i=n/2+1;i<=ctot[k];i++){
        M p=club[k][i];
        int mmpos=p.nxt;
        int res=0;
        if(mmpos==1){
            res=p.a;
        }else if(mmpos==2){
            res=p.b;
        }else res=p.c;
        club[mmpos][++ctot[mmpos]]={p.a,p.b,p.c,res,mmpos,0};
    }
    ctot[k]=n/2;
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    while(t--){
        memset(club,0,sizeof(club));
        memset(ctot,0,sizeof(ctot));
        cin>>n;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=3;j++)
                cin>>a[i][j];
        for(int i=1;i<=n;i++)
            handle(i);
        // for(int i=1;i<=3;i++)
        //     printf("ctot[%d]=%d\n",i,ctot[i]);
        for(int j=1;j<=3;j++)
            if(ctot[j]>n/2)
                handle2(j);
        int ans=0;
        for(int j=1;j<=3;j++){
            for(int i=1;i<=ctot[j];i++)
                ans+=club[j][i].res;
        }cout<<ans<<'\n';
    }
    return 0;
}