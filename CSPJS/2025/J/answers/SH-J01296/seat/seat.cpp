#include<bits/stdc++.h>
using namespace std;

long long n,m,aa1,aa2=1,temp,ans;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>aa1;
	for(long long i=2;i<=n*m;i++)
	{
		cin>>temp;
		if(temp>aa1)
			aa2++;
	}
	ans=(aa2/(2*n))*2;
	aa2-=ans*n;
	if(aa2==0)
	{
		cout<<ans<<" "<<"1";
		return 0;
	}
	if(aa2<=n)
	{
		cout<<ans+1<<" "<<aa2;
		return 0;
	}
	if(aa2>n)
	{
		cout<<ans+2<<" "<<(2*n-aa2+1);
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
