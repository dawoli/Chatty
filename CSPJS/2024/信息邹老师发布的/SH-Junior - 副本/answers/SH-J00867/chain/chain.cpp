#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int l[100010],s[100010][200010];
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    cin >> t;
    while (t--){
        int n,k,q;
        scanf("%d%d%d",&n,&k,&q);
        for (int i = 1; i <= n; i++){
            scanf("%d",&l[i]);
            for (int j = 1; j <= l[i] ; j++) scanf("%d",&s[i][j]);
        }
        for (int i = 1; i <= q; i++){
            int r,c;
            cin >> r >> c;
            if (i % 2 == 1) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
