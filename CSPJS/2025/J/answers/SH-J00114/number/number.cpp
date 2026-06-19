#include<bits/stdc++.h>
using namespace std;
int mp[20];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			mp[s[i]-'0']++;
		}
	}
	bool flag=0;
	for(int i=9;i>=0;i--)
	{
		for(int j=mp[i];j>0;j--)
		{
			if(flag==0)
			{
				if(i>=1)
				{
					flag=1;
				}
				else
				{
					cout<<0;
					return 0;
				}
			}
			printf("%d",i);
		}
	}
	return 0;
} 
