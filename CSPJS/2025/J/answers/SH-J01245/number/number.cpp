#include<bits/stdc++.h>
using namespace std;
string s;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int a[s.size()+5]={0};
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>'0' && s[i]<='9')
		{
			a[i]=s[i]-'0';
		}
		else if(s[i]=='0')
		{
			a[i]=10;
		}
	}
	sort(a,a+s.size(),cmp);
	int zz=0,zerocnt=0;
	while(1)
	{
		if(a[zz]==0)
		{
			break;
		}
		else if(a[zz]==10)
		{
			zerocnt++;
		}
		else
		{
			cout<<a[zz];
		}
		zz++;
	}
	for(int i=0;i<zerocnt;i++)
	{
		cout<<0; 
	}
	return 0;
}
