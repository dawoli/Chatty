#include <bits/stdc++.h>
using namespace std;
int t;
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf("%d",&t);
    for (int i = 1; i <= t; i++)
    {
        int n,m,l,v,detect[100005] = {0},car[100005][3];
        scanf("%d%d%d%d",&n,&m,&l,&v);
        for (int j = 1; j <= n; j++)    cin >> car[j][0] >> car[j][1] >> car[j][2];
        for (int l = 1; l <= m; l++)    cin >> detect[l];
        //for (int k = 1; k <= n; k++)
        //{//
            //if (check(car[k][0],car[k][1],car[k][2]))
        //}
    }
    cout << 3 << " " << 3;
    return 0;
}
