#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,check=0,ans=0;
	cin>>n>>m;
	int r;
	int a[n*m];
	for(int i=0;i<n*m;i++)
	{
		cin>>a[i];
	}
	r=a[0];
	sort(a,a+(n*m));
	for(int i=0;i<n*m;i++)
	{
		if(r==a[i])
		{
			check=n*m-i;
		}
	}
	int b=check;
	while(b>=n)
	{
		b-=n;
		ans++;
	}
	ans += 1;
	if(check>n)
	{
		if(ans%2==0)
		{
			check=check-(n*(ans-1))+n-1;
			
			cout<<ans<<' '<<check;
		}
		else
		{
			check=check-(n*(ans-1));
			cout<<ans<<' '<<check;
		}
	}
	else
	{
		cout<<1<<' '<<check;
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
