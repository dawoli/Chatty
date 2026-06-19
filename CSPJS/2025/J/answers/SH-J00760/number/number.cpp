#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int a[1000005];
	int num=0;
	cin>>s;
	for(int i=0;i<s.length();i++)
	{
		if('0'<=s[i]&&s[i]<='9')
		{
			int tem=s[i]-'0';
			a[++num]=tem;
		}
	}
	sort(a+1,a+1+num);
	for(int i=num;i>=1;i--) cout<<a[i];
	return 0;
}
