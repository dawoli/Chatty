#include <bits/stdc++.h>
using namespace std;
int x[1010000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=1;
	for (int i=0;i<s.size();i++){
		if (s[i]>='0' && s[i]<='9') x[n++]=s[i]-'0';
	}
	sort(x+1,x+n);
	for (int i=n-1;i>=1;i--) cout<<x[i];
} 
