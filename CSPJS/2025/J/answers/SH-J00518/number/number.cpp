#include<bits/stdc++.h>
using namespace std;
string a;
int t[15];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> a;
	for(int i = 0;i < a.size();i++)
	{
		int b = int(a[i])-48;
		if(b >= 10) t[11]++;
		else t[b]++;
	}
	for(int i = 9;i >= 0;i--)
	{
		for(int j = 1;j <= t[i];j++)
		{
			cout << i;
		}
	}
	return 0;
} 
