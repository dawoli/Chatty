#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
#define ll long long
ll n,m,ans=0;
ll a[20],b[20],d[20];
string x;
bool vis[20];
void getp(int steps)
{
	if(steps==n+1)
	{

		for(int i=1;i<=10;i++)
		{
			int c=b[i];
			d[i]=a[c];
			//cout<<d[i]<<" ";
		}			
		//cout<<endl;
		int lu=0,dis=0;
		for(int j=0;j<n;j++)
		{
			if(dis<d[j+1]&&x[j]=='1')lu++;
			else dis++;
		}
		if(lu>=m)ans++;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			b[steps]=i;
			getp(steps+1);
			vis[i]=0;
			b[steps]=0;
		}
	}
	
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>x;
	for(int i=1;i<=n;i++)cin>>a[i];
	getp(1);
	
	cout<<ans%998244353;
	return 0;
}
