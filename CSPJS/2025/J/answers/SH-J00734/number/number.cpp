#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000010],tot = 0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for (int i = 0;i < s.length();i++){
		if (s[i] >= '0' && s[i] <= '9') a[tot++] = s[i] - '0';
	}
	sort(a,a+tot);
	for (int i = tot - 1;i >= 0;i--) cout << a[i];
}
