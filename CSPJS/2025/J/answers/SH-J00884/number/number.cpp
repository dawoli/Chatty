#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int a[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int cur=0;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]<='9'&&s[i]>='0')
		{
			a[++cur]=s[i]-'0';
		}
	}
	sort(a+1,a+cur+1);
	for(int i=cur;i>=1;i--)
	{
		cout << a[i];
	}
	return 0;
}
