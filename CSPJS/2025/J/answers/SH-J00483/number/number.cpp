#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
ll k,a[1000010];
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	for(char c:s) if(isdigit(c)) a[++k]=c-'0';
	sort(a+1,a+k+1);
	for(ll i=k; i>=1; --i) cout<<a[i];
	return 0;
}
