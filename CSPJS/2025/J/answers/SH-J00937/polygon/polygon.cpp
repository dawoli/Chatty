#include <bits/stdc++.h>

using namespace std;

int n;
int a[10000];
const int mod = 998244353;

int f(int i,int sum,int maxn,int x)
{
	if(i == n && x >= 3)
	{
		if(sum > 2*maxn)
		{
			return 1;
		}else{
			return 0;
		}
	}else if(i == n){
		return 0;
	}
	return f(i+1,sum + a[i+1],max(maxn,a[i+1]),x+1) + f(i+1,sum,maxn,x);
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	bool is1 = true;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		if(a[i] != 1)
		{
			is1 = false;
		}
	}
	if(is1)
	{
		long long ans = 1;
		for(int m = 3;m <= n;m++)
		{
			bool ok = false;
			vector<bool> v(m+1,true);
			long long sum = 1;
			for(int i = n;i >= n-m;i--)
			{
				bool lock = true;
				if(!ok)
				{
					for(int j = m;j >= 1;j--)
					{
						bool isok = true;
						if(v[j] && i % j == 0)
						{
							sum *= i / j;
							lock = false;
							sum %= mod;
							break;
						}
						if(v[i])
						{
							isok = false;
						}
						if(j == 1 && isok)
						{
							ok = true;
						}
					}
				}
				if(lock)
				{
					sum *= i;
					sum %= mod;
				}
			}
			ans += sum;
			ans %= mod;
		}
		cout <<ans;
		return 0;
	}
	int ans = 0;
	cout << f(0,0,-1,0);
	return 0;
}
