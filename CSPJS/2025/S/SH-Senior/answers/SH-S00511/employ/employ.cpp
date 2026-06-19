#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

int read() {
    int f=1,x=0;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-'){f=-1;}ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return f*x;
}

const int MOD = 998244353;

long long fact(int x) {
    long long ans = 1;
    for (int i = 1; i <= x; ++i) {
        ans = ans * i % MOD;
    }
    return ans % MOD;
}

int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    int n = read(); int m = read();
    string s; cin >> s;
    cout << fact(n) << '\n';
}