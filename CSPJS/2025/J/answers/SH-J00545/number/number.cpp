#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
string a;
long long num[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++)
	{
		if('0'<=a[i]&&a[i]<='9')
		{
			num[a[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=num[i];j++)
		{
			cout<<i;
		}
	}
	return 0;
}
