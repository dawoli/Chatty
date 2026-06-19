#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    long long n, k, ans = 0, tmp = 0;
    cin >> n >> k;
    long long a[n];
    for (int i = 0; i < n; i ++)
    {
        cin >> a[i];
        tmp = tmp ^ a[i];
        if (tmp == k){
            ans ++;
            tmp = 0;
        }
        //cout << tmp << " ";
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
