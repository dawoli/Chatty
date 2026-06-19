#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	cin>>s;
	for(int i = 9;i>=0;i--)
	{
		for(int j = 0;j < s.length();j++)
		{
			if(s[j]-'0' == i)
			{
				cout<<i;
			}
		}
	}	
	return 0;
}
