#include <bits/stdc++.h>
using namespace std;
int n, a[5005], ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 3; i <= n; i++){
        if (i == 3){
            for (int x = 1; x <= n - 2; x++){
                for (int y = x + 1; y <= n - 1; y++){
                    for (int z = y + 1; z <= n; z++){
                        int s = a[x] + a[y] + a[z] , m = max(max(a[x], a[y]), a[z]);
                        if (s > m * 2)
                            ans++;
                    }
                }
            }
        }
        else{
            int s = 0, m = 0;
            for (int j = 1; j <= i; j++){
                s += a[j];
                m = max(m, a[j]);
                if (s > m * 2)
                    ans++;
            }
        }

    }
    cout << ans % 998244353;
	return 0;
}
