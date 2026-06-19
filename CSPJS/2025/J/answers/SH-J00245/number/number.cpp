#include<bits/stdc++.h>
using namespace std;
const int KS=1e6+10;
int a[KS];
int main() {
	freopen("numder.in","r",stdin);
	freopen("numder.out","w",stdout);
	string s;
	cin>>s;
	int idx=0;
	for(int i=0; i<s.length(); i++) {
		if(isdigit(s[i])) {
			idx++;
			a[idx]=s[i]-'0';
		}
	}
	sort(a+1,a+1+idx);
	for(int i=idx; i>=1; i--) {
		cout<<a[i];
	}
	return 0;
}
