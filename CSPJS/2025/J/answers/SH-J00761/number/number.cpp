#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int a[1000005],b[1000005];
int tot=0;
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
	for (int i=0;i<s.length();i++)
	{
		if (isdigit(s[i]))
		{
			b[++tot]=s[i]-'0';
		}
	}
	sort(b+1,b+tot+1,cmp);
	for (int i=1;i<=tot;i++)
	{
		cout<<b[i];
	}
	return 0;
}
