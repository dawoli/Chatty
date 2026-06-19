#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int c=0;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			c++;
			a[c]=s[i]-'0';	
		}
	}
	sort(a+1,a+c+1);
	for(int i=c;i>=1;i--)
	{
		cout<<a[i];
	}
	return 0;
}
