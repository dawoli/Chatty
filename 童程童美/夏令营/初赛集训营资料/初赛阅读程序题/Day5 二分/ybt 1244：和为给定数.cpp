#include <bits/stdc++.h>
using namespace std;
#define N 100005 
int main()
{
    int n, m, a[N], num;
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    cin >> m;
    sort(a+1, a+1+n);
    for(int i = 1; i <= n && a[i] < m; ++i)
    {
        num = m - a[i];
        int l = i+1, r = n;
        while(l <= r)
        {
            int mid = (l+r)/2;
            if(a[mid] >= num)
                r = mid-1;
            else
                l = mid+1;
        }
        if(a[l] == num)
        {
            cout << a[i] << ' ' << num;
            return 0;
        }
    }
    cout << "No";
    return 0;
}
