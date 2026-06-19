#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
using namespace std;
string a;
int a1a[100010];
int s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;a[i];i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			a1a[s]=a[i]-48;
			s++;
		}
	}
	sort(a1a,a1a+s);
	for(int i=s-1;i>=0;i--)
	cout<<a1a[i];
	return 0;
} 
