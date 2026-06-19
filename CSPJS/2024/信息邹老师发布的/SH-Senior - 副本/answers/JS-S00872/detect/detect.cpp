#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, a, b) for(int i = (a); i >= (b); i--)
using namespace std;
typedef long double ld;
const int N = 1000010;
const ld eps = 1e-9;
int n, m, L, V, s[N], a[N], tot, ans1, ans2;
bool v[N];
pair<int, int> e[N];
bool cmp(const pair<int, int> &x, const pair<int, int> &y) {return x.second < y.second;}

void solve(){
    scanf("%d%d%d%d", &n, &m, &L, &V);
    tot = 0;
    rep(i, 1, n){
        int x, v, a; scanf("%d%d%d", &x, &v, &a);
        if(!a){
            if(v > V) e[++tot] = {x, L};
        }
        else if(a > 0){
            if(v > V) e[++tot] = {x, L};
            else{
                ld t = ((ld)(V-v)) /a; ld dx = v*t + 0.5*t*t*a;
                if(x+dx+eps <= L) e[++tot] = {ceil(x+dx+eps), L};
            }
        }
        else{
            if(v > V){
                ld t = ((ld)(V-v)) /a; ld dx = v*t + 0.5*t*t*a;
                e[++tot] = {x, min(floor(x+dx-eps), (ld)L)};
            }
        }
    }
    // rep(i, 1, tot) fprintf(stderr, "%d %d\n", e[i].first, e[i].second);
    rep(i, 0, L) s[i] = 0;
    rep(i, 1, m) scanf("%d", &a[i]), s[a[i]]++;
    rep(i, 1, L) s[i] += s[i-1];
    ans1 = 0, ans2 = 0;
    sort(e+1, e+tot+1, cmp);
    rep(i, 1, tot){
        v[i] = 0;
        if(s[e[i].second] > (e[i].first ? s[e[i].first-1] : 0)) ans1++, v[i] = 1;
    }
    int pos = 0;
    rep(i, 1, tot) if(v[i] && (!pos || a[pos] < e[i].first)){
        ans2++;
        while(pos < m && a[pos+1] <= e[i].second) pos++;
    }
    printf("%d %d\n", ans1, m - ans2);
}

int main(){
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int T; scanf("%d", &T); while(T--) solve();
    return 0;
}

// g++ -std=c++14 -Wall -Wextra -fsanitize=undefined -Wno-unused-result -O2 detect.cpp -o detect && ./detect