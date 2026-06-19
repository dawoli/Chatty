#include <bits/stdc++.h>
using namespace std;

int n,k;
const int N=5e5+7;
int a[N],sum[N];
bool vis[N];
long long ans;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		vis[i]=false;
		sum[i]=sum[i-1]^a[i];
	}
	for(int len=1;len<=n;len++)
	{
		for(int i=1;i+len-1<=n;i++)
		{
			int j=i+len-1,temp=0;
			bool flag=false;
			for(int k=i;k<=j;k++)
			{
				if(vis[k])
				{
					flag=true;
					break;
				}
				temp^=a[k];
			}
			cout<<len<<" "<<i<<" "<<j<<" "<<temp<<endl;
			if(temp==k&&flag==false)
			{
				for(int k=i;k<=j;k++)
				{
					vis[k]=true;
				}
				ans++;
			}
		}
	}
	cout<<ans<"\n";
	return 0;
}
