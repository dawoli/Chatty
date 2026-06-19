#include<bits/stdc++.h>
using namespace std;
long long num[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for (long long i=0;i<s.length();i++)
	{
		if (s[i]>=48&&s[i]<=57)
		{
			num[s[i]-48]++;
		}
	}
	for (long long i=9;i>=0;i--)
	{
		for (long long j=1;j<=num[i];j++)
		{
			cout<<i; 
		}
	}
	cout<<endl;
	return 0;
}
