#include<bits/stdc++.h>
using namespace std;
int n,m,a,cnt; 
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='0')break;
		else cnt++;
	} 
	for(int i=1;i<=n;i++)cin>>a;
	cout<<cnt*(cnt-1)/2;
	return 0;
} 
