#include <bits/stdc++.h>
using namespace std;

int a[1000006];

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
	int len=s.size(),cnt=0;
	for(int i = 0;i<len;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[cnt++]=s[i]-'0';
		 } 
	}
	sort(a,a+cnt,cmp);
	for(int i = 0;i<cnt;i++)
	{
		cout << a[i];
	}
	return 0;
}

