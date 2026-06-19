#include<iostream>
using namespace std;

int ans,a[500010],f[500010];

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(int(a[i]|a[j])==k)
			{
				ans++;
				i=j;
			}
		}
	}
    cout<<ans<<endl;
    return 0;
}
