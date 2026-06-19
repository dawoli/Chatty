#include<bits/stdc++.h>
using namespace std;
#define int long long
int h[20];
signed main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	for(int i=0;i<s.size();i++) {
		if('0'<=s[i]&&s[i]<='9') h[s[i]-'0']++;
	}
	bool f=0;
	for(int i=9;i>=0;i--) {
		if(i==0&&f==0) {
			cout << 0 << endl;
			return 0;
		}
		if(f==0&&h[i]!=0) f=1;
		for(int j=1;j<=h[i];j++) {
			cout << i;
		}
	}
	cout << endl;
	return 0;
} 
