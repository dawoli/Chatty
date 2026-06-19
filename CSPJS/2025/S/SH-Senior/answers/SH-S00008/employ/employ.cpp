#include <bits/stdc++.h>

using namespace std;

int n,m,cnt;
int c[1010];
int MOD = 998244353;

bool cmp(int a, int b)
{
	return a < b;
 } 

int pai(int a)
{
	int ans = 1;
	for(int i=1; i<=a; i++)
	{
		ans*=i;
		ans%=MOD;
	}
	return ans;
}

int main()
{
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin >> n >> m;
	string s;
	cin >> s;
	cnt = n;
	
	for(int i = 0; i < n; i++)
	{
		cin >> c[i];
		if(c[i]==0) cnt-=1;
	}
	
	if(cnt = 0)
	{
		cout << 0;
		return 0;
	}
	
	if(m == 1)
	{
		int ans=1;
		ans = cnt * pai(n-1);
		cout << ans;
		return 0;
	}
	
	if(m == n)
	{
		sort(c,c+n,cmp);
		for(int i=0; i<n; i++)
		{
			m++;
		}
	} 
	
	
	
	return 0;
}
