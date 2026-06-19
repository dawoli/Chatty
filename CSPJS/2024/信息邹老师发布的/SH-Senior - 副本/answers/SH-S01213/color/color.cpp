// espyjump JZJF 24-10-26
// Nunc sola via est necare aut necari, per aspera ad astra.
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

void solve(){
    int m;
    long long rp,bp;
    cin>>m;
    vector<int> a(m);
    for(auto &i:a) cin>>i;
    vector<vector<vector<long long> > > dp(m,vector<vector<long long> >(2,vector<long long>(3)));
    dp[0][0][0]=0;
    dp[0][0][1]=a[0];
    dp[0][0][2]=0;
    dp[0][1][0]=0;
    dp[0][1][1]=0;
    dp[0][1][2]=a[0];
    // bbp=a[0];brp=a[0];
    // rbp=a[0];rrp=a[0];
    for(int i=1;i<m;i++){
        // If the color selected is red
        if(dp[i-1][0][0]>dp[i-1][1][0]){
            dp[i][0][0]=dp[i-1][0][0];
            if(dp[i-1][0][1]==a[i]){
                dp[i][0][0]+=a[i];
            }
            dp[i][0][1]=a[i];
            dp[i][0][2]=dp[i-1][0][2];
        }
        else{
            dp[i][0][0]=dp[i-1][1][0];
            if(dp[i-1][1][1]==a[i]){
                dp[i][0][0]+=a[i];
            }
            dp[i][0][1]=a[i];
            dp[i][0][2]=dp[i-1][1][2];
        }
        // If the color selected is blue
        if(dp[i-1][0][0]>dp[i-1][1][0]){
            dp[i][0][0]=dp[i-1][0][0];
            if(dp[i-1][0][2]==a[i]){
                dp[i][1][0]+=a[i];
            }
            dp[i][1][2]=a[i];
            dp[i][1][1]=dp[i-1][0][1];
        }
        else{
            dp[i][1][0]=dp[i-1][1][0];
            if(dp[i-1][1][2]==a[i]){
                dp[i][1][0]+=a[i];
            }
            dp[i][1][2]=a[i];
            dp[i][1][1]=dp[i-1][1][1];
        }
        // cout<<"i "<<i<<" rp;bp "<<rp<<" "<<bp<<endl;
    }
    // for(auto &i:dp) cout<<"("<<i[0][0]<<","<<i[0][1]<<","<<i[0][2]<<") "<<"("<<i[1][0]<<","<<i[1][1]<<","<<i[1][2]<<")"<<endl;
    cout<<max(dp[m-1][0][0],dp[m-1][1][0]);
}

int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    cin>>t;
    for(int i=0;i<t;i++) solve();
    return 0;
}