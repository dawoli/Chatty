#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

using LL = long long;

int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    
    string s;
    cin >> s;
    vector<LL> nums;
    LL len = s.size();
    for (LL i = 0; i < len; i++) {
        if (isdigit(s[i])) {
            nums.push_back(s[i] - '0');
        }
    }
    sort(nums.begin(), nums.end(), greater<LL>());
    for (LL x : nums) {
        cout << x;
    }
    cout << endl;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
