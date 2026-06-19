#include<bits/stdc++.h>
using namespace std;
int a[15],b[15];
int main(){
    freopen("coffee.in","r",stdin);
    freopen("coffee.out","w",stdout);
    int T;cin>>T;
    while(T--){
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for(int i=1;i<=5;i++){
            for(int j=1;j<=8;j++){
                string x;cin>>x;
                a[i]+=(x=="math");
            }
        }
        int n,m,ans=0;cin>>n>>m;
        int week=n/7;
        for(int i=1;i<=7;i++) b[i]+=week;
        for(int i=m,j=1;j<=n-week*7;i++,j++){
            if(i>7) i-=7;
            b[i]++;
        }
        for(int i=1;i<=5;i++){
            ans+=a[i]*b[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}
