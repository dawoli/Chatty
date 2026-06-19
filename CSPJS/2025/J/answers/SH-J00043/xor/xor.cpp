#include <bits/stdc++.h>
using namespace std;
int n, k, a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    if (k == 0)
        cout << 0;
    else{
        int s = 0;
        for (int i = 1; i <= n; i++){
            if (a[i] == 1){
                s++;
            }
        }
        cout << s;
    }

	return 0;
}
