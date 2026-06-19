#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
int a[N],cnt=0,fl=0;
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	cnt=0;
	for(int i=0;i<s.size();i++)
	{
		char c=s[i];
		if(c>='0'&&c<='9')
		{
			cnt++;
			a[cnt]=(int)c-'0';
		}
	}
	sort(a+1,a+cnt+1);
	for(int i=1;i<=cnt;i++)
	{
		if(a[i]!=0)
		{
			fl=1;
		}
	}
	if(!fl)
	{
		cout<<0<<endl;
		return 0;
	}
	for(int i=cnt;i>=1;i--)
	{
		cout<<a[i];
	}
	return 0;
}
