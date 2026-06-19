#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],len;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[len]=s[i]-'0';
			len++;
		}
	}
	sort(a,a+len);
	for(int i=len-1;i>=0;i--)
	{
		cout<<a[i];
	}
	cout<<endl;
	return 0;
}
