#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> a;
vector<int> attack;

int solve() {
    for(int i=0; i<a.size(); i++){
        for(int j=i; j<a.size(); j++){
            if(a[j] > a[i] && attack[j] == 0 && a[i] != -1){
                a[i] = -1;
                attack[j] = 1;
                continue;
            }
        }
    }
    int ans = 0;
    for(auto it:a)
        if(it>0)
            ans++;
    return ans;
}

int main() {
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin >> n;
    a.resize(n);
    attack.resize(n);
    fill(attack.begin(),attack.end(),0);
    for(int i=0; i<n; i++)
        cin >> a[i];
    sort(a.begin(),a.end());
    cout << solve() << endl;
    return 0;
}
