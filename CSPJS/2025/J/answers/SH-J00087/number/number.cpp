#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],t;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();++i)
		if(isdigit(s[i]))
			a[++t]=s[i]-'0';
	sort(a+1,a+1+t);
	for(int i=t;i>=1;--i) cout<<a[i];
	cout<<"\n";
	return 0;
}
