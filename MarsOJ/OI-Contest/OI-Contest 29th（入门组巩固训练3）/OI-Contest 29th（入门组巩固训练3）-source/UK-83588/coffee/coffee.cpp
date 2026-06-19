#include<bits/stdc++.h>
using namespace std;
long long t,n,m,sum[10],ans;
string s;
int main(){
    freopen("coffee.in","r",stdin);
    freopen("coffee.out","w",stdout);
    cin>>t;
    while(t--){
        memset(sum,0,sizeof(sum));
        for(int i=1;i<=5;i++){
            for(int j=0;j<8;j++){
                cin>>s;
                if(s=="math")sum[i]++;
            }
        }
        scanf("%lld%lld",&n,&m);
        ans=(n/7)*(sum[5]+sum[1]+sum[2]+sum[3]+sum[4]);
        for(int i=0;i<n%7;i++){
            ans+=sum[(m+i)%7];
        }
        printf("%lld\n",ans);
    }
    return 0;
}
