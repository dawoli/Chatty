#include <bits/stdc++.h>
using namespace std;
int n,m;
string s[60];
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>s[i];
	sort(s+1,s+n+1);
	for (int i=1;i<=n;i++)
		if (s[i]!=s[i-1])
			m++;
	cout<<52-m; 
 } 
