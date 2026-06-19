#include <bits/stdc++.h>
using namespace std;
char a[1000005];
int pos;
string s,s1;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[pos++]=s[i];
		}
	}
	sort(a,a+pos);
	
	for(int i=pos-1;i>=0;i--)
	{
		s1+=a[i];
	}
	cout<<s1;
	return 0;
}
