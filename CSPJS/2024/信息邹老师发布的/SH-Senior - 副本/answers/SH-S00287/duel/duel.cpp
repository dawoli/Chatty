#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n,r[N];
map<int,int> mp;
vector<pair<int,int> > v;
int sum[N];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n ; ++ i)cin >> r[i],mp[r[i]]++;
    v.clear();
    for(pair<int,int> x : mp){
        v.push_back(x);
    }
    int num = v.size() - 1;
    sum[0] = v[0].second;
    for(int i = 1; i < v.size(); ++ i){
        if(v[i].second < sum[i-1]){
            sum[i] = sum[i-1];
        }else{
            sum[i] = v[i].second;
        }
    }
    int ans = sum[num];
    cout << ans << "\n";
    return 0;
}