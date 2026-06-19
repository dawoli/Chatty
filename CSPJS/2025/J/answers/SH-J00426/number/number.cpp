#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+5;
ll a[N],cnt=0;
string s;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	ll l=s.size();
	for(int i=0;i<l;i++) {
		if(s[i]>='0'&&s[i]<='9') {
			a[++cnt]=s[i]-'0';
		}
	}
	sort(a+1,a+cnt+1);
	for(int i=cnt;i>=1;i--) {
		cout << a[i];
	}
	return 0;
}

