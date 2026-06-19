#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
char nw[1000010];
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    cin>>s;ll m=0;
    for (ll i=0;i<s.size();i++) {
        if (s[i]>='0'&&s[i]<='9') {
        	nw[++m]=s[i];
		}
    }
    sort(nw+1,nw+m+1);
	for (ll i=m;i>=1;i--) cout<<nw[i];
    return 0;
}

