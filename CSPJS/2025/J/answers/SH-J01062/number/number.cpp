#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int main()
{
	int a[20],i,j;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(i=0;i<20;i++)a[i]=0;
	for(i=0;i<s.size();i++)
	{
		if('0'<=s[i]&&s[i]<='9')a[s[i]-'0']+=1;
	}
	for(i=9;i>=0;i--)
	{
		for(j=a[i];j>0;j--)
		{
			cout<<i;
		}
	}
	return 0;
}
