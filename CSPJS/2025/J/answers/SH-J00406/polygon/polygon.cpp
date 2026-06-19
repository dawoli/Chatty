#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[5005];
ll cnt=0;
const int p=998244353;
int n;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==3){
		ll sum=a[1]+a[2]+a[3];
		ll mx=max(a[1],max(a[2],a[3]));
		if(sum>2*mx){
			cnt++;
			cnt%=p;
		}
	}
	else{
		for(int i=1;i<=n;i++)
		{
			cnt*=i;
			cnt%=p;
		}
    }
	cout<<cnt%p;
	return 0;
}
