#include<bits/stdc++.h>
using namespace std;
string s;
int t1 = 0,t2 = 0,oot;
int big(int a[])
{
	int ot = -2147483647,ii = 0;
	for(int i = 0;i < t1;i++)
	{
		if(a[i] > ot && a[i] != -1)
		{
			ot = a[i];
			ii = i;
		}
	}
	return ii;
}
int main()
{
	freopen("number.in",  "r", stdin);
	freopen("number.out",  "w", stdout);
	cin>>s;
	int a[s.length()+1];
	for(int i = 0;i < s.length();i++)
	{
		if(s[i] >= '0' && s[i] <= '9')
		{
			a[t1] = s[i] - 48;
			//cout<<a[t1]<<endl;
			t1++;
		}
	}
	int mo = -2147483647;
	t2 = t1;
	oot = 0;
	int bb = 1;
	for(int i = 0;i < t1;i++)
	{
		bb = 1;
		for(int j = 0;j < t2 - 1;j++)
		{
			bb *= 10;
		}
		oot += a[big(a)] * bb;
		//cout<<big(a)<<' '<<a[big(a)]<<' '<<oot<<' '<<t2<<endl;
		a[big(a)] = -1;
		t2 -= 1;
	}
	cout<<oot;
	return 0;
}
