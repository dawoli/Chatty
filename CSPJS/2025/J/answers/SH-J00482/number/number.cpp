#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int j=1;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[j]=s[i]-'1'+1;
			j++;
		}
	}
	sort(a+1,a+j);
	for(int i=j-1;i>=1;i--)
	{
		cout<<a[i];
	}
	return 0;
}
