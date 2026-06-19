#include<bits/stdc++.h>
using namespace std;

string s;
long long n[100];

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long len=s.size();
	for(long long i=0;i<len;i++)
	{
		if(48<=s[i] && s[i]<=57)
			n[s[i]-48]++;
	}
	for(long long i=9;i>=0;i--)
	{
		for(long long j=1;j<=n[i];j++)
			cout<<i;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
