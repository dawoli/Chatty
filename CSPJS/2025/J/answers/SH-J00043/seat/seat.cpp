#include <bits/stdc++.h>
using namespace std;
int n, m, a[105], s;
bool comp(int x, int y)
{
    if (x > y)
        return true;
    else
        return false;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w", stdout);
	cin >> n >> m;
    for (int i = 1; i <= n * m; i++)
        cin >> a[i];
    s = a[1];
    sort(a + 1, a + n * m + 1, comp);
    for (int i = 1; i <= n * m; i++){
        if (a[i] == s){
            if (i % n == 0){
                cout << i / n << " ";
                if (i / n % 2 == 1)
                    cout << n;
                else
                    cout << 1;
            }
            else{
                cout << i / n + 1 << " ";
                if (i / n % 2 == 1)
                    cout << m - i % n + 1;
                else
                    cout << i % n;
            }
            return 0;
        }
    }
}
