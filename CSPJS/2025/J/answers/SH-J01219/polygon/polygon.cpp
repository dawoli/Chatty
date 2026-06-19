#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
int n,a[5005];
long long ans;
bool flag=true;
void dfs(int depth,long long sum,int max_a) {
    if(depth==n+1) {
        if(sum>2*max_a){
            ++ans;
            ans %= MOD;
        }
        return;
    }
    dfs(depth+1,sum+a[depth],max(max_a,a[depth]));
    dfs(depth+1,sum,max_a);
}
int main(){
    ifstream fin("polygon.in");
    ofstream fout("polygon.out");
    fin>>n;
    for(int i=1;i<=n;++i){
        fin>>a[i];
        if(a[i]>1)flag=false;
    }
    if(flag){
        ans = pow(2,n)-n-n*(n-1)/2;
        ans %= MOD;
        fout<<ans<<endl;
    } else {
        dfs(0,0,0);
        fout<<ans/2<<endl;
    }
    return 0;
}