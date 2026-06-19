#include<bits/stdc++.h>
using namespace std;
int n;
int a[5001];
int sum;
int ma=-1;
int ans;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(long long i=0;i<1<<n;i++)
    {
    	long long t=i;
    	for(int j=1;t>0;j++)
    	{
    		if(t%2==1) 
    		{
    			sum+=a[j];
				ma=max(ma,a[j]);
			}
			t/=2;
		}
		if(sum>ma*2) ans++;
		sum=0;
		ma=-1;
	}
	cout<<(ans-1)%998244353;
	return 0;
}
