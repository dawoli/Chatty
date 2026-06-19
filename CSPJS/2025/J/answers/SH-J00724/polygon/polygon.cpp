#include <bits/stdc++.h>
#define lol long long 
#define mod 998244353
using namespace std;

int n;
int a[5005];

lol pre[5005];

int maxn;
lol sum;

lol ans;

bool flag = 1; 

bool cmp(int x,int y)
{
	return x > y;
}




int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	cin>>n;
	
	for(int i = 1;i <= n;i ++)
	{
		cin>>a[i];
		maxn = max(maxn,a[i]);
		sum += a[i];
		pre[i] = pre[i - 1] + a[i];
		if(a[i] != 1) flag = 0;
	}
	
	//sort(a + 1, a + n + 1,cmp);
	
	if(n < 3)
	{
		cout<<0<<'\n';
		return 0;
	}
	
	if(n == 3)
	{
		if(sum > 2 * maxn)
		{
			cout<<1<<'\n';
			return 0;
		}
		cout<<0<<'\n';
		return 0;
	}
	
//	if(flag)
//	{
//		if(n <= 500)
//		{
//			
//		}
//	}
//	
	
	//if(n > 500)
	{
		cout<<0<<'\n';
		return 0;
	}
	
	
	
	
	return 0;
}
