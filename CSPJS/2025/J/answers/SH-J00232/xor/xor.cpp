#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=500005;
vector<int>buck[MAXN];
int sum[MAXN],dp[MAXN];
int n,k,mann;
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    buck[0].push_back(0);
    for(int i=1;i<=n;i++){
        int h;
        cin>>h;
        sum[i]=sum[i-1]^h;
        buck[sum[i]].push_back(i);
    }
    int mann=0;
    for(int i=1;i<=n;i++){
        int u=sum[i]^k;
        if(buck[u].empty())
            dp[i]=mann;
        else{
            int t;
            for(auto j:buck[u]){
                if(j<=i)
                t=j;
                else
                    break;
            }
            if(t<0)dp[i]=mann;
            else{
                 dp[i]=max(dp[t]+1,mann);
                 mann=max(mann,dp[i]);
            }
        }
    }
    cout<<mann;
    return 0;
}
