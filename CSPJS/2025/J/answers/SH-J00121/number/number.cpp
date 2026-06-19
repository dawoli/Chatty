#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+5;
int a[N];

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	if(s.length() == 1)
	{
		cout<<s;
		return 0;
	}
	int len = s.length();
	string new_s = "";
	for(int i=0;i<len;i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			new_s += s[i];
		}
	}
	int len2 = new_s.length();
	for(int i=0;i<len2;i++)
	{
		a[i] = new_s[i]-'0';
	}
	sort(a,a+len2);
	for(int i=len2-1;i>=0;i--)
	{
		cout<<a[i];
	}
	return 0;
}


/*

*/
