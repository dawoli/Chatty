#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,c[N],ans;

int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); cin>>n; int x;
    for(int i=1;i<=n;i++)cin>>x,c[x]++;
    for(int i=N-5;i>=1;i--)ans=max(ans,c[i]);
    cout<<ans<<"\n";return 0;
}