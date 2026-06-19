#include <bits/stdc++.h>
using namespace std;
int a[1000004];
int main(){
	freopen("number3.in","r",stdin);
	freopen("number3.out","w",stdout);
	int m=0;
	string s;cin>>s;
	for(int i=0;i<s.size();i++)
		if('0'<=s[i]&&s[i]<='9')
			a[++m]=s[i]-'0';
	sort(a+1,a+m+1);
	for(;m;m--) cout<<a[m];
	return 0;
} 
