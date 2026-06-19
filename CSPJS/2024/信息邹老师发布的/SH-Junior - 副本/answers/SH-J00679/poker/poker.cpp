#include<bits/stdc++.h>
using namespace std;
int n,a[55];
string t;
int loca(string s) {
	char x = s[0],y = s[1];
	int z,ans;
	if(x == 'D')	z = 0;
	if(x == 'C')	z = 13;
	if(x == 'H')	z = 26;
	if(x == 'S')	z = 39;
	if(t[1]>='2' && t[1]<='9') {
		ans=z+(y-'0');
	} else if(t[1]=='A') {
		ans=z+1;
	} else if(t[1]=='T') {
		ans=z+10;
	} else if(t[1]=='J') {
		ans=z+11;
	} else if(t[1]=='Q') {
		ans=z+12;
	} else if(t[1]=='K') {
		ans=z+13;
	}
//	cout << x << " " << y << " " << z << " " << ans << endl;
	return ans;
}
int main() {
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> t;
		a[loca(t)]++;
	}
//	for(int i = 1;i <= 52;i++){
//		cout << a[i] << " ";
//	}
	int sum = 0;
	for(int i = 1; i <= 52; i++) {
		if(a[i]==0)	sum++;
	}
	cout << sum;
	return 0;
}
