#include <bits/stdc++.h>
using namespace std;
int n,monster[100005],ans,k1 = 1;
int main()
{
    freopen("duel.in","r"stdin);
    freopen("duel.out","w",stdout);
    scanf("%d",&n);
    ans = n;
    for (int i = 1; i <= n; i++)
    {
        cin >> monster[i];
    }
    sort(monster + 1,monster + n + 1);
    for (int j = 1; j <= n; j++)
    {
        for (int k = j + 1; k <= n; k++)
        {
            int s = 1;
            if (monster[k1] < monster[k])
            {
                ans--;
                monster[k] = 0;
                s = 0;
                break;
            }
            if (s == 0)    break;
        }
        k1++;
    }
    cout << ans;
    return 0;
}
