#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int a[N] = {};
string s = "";
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int i = 0;
	int len = s.length();
	for (int k=0;k<len;k++)
	{
		if (s[k] >= '0'&&s[k] <= '9')
		{
			i++;
			a[i] = s[k] - '0';
		}
	}
	sort(a+1,a+i+1);
	for (int j=i;j>=1;j--)
	{
		cout<<a[j];
	}
	return 0;
}
