#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000005],n,cnt;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.length();
	for(int i=0;i<n;i++)
	{
		if(s[i]<='9'&&s[i]>='0')
		{
			a[cnt]=s[i]-48;
			cnt++;
		}
	}
	sort(a,a+cnt);
	for(int i=cnt-1;i>=0;i--)
	{
		cout<<a[i];
	}
	return 0;
}
