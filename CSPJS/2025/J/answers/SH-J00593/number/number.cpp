#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
long long ans[10000009];
long long num[10];
int cmp(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string in;
	long long d=0;
	cin>>in;
	for(long long i=0;i<in.size();i++)
	{
		if(in[i]=='0')
		{
			ans[d]=0;
			d++;
		}
		else if(in[i]=='1')
		{
			ans[d]=1;
			d++;
		}
		else if(in[i]=='2')
		{
			ans[d]=2;
			d++;
		}else if(in[i]=='3')
		{
			ans[d]=3;
			d++;
		}
		else if(in[i]=='4')
		{
			ans[d]=4;
			d++;
		}
		else if(in[i]=='5')
		{
			ans[d]=5;
			d++;
		}
		else if(in[i]=='6')
		{
			ans[d]=6;
			d++;
		}
		else if(in[i]=='7')
		{
			ans[d]=7;
			d++;
		}
		else if(in[i]=='8')
		{
			ans[d]=8;
			d++;
		}
		else if(in[i]=='9')
		{
			ans[d]=9;
			d++;
		}
	}
	sort(ans,ans+d);
	for(long long i=d-1;i>=0;i--)
		cout<<ans[i];
}
