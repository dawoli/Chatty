#include <bits/stdc++.h>
using namespace std;
string str;
int T,n,m,cnt,ans,a[5];
int main(){
    freopen("coffee.in","r",stdin);
    freopen("coffee.out","w",stdout);
    cin>>T;
    for(int i=0;i<T;i++){
        ans=0;
        for(int j=0;j<5;j++){
            cnt=0;
            for(int k=0;k<8;k++){
                cin>>str;
                if(str=="math")
                    cnt++;
            }a[j]=cnt;}
        cin>>n>>m;
        cnt=a[0]+a[1]+a[2]+a[3]+a[4];
        ans=(n-(7-m+1))/7*cnt;
        for(int j=m;j<=5;j++)
            ans=ans+a[j-1];
        for(int j=1;j<=(n-(7-m+1))%7;j++)
            ans=ans+a[j-1];
        cout<<ans<<endl;
    }
    return 0;
}
