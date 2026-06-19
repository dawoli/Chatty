#include <bits/stdc++.h>
using namespace std;

bool cmp(int a,int b)
{
	return a > b;
}

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int num[1000010] = {0};
	int cnt = 0;
	for (int i = 0;i < s.size();i++)
	{
		if (s[i] == '0')
		{
			num[cnt] = 0;
			cnt++;
		}
		if (s[i] == '1')
	    {
			num[cnt] = 1;
			cnt++;
		}
		if (s[i] == '2')
		{
			num[cnt] = 2;
			cnt++;
		}
		if (s[i] == '3')
		{
			num[cnt] = 3;
			cnt++;
		}
		if (s[i] == '4')
		{
			num[cnt] = 4;
			cnt++;
		}
		if (s[i] == '5')
		{
			num[cnt] = 5;
			cnt++;
		}	
		if (s[i] == '6')
		{
			num[cnt] = 6;
			cnt++;
		}
		if (s[i] == '7')
		{
			num[cnt] = 7;
			cnt++;
		}
		if (s[i] == '8')
		{
			num[cnt] = 8;
			cnt++;
		}
		if (s[i] == '9')
		{
			num[cnt] = 9;
			cnt++;
		}
    } 
    sort(num,num + cnt + 1,cmp);
    for (int i = 0;i < cnt;i++)
    	cout << num[i];
    	
    return 0;
}
