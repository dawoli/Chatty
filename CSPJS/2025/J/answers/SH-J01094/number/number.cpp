#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;

	int o=0;
	int p=s.size();
	for(int i=0; i<p; i++) {
		if(isdigit(s[i])) {
			a[o]=(s[i]-'0');
			o++;
		}
	}
	sort(a,a+o);
	for(int i=o-1; i>=0; i--) {
		cout<<a[i];
	}
	return 0;
}
