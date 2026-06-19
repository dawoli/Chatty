#include<bits/stdc++.h>
using namespace std;
string s = "";
int flag = 0;
int m[15];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	memset(m,sizeof(m),0);
	long long n = 1000007;
	for(long long i = 0;i < n;i++)
	{
		if(s[i] == '0')
		{
			m[0]++;
		}
		else if(s[i] == '1')
		{
			m[1]++;
		}
		else if(s[i] == '2')
		{
			m[2]++;
		}
		else if(s[i] == '3')
		{
			m[3]++;
		}
		else if(s[i] == '4')
		{
			m[4]++;
		}
		else if(s[i] == '5')
		{
			m[5]++;
		}
		else if(s[i] == '6')
		{
			m[6]++;
		}
		else if(s[i] == '7')
		{
			m[7]++;
		}
		else if(s[i] == '8')
		{
			m[8]++;
		}
		else if(s[i] == '9')
		{
			m[9]++;
		}
		if(int(s[i]) == 0)
		{
			break;
		}
	}
	for(int i = 9;i >= 0;i--)
	{
		for(int j = 0;j < m[i];j++)
		{
			cout << i;
		}
	}
	return 0;
}
