#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,d[14],c[14],h[14],s[14],ans;
string a;
int main() {
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a;
		if(a[0]=='C') {
			if(a[1]=='A')c[1]=1;
			else if(a[1]=='T')c[10]=1;
			else if(a[1]=='J')c[11]=1;
			else if(a[1]=='Q')c[12]=1;
			else if(a[1]=='K')c[13]=1;
			else c[a[1]-'0']=1;
		}
		if(a[0]=='D') {
			if(a[1]=='A')d[1]=1;
			else if(a[1]=='T')d[10]=1;
			else if(a[1]=='J')d[11]=1;
			else if(a[1]=='Q')d[12]=1;
			else if(a[1]=='K')d[13]=1;
			else d[a[1]-'0']=1;
		}
		if(a[0]=='H') {
			if(a[1]=='A')h[1]=1;
			else if(a[1]=='T')h[10]=1;
			else if(a[1]=='J')h[11]=1;
			else if(a[1]=='Q')h[12]=1;
			else if(a[1]=='K')h[13]=1;
			else h[a[1]-'0']=1;
		}
		if(a[0]=='S') {
			if(a[1]=='A')s[1]=1;
			else if(a[1]=='T')s[10]=1;
			else if(a[1]=='J')s[11]=1;
			else if(a[1]=='Q')s[12]=1;
			else if(a[1]=='K')s[13]=1;
			else s[a[1]-'0']=1;
		}
	}
	for(int i=1;i<=13;i++) {
		if(d[i]==0)ans++;
		if(c[i]==0)ans++;
		if(h[i]==0)ans++;
		if(s[i]==0)ans++;
	}
	cout<<ans;
	return 0;
}
