#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt=1,a1,a2;
long long s[200];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n*m;i++)
	{
		cin>>s[i];
	}
	for(long long i=2;i<=n*m;i++)
	{
		if(s[i]>s[1])
		{
			cnt++;
		}
	}
	a1=(cnt-1)/n+1;
	if(a1%2)
	{
		a2=(cnt-1)%n+1;
	}
	else
	{
		a2=n+1-((cnt-1)%n+1);
	}
	cout<<a1<<" "<<a2;
	return 0;
}
