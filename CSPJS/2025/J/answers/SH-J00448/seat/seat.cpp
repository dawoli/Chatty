#include <iostream>
#include <algorithm>
#define int long long
using namespace std;

int n, m, nums;
int a[200];

bool cmp(int x, int y)
{
    return x > y;
}

signed main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    cin >> n >> m;
    nums = n * m;
    for (int i = 1; i <= nums; i++)
    {
        cin >> a[i];
    }

    int R = a[1];
    int R_index = 1;
    sort(a+1, a+1+nums, cmp);
    for (int i = 1; i <= nums; i++)
    {
        if (a[i] == R)
        {
            R_index = i;
            break;
        }
    }
    // cin >> R_index;

    int ans_one;
    if (R_index % m == 0)
    {
        ans_one = R_index / m;
        cout << R_index / m << " ";
    }
    else
    {
        ans_one = R_index / m + 1;
        cout << R_index / m + 1 << " ";
    }

    if (ans_one % 2 == 0)
    {
        if (R_index % m == 0)
        {
            cout << 1;
        }
        else
        {
            cout << n - R_index % m + 1;
        }
    }
    else
    {
        if (R_index % m == 0)
        {
            cout << n;
        }
        else
        {
            cout << R_index % m;
        }
    }


    fclose(stdin);
    fclose(stdout);
    return 0;
}

