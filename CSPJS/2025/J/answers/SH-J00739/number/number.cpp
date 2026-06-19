#include <bits/stdc++.h>
using namespace std;
int b[1000005];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	int c = 0;
	cin >> a;
	for(int i = 0;i<a.length();i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			b[c] = a[i]-'0';
			c++;
		}
	}
	sort(b,b+c,cmp);
	for(int i = 0;i<c;i++)
	{
		cout << b[i];
	}
	cout << endl;
	return 0;
}
