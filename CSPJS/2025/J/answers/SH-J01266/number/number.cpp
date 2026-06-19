#include<bits/stdc++.h>
using namespace std;
string s;
long long a[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>> s;
	/**while(cin>>s)
	{
		//cout<<s;
		if(int(s)>=48&&int(s)<=57)
			a[int(s)-48]++;
	}*/
	//for(int i=0;i<=n;i++)
	//	cout<<s[i];
	for(int i=0;i<=s.length();++i)
	{
		//cout<<s[i];
		if(int(s[i])>=48&&int(s[i])<=57)
			a[int(s[i])-48]++;
	}	
	
	for(int i=9;i>=0;--i)
	{
		//cout<<a[i];
		for(long long j=1;j<=a[i];j++)
			cout<<i;
	}
	return 0;
}
//xxyilu
