#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int t,n=0;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	t=s.length();
	for(int i=0;i<t;i++) {
		if(s[i]>='0'&&s[i]<='9') {
			a[n]=s[i]-48;
			n++;		
		}
	}
	sort(a,a+n);
	for(int i=n-1;i>=0;i--) {
		cout<<a[i];
	}
	return 0;
}
