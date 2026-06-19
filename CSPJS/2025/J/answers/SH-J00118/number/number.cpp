#include<bits/stdc++.h>
using namespace std;
long long num[20];
string s;
long long cnt=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(long long i=0;i<s.size();i++)
	{
		if('0'<=s[i]&&s[i]<='9')
		{
			num[s[i]-'0']++;
			cnt++;
		}
	}
	if(cnt-s[0]==0)
	{
		cout<<0;
		return 0;
	}
	for(long long i=9;i>=0;i--)
	{
		for(long long j=1;j<=num[i];j++)
		{
			cout<<i;
		}
	}
	return 0;
} 
