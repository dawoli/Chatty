#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD=998244353;
int n,m,c[505],cnt,eff;
string s;
int fact(int n){
    int ans=1;
    for(int i=2;i<=n;i++){
        ans*=i;
        ans%=MOD;
    }
    return ans;
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++){cin>>c[i];if(c[i])eff++;}
    for(int i=0;i<n;i++) if(s[i]=='1') cnt++;
    if(cnt<m||eff<m){cout<<0;return 0;}
    if(m==n){
        cout<<fact(n);
        return 0;
    }
}
