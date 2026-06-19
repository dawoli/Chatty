#include <bits/stdc++.h>
using namespace std;
long long cnt[15];
int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string s;
    cin >> s;
    for(long long i = 0; i < s.size(); i++){
        if((s[i] - '0') <= 9 && (s[i] - '0') >= 0){
            cnt[(s[i] - '0')]++;
        }
    }
    for(long long i = 9; i >= 0; i--){
        while(cnt[i]){
            cout << i;
            cnt[i]--;
        }
    }
    return 0;
}
