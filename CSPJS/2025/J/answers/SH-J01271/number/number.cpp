#include <bits/stdc++.h>
#include <cstring>
using namespace std;
string a;
int b[2000000];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	long long num = 1;
	cin >> a;
	for(int i = 0;i < a.length();i++)
	{
		if(a[i] - '0' >= 0 and a[i] - '0' <= 9)
		{
			b[num] = a[i] - '0';
			num++;
		}	
	}
	sort(b+1,b+num);
	for(int i = num - 1;i > 0;i--)
	{
		cout << b[i];
	} 
	return 0;
 } 
