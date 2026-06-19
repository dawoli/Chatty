#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

int read() {
    int f=1,x=0;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-'){f=-1;}ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return f*x;
}

vector<pair<string,string>> match;

int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    int n = read(), q = read();
    for (int i = 1; i <= n; ++i) {
        string a, b;
        cin >> a >> b;
        match.push_back({a, b});    
    }
    while (q--) {
        string s;
        cin >> s;
        int ans = 0;
        for (char c : s) {
            if (c == 'b') ++ans;
        }
        cout << ans << '\n';
    }
    return 0;
}