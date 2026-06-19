#include <bits/stdc++.h>
using namespace std;
int boom(int n, int cnt)
{
	if(n==2)return cnt*10+1;
	if(n==3)return cnt*10+7;
	if(n==4)return cnt*10+4;
	if(n==5)return cnt*10+2; 
	if(n==6)
	{
		if(cnt > 0)cnt = cnt*10;
		else cnt = 6;
	}
	if(n==7)return cnt*10+8;
	int w = n/7;
	if(n%7!=0)w++;
	if(n%7==0)
	{
		for(int i = 1 ; i <= n % 7 ; i ++)
		{
			cnt=cnt*10+8;
		}
		return cnt;
	}else
	{
		int k = (n-2)/7;
		if(n%7!=0)++k;
		if(k==w)
		{
			return min(boom(n-2, cnt*10+1), min(boom(n-3, cnt*10+7),min(boom(n-4,cnt*10+4),min(boom(n-5,cnt*10+2),min(boom(n-6, cnt*10),boom(n-7,cnt*8))))));
		}else
		{
			k = (n-3) / 7;
			if(n%7!=0)++k;
			if(k==w)
			{
				return min(0x3f3f3f, min(boom(n-3, cnt*10+7),min(boom(n-4,cnt*10+4),min(boom(n-5,cnt*10+2),min(boom(n-6, cnt*10),boom(n-7,cnt*8))))));
			}else
			{
				k = (n-4) / 7;
				if(n % 7 != 0)++k;
				if(k==w)
				{
					return min(0x3f3f3f, min(0x3f3f3f,min(boom(n-4,cnt*10+4),min(boom(n-5,cnt*10+2),min(boom(n-6, cnt*10),boom(n-7,cnt*8))))));
				}else
				{
					k = (n-5) / 7;
					if(n % 7 != 0)++k;
					if(k==w)
					{
						return min(0x3f3f3f, min(0x3f3f3f,min(0x3f3f3f,min(boom(n-5,cnt*10+2),min(boom(n-6, cnt*10),boom(n-7,cnt*8))))));
					}else
					{
						k = (n-6) / 7;
						if(n%7 != 0)++k;
						if(k==w)
						{
							return min(0x3f3f3f, min(0x3f3f3f,min(0x3f3f3f,min(0x3f3f3f,min(boom(n-6, cnt*10),boom(n-7,cnt*8))))));
						}
					}
				}
			}
		}
	}
}
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin >>t;
	while(t--)
	{
		int n;
		cin >> n;
		//个位数进行打表，对>7的数字进行分解拆开 
		if(n<=7)
		{
			if(n==1)cout << -1 << endl;
			if(n==2)cout << 1 << endl;
			if(n==3)cout << 7 << endl;
			if(n==4)cout << 4 << endl;
			if(n==5)cout << 2 << endl;
			if(n==6)cout << 6 << endl;
			if(n==7)cout << 8 << endl;
		}
		int w = n/7;
		if(n%7!=0)w++;//余数，现在求出了最少的位数
		int dp[10001];
		if(n % 7 == 0)
		{
			for(int i =1 ; i <= n / 7 ; i ++)cout<<8;
			cout << endl;
			continue;
		}else
		{
			cout << boom(n, 0) << endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
