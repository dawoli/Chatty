#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int l=s.length();
	for(int k=9;k>=0;k--)
	{
		for(int i=0;i<l;i++)
		{
			if(s[i]-'0'==k)cout<<s[i];
		}
	}
	
	return 0;
}
