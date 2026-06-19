#include<bits/stdc++.h>
using namespace std;

int n;
int l[5005];
long long f[5005];
long long re[5005];
long long ans;
const long long MOD = 998244353;

long long qpow(long long a,long long b)
{
	long long res = 1;
	while(b>0)
	{
		if(b&1) res = (res * a) % MOD;
		a = (a * a) % MOD;
		b>>=1;
	}
	return res;
}


long long C(int a,int b)
{
	if (a==b) return 1;
	long long res = f[a];
	res = (res * re[b]) % MOD;
	res = (res * re[a-b]) % MOD;
	
	return res;
}


int dfs(int ind,int mx,int sum,int cnt)
{
	if(ind > n)
	{
		if(cnt >= 3 && sum > 2 * mx) ans++;
		return 0;
	}
	
	dfs(ind+1,max(mx,l[ind]),sum+l[ind],cnt+1);
	dfs(ind+1,mx,sum,cnt);
	
	return 0;
}






int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	
	ans = 0;
	
	for(int i=1;i<=n;i++) cin>>l[i];
	
	if(n<=20)
	{
		dfs(1,0,0,0);
	}
	else{
		f[0] = 1;
		for(int i=1;i<=n;i++)
		{
			f[i] = (f[i-1] * i) % MOD;
			re[i] = qpow(f[i],MOD-2);
		}
		for(int i=3;i<=n;i++)
		{
			ans = (ans + C(n,i)) % MOD;
		}
		
	}
	
	
	
	cout<<ans % MOD;
	
	return 0;
}
