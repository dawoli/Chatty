#include<bits/stdc++.h>
using namespace std;
int a[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char ch;
	while (cin.get(ch))
	{
		if (isdigit(ch))
		{
			a[ch-'0']++;
		}
	}
	for (int i=9;i>=0;i--)while (a[i]--)cout<<i;
	cout<<endl;
}
