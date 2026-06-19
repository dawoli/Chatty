#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],n=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++)
		if(s[i]>='0'&&s[i]<='9')
		{
			n++;
			a[n]=s[i]-'0';
		}
	sort(a+1,a+1+n);
	for(int i=n;i>=1;i--)
		printf("%d",a[i]);
	return 0;
}
