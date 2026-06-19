#include <stdio.h>
#include <string.h>
#include <queue>
#define max(a,b) (a)>(b)?(a):(b)
const int MAXN=1e4+10;
// wrong!
//try to greed and failed
// a structure of a determination
struct dtm{
    int sc,dpt;
};
bool operator<(dtm a,dtm b){
    return a.sc<b.sc;
}
// a structure record a member
struct nmem{
    std::priority_queue<dtm>dtms;
    int id;
    int chsd;
}a[MAXN];
// the structure for the club to re-choose
struct cmem{
    int id,ctr;
};
bool operator<(cmem a,cmem b){
    return a.ctr>b.ctr;
}
// the queue of a club
std::priority_queue<cmem> q[3];
// ok,there will be three turns of decision
// In every turn, every club will receive every on who want to join
// and then throw the one who contribute less out in order to keep its number of members
void solve(){
    q[0]=std::priority_queue<cmem>();
    q[1]=std::priority_queue<cmem>();
    q[2]=std::priority_queue<cmem>();
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;++i){
        int c1,c2,c3;
        a[i].dtms=std::priority_queue<dtm>();
        scanf("%d%d%d",&c1,&c2,&c3);
        a[i].dtms.push({c1,0}),
        a[i].dtms.push({c2,1}),
        a[i].dtms.push({c3,2});
        a[i].id=i,a[i].chsd=0;
    }
    for (;;){
        bool flg=1;
        for (int i=1;i<=n;++i){
            if (a[i].chsd||a[i].dtms.empty())continue;
            dtm d=a[i].dtms.top();
            q[d.dpt].push({i,d.sc});
            a[i].chsd=d.sc;
            flg=0;
        }
        if (flg) break;
        for (int i=0;i<3;++i){
            while (q[i].size()>n/2){
                cmem m=q[i].top();
                a[m.id].chsd=0;
                if (!a[m.id].dtms.empty()) 
                    a[m.id].dtms.pop();
                q[i].pop();
            }
        }
    }
    int ans=0;
    for (int i=1;i<=n;++i){
        ans+=a[i].chsd;
    }
    printf("%d\n",ans);
}
/*
// then try dp
// decide to i, and choose 1,2
const int MAXN=1e2+10;
int dp[MAXN][MAXN][MAXN];
int a[MAXN][3];
void solve(){
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;++i){
        int c1,c2,c3;
        scanf("%d%d%d",&c1,&c2,&c3);
        a[i][0]=c1,a[i][1]=c2,a[i][2]=c3;
    }
    int mx=(n<<1);
    int ans=0;
    memset(dp,0,sizeof dp);
    for (int i=1;i<=n;++i){
        for (int j=0;j<=i;++j){
            for (int k=0;k<=i-j;++k){
                if (j>mx||k>mx||i-j-k>mx) continue;
                dp[i][j][k]=
                    max(j>0 ? dp[i-1][j-1][k]+a[i][0]:-1,
                        max(
                            k>0 ? dp[i-1][j][k-1]+a[i][1]:-1,
                            dp[i-1][j][k]+a[i][2]));
                if (i==n){
                    ans=max(ans,dp[i][j][k]);
                }
            }
        }
    }
    /*for (int i=1;i<=n;++i){
        for (int j=0;j<=n;++j){
            for (int k=0;k<=n;++k){
                printf("%d ",dp[i][j][k]);
            }
            putchar('\n');
        }
    }
    printf("%d\n",ans);
}
*/
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    scanf("%d",&t);
    for (int _=0;_<t;++_){
        solve();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}