#include<bits/stdc++.h>
using namespace std;

const int N = 5e5+10;

int n, k;
int a[N];
int ans = -1e9;

void dfs(int step, int cnt){
    if(step > n){
        ans = max(ans, cnt);
        return;
    }

    for(int i=step; i<=n; i++){
        for(int j=i; j<=n; j++){
            int num = a[i];
            for(int tmp=i+1; tmp<=j; tmp++){
                num ^= a[tmp];
            }
            if(num == k){
                dfs(j+1, cnt+1);
            }
        }
    }
}

int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);


    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }

    if(k == 0){
        cout << n << endl;
        fclose(stdin);
        fclose(stdout);
        return 0;
    }

    dfs(1, 0);

    cout << ans << endl;

    fclose(stdin);
    fclose(stdout);

    return 0;
}
