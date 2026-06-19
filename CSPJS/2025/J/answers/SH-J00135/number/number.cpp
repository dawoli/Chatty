#include<bits/stdc++.h>
using namespace std;
int a[1000000]={};
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int cnt=0;
	int f=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>=48&&s[i]<=58)
		{
			a[f]=s[i]-48;
			cnt++;
			f++;
		}
	}
	sort(a,a+cnt+1,cmp);
	if(a[0]==0)
	{
		cout<<0;
	}
	else
	{
		for(int i=0;i<cnt;i++)
		{
			cout<<a[i];
		}
	}
	return 0;
 }
