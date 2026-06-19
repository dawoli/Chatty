#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,s2="";
	cin>>s;
	for(int i=0;i<=s.length()-1;i++)
	{
		if('0'<=s[i]&&s[i]<='9')
		{
			s2+=s[i];
		}
	}
	for(int i=0;i<=s2.length()-1;i++)
	{
		a[i+1]=s2[i]-'0';
	}
	sort(a+1,a+s2.length()+1);
	for(int i=s2.length();i>=1;i--) 
	{
		cout<<a[i];
	}
	return 0;	
} 
