#include <bits/stdc++.h>
using namespace std;

vector<short> nums;

int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string s;
    cin >> s;
    for (auto x : s) if (isdigit(x)) nums.push_back(x - '0');
    sort(nums.begin(), nums.end());
    reverse(nums.begin(), nums.end());
    for (auto i : nums) cout << i;
    cout << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
