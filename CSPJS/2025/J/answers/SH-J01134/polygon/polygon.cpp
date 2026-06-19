#include<bits/stdc++.h>
using namespace std;
const int mod =998244353;
int n,cnt;
int a[5005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=3){
        int maxx=2*max(max(a[1],a[2]),a[3]);
        if(a[1]+a[2]+a[3]>maxx){
            cout<<1;
            return 0;
        }
    }
    return 0;
}
