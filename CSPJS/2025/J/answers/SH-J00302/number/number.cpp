#include <bits/stdc++.h>
using namespace std;
int a[1000100];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.ans","w",stdout);
	string s;
	cin>>s;
	int cur=1;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[cur]=s[i]-'0';
			cur++;
		}
	}
	sort(a+1,a+cur);
	for(int i=cur-1;i>=1;i--)
	{
		cout<<a[i];
	}
}
