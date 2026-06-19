#include<bits/stdc++.h>
using namespace std;

string a;
int len,n,ans;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	len=a.length();
	for(int i=0;i<=len-1;i++)
	{
		if(a[i]=='9')cout<<a[i];
	}
	for(int i=0;i<=len-1;i++)
	{
		if(a[i]=='8')cout<<a[i];
	}
	for(int i=0;i<=len-1;i++)
	{
		if(a[i]=='7')cout<<a[i];
	}
	for(int i=0;i<=len-1;i++)
	{
		if(a[i]=='6')cout<<a[i];
	}
	for(int i=0;i<=len-1;i++)
	{
		if(a[i]=='5')cout<<a[i];
	}
	for(int i=0;i<=len-1;i++)
	{
		if(a[i]=='4')cout<<a[i];
	}
	for(int i=0;i<=len-1;i++)
	{
		if(a[i]=='3')cout<<a[i];
	}
	for(int i=0;i<=len-1;i++)
	{
		if(a[i]=='2')cout<<a[i];
	}
	for(int i=0;i<=len-1;i++)
	{
		if(a[i]=='1')cout<<a[i];
	}
	for(int i=0;i<=len-1;i++)
	{
		if(a[i]=='0')cout<<a[i];
	}
}
