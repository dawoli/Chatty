#include <iostream>
#include <algorithm>
using namespace std;

int n, ans;
string s[70];

int main() {

    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);

    cin >> n;
    ans = n;
    for(int i=1;i<=n;i++){
        cin >> s[i];
    }
    sort(s+1, s+1+n);
    for(int i=2;i<=n;i++){
        if(s[i]==s[i-1])ans--;
    }
    cout << 52-ans << endl;
    return 0;
}
