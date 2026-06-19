#include<iostream>
#include<cstdio>
using namespace std;
long long ans;
int T, n, a[100005];
long long dfs(int i, int j){
    long long res = 0;
    if(i + j <= 1)    return 0;
    if(j < i - 1){
        int c = 0;
        if(a[i - 1] == a[i]) c = a[i];
        res = dfs(i - 1, j) + c;
    }
    else if(j = i - 1)
        for(int k = 0; k < j; k++){
            int c = 0;
            if(a[k] == a[i]) c = a[i];
            res = max(res, dfs(k, j) + c);
        }
    else if(j = i + 1)
        for(int k = 0; k < i; k++){
            int c = 0;
            if(a[k] == a[j]) c = a[j];
            res = max(res, dfs(i, k) + c);
        }
    else if(j > i + 1){
        int c = 0;
        if(a[j - 1] == a[j]) c = a[j];
        res = dfs(i, j - 1) + c;
    }
    return res;
}
int main(){
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    cin>>T;
    while(T--){
        cin>>n; ans = 0;
        for(int i = 1; i <= n; i++) cin>>a[i];
        for(int i = 0; i < n; i++)  ans = max(ans, max(dfs(n, i), dfs(i, n)));
        cout<<ans<<endl;
    }
    return 0;
}