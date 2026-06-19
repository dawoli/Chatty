#include<iostream>
#include<algorithm>
using namespace std;


int f[5005][5005];
int sum[5005];
int n;
int a[5005];
int pow2[5005];

int dp(int x,int y)
{
	if(f[x][y]>0)return f[x][y];
	if(y<=0)return pow2[x];
	if(x==0)
	{
		if(y>0)return 0;
		return 1;
	}
	if(sum[x]<y)return 0;
	if(sum[x]==y)return 1;
	f[x][y]=(dp(x-1,y-a[x])+dp(x-1,y))%998244353;
	//cout<<x<<' '<<y<<' '<<f[x][y]<<endl;
	return f[x][y];
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	pow2[0]=1;
	for(int i=1;i<=5000;i++)
	{
		pow2[i]=(pow2[i-1]*2)%998244353;
	}
	sum[0]=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
	}
	int ans=0;
	for(int i=n;i>=3;i--)
	{
		//cout<<i<<' '<<2*a[i]+1<<endl;
		ans+=dp(i-1,a[i]+1);
		ans%=998244353;
	}
	ans%=998244353;
	cout<<ans;
	return 0;
 } 
