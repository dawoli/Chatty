#include<iostream>
#include<fstream>
#define int long long
using namespace std;
int a[6][9],p[57];//a:shuxue p:di k jiekejizhiqianyoujijieshuxueke
string s;
void solve(){
    for(int i=1;i<=5;i++)
        for(int j=1;j<=8;j++){
            a[i][j]=0;
            p[(i-1)*8+j]=p[(i-1)*8+j-1];
            cin>>s;
            if(s=="math"){
                a[i][j]=1;
                p[(i-1)*8+j]++;    
            }
        }
    for(int i=41;i<=56;i++)
        p[i]=p[i-1];
    int n,m;
    scanf("%lld%lld",&n,&m);
    int t1=n/7;//gongyoujizhou
    int t2=n%7;//haiyoujitian
    int tmp1=t1*p[56];
    int tmp2=0;
    for(int i=m;i<m+t2;i++){
        int tmp=i%7;
        if(!tmp)
            tmp=7;
        tmp2+=p[tmp*8]-p[(tmp-1)*8];
    }
    printf("%lld\n",tmp1+tmp2);
    // for(int i=1;i<=56;i++)
    //     printf("%d\t",i);
    // printf("\n");
    // for(int i=1;i<=56;i++)
    //     printf("%d\t",p[i]);
    return;
}
signed main(){
    freopen("coffee.in","r",stdin);
    freopen("coffee.out","w",stdout);
    int T;
    scanf("%lld",&T);
    while(T--)
        solve();
    return 0;
}