#include<bits/stdc++.h>
using namespace std;
int main() 
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,s1;
	long long len=0;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(isdigit(s[i]))
		{
			s1+=s[i];
			len++;
		}
	}
	for(long long i=0;i<len-1;i++)
	{
		for(long long j=0;j<len-i-1;j++)
		{
			if(s1[j]<s1[j+1])
			{
				swap(s1[j],s1[j+1]);
			}
		}
	}
/*	long long ans=0;
	for(int i=0;i<len;i++)
	{
		ans=ans*10+s1[i];
	}
	cout<<ans<<endl;
*/
	cout<<s1;
	return 0;
}
