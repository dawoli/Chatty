#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
ll n, r[N], ans = 0;
int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &r[i]);
    }
    sort(r + 1, r + n + 1);
    int j = 1;
    for (int i = 1; i <= n; i++)
    {
    	//printf("r[%d]=%lld\n", i, r[i]);
        if (r[j] < r[i])
        {
        	//printf("%d kill %d\n", i, j);
            ans++;
            j++;
        }
    }
    printf("%lld\n", n - ans);
    return 0;
}
