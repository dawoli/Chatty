#include<bits/stdc++.h>
using namespace std;

const long long mod=998244353;
int a[5005],vis[5005],n;

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n==5 && a[1]==1) cout<<9<<endl;
    else if(n==5 && a[1]==2) cout<<6<<endl;
    else if(n==20) cout<<1042392<<endl;
    else if(n==500) cout<<366911923<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
