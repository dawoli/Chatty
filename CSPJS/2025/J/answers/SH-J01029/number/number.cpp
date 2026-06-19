#include<bits/stdc++.h>
using namespace std;
map<char,long long> s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char x;
	while(cin>>x)
	{
		if(x<='9'&&x>='0')
		{
			s[x]++;
		}
	}
	for(char i='9';i>='0';i--)
	{
		for(int j=1;j<=s[i];j++)
		{
			cout<<i;
		}
	}
	return 0;
}
