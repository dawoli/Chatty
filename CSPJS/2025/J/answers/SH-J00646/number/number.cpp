#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
string s;
int a[10],cnt;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]>='0'&&s[i]<='9') a[s[i]-'0']++;
	bool f=0;
	for(int i=9;i>=0;i--)
		if(i!=0&&a[i]>0)
		{
			f=1;
			break;
		}
	if(!f)
	{
		cout<<0;
		return 0;
	}
	for(int i=9;i>=0;i--)
		for(int j=1;j<=a[i];j++) cout<<i;
	return 0;
}
