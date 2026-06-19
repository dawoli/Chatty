#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int mod=998244353;

int n;
const int N=5010;
int a[N];
int k[N];
ll f[N*N];
int m=0;
ll ans=0;

void dfs(int x,int num)
{
	if(x==n+1)
	{
		if(num<3) return ;
		int sum=0;
		for(int i=1;i<num;i++)
		{
			sum+=k[i];
		}
		if(sum>k[num]) ans++;
		return ;
	}
	k[num+1]=a[x];
	dfs(x+1,num+1);
	k[num+1]=0;
	dfs(x+1,num);
}

ll quick_pow(ll a,int b)
{
	ll res=1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int mx=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
		m+=a[i];
	}
	sort(a+1,a+n+1);
	if(n<=20)
	{
		dfs(1,0);
		cout<<ans;
	}
	else if(mx==1){
		ll ans=quick_pow(2,n);
		ans=(ans-n-1-n*(n-1)/2+mod)%mod;
		cout<<ans;
	}
	else{
		f[0]=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=a[i]+1;j<=m;j++) ans=(ans+f[j])%mod;
			for(int j=m;j>=a[i];j--)
			{
				f[j]=(f[j]+f[j-a[i]])%mod;
			}
		}
		cout<<ans;
	}
	return 0;
}
