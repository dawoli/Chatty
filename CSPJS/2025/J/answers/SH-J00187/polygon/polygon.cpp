#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],ans = 0;
long long f[5005];
long long c(long long x,long long m)
{
	long long shang = 1,xia = 1;
	for(int i = x;i > x - m;i--)
	{
		shang *= i;
		shang %= 998244353; 
	}
	for(int i = 1;i <= m;i++)
	{
		xia *= i;
		xia %= 998244353;
	}
	return shang/xia;
} 
bool check()
{
	long long cnt = 0,maxx = -1,sum = 0;
	for(int i = 1;i <= n;i++)
	{
		if(f[i]) cnt++;
		if(f[i] == 1 && a[i]> maxx) maxx = a[i];
		if(f[i]) sum += a[i];
	}
	//cout<<cnt<<maxx<<sum<<endl;
	if(cnt < 3) return false;
	else if(sum > (maxx * 2)) return true;
	else return false;
}
void dfs(long long num)
{
	if(num > n)
	{
		//cout<<"a"<<endl;
		if(check() == true) 
		{
			ans++;
			//cout<<"b"<<endl;
		}
		ans %= 998244353;
		return;
	}
	f[num] = 1;
	dfs(num + 1);
	f[num] = 0;
	dfs(num + 1);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++) cin>>a[i];
	bool flag = true;
	for(int i = 1;i <= n;i++)
	{
		if(a[i] != 1) flag = false; 
	}
	if(flag) 
	{
		for(int i = 3;i <= n;i++) 
		{
			ans += c(n,i);
			ans %= 998244353;
		}
	}
	else
	{
		dfs(1);
	}
	cout<<ans<<endl;
	return 0;
}
