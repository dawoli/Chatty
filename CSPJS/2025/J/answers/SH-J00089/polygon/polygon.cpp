#include<bits/stdc++.h>
using namespace std;

const int N = 5e3+10;
const int MOD = 998244353;

int n;
int a[N];
int ans = 0;

bool check(int sum, int chosen, int maxn){
    return (chosen >= 3) && (sum > 2*maxn);
}

void dfs(int step, int sum, int chosen, int maxn){
    if(step > n){
        if(check(sum, chosen, maxn)){
            ans = (ans+1) % MOD;
        }
        return;
    }
    dfs(step+1, sum, chosen, maxn);
    dfs(step+1, sum+a[step], chosen+1, max(maxn, a[step]));
}



int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);


    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }

    dfs(1, 0, 0, 0);

    cout << ans << endl;

    fclose(stdin);
    fclose(stdout);

    return 0;
}
