#include<bits/stdc++.h>
using namespace std;
string s;
int a[10];
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;++i) {
		if(s[i]>='0'&&s[i]<='9') {
			a[s[i]-'0']++;
		}
	}
	bool f=1;
	for(int i=9;i>=0;i--) {
		if(f&&(i==0)) {
			cout<<0;
			return 0;
		}
		if(a[i]!=0) f=0;
		for(int j=0;j<a[i];j++) {
			cout<<i;
		}
	}
	return 0;
}
