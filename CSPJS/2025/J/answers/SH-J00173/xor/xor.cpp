#include<bits/stdc++.h>
using namespace std;
#define int long long
int prexor[500005];
int a[500005];

signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	prexor[1]=a[1];
	for(int i=2;i<=n;i++)
	{
		prexor[i]=(prexor[i-1]^a[i]);
	}
	int lasti=0;
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		int cur=prexor[i]^prexor[lasti];
		if(cur==k){cnt++;lasti=i;}
		else {
			int target=cur^k;
			for(int j=lasti+1;j<i;j++)
			{
				if(prexor[j]^prexor[lasti]==target)
				{
					cnt++;
					lasti=i;
					break;
				}
			}
		}
	}
	cout<<cnt;
	return 0;
}
