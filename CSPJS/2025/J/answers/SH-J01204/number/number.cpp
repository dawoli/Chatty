#include <bits/stdc++.h>
using namespace std;
long long a[10];
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	long long l=s.size();
	for(int i=0;i<l;i++)
	{
		if(s[i]=='1')
			a[1]++;
		if(s[i]=='2')
			a[2]++;
		if(s[i]=='3')
			a[3]++;
		if(s[i]=='4')
			a[4]++;
		if(s[i]=='5')
			a[5]++;
		if(s[i]=='6')
			a[6]++;
		if(s[i]=='7')
			a[7]++;
		if(s[i]=='8')
			a[8]++;
		if(s[i]=='9')
			a[9]++;
		if(s[i]=='0')
			a[0]++;
	}
	for(int i=9;i>=0;i--)
	{
		while(a[i]>0)
		{
			a[i]--;
			cout << i;
		}
	}
	return 0;
}
