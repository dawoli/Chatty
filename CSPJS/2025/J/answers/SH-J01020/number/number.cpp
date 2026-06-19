#include<bits/stdc++.h>
using namespace std;
using ll=long long;
string s;
int Mp[100];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]<='9'&&s[i]>='0')Mp[s[i]-'0']++;
	}
	for(int i=9;i>=0;)
	{
		if(Mp[i]>0)
		{
			cout<<i;
			Mp[i]--;
		}
		else i--;
	}
	return 0;
} 
