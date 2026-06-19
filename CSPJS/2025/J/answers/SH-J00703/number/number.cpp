#include <bits/stdc++.h>
using namespace std;
string s;
int n,a[1000005],cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	n = s.length();
	for (int i = 0;i < n;i++){
		if ('0' <= s[i] && '9' >= s[i]) a[++cnt] = s[i] - '0'; 
	}
	sort(a+1,a+cnt+1);
	for (int i = cnt; i >= 1;i--) cout << a[i];
	return 0;
} 
