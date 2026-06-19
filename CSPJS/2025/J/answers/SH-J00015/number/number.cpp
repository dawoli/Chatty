#include<bits/stdc++.h>
using namespace std;
int main() 
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	long long s=a.length();
	long long sum[15]={};
	long long f=1;
	for(long long i=0;i<s;i++)
	{
		if(int(a[i]-48)>=0&&int(a[i]-48)<=9)
		{
			sum[int(a[i]-48)]++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=0;j<sum[i];j++)cout<<i;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
