#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10; char s[N]; int cnt[20];
int main() {
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(nullptr);
    int n; cin>>(s+1),n=strlen(s+1);
    for(int i=1;i<=n;i++) if('0'<=s[i]&&s[i]<='9') cnt[s[i]-'0']++;
    for(int i=9;i>=0;i--) while(cnt[i]--) cout<<i;
    return 0;
}
