#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s;
char a[2000000];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int p=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[p]=s[i];
			p++;
		}
	}
	sort(a,a+p);
	for(int i=p-1;i>=0;i--)
	{
		cout<<a[i];
	}
	return 0;
}

