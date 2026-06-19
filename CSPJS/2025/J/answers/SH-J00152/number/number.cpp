#include <bits/stdc++.h>
using namespace std; 
long long cnt[128];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
		cnt[s[i]]++;
	for(char i='9';i>='0';i--)
		while(cnt[i]--)
			cout<<i; 
	return 0;
}
