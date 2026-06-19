#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,x,a[100010],ans;
int main() {
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>x,ans=max(ans,++a[x]);
    cout<<ans<<endl;
}