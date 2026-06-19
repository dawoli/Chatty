#include <bits/stdc++.h>
using namespace std;
#define int long long

string inp;
vector<int> nums;
signed main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);

    cin >> inp;
    for (char a : inp)
    {
        if (a >= '0' && a <= '9') nums.push_back(a - '0');
    }
    sort(nums.begin(), nums.end());
    for (int i = nums.size() - 1; i >= 0; i--) cout << nums[i];

    fclose(stdin);
    fclose(stdout);

    return 0;
}
