#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n,m,nn,u,ans,mm;
bool ok;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	nn=m*n;
	cin>>u;
	ans=1;
	for(int i=2,x;i<=nn;i++)
	{
		cin>>x;
		if(x>u)
		{
			ans++;
		}
	}
	ok=ans%n;
	if(!ok)
	{
		mm=n;
	}
	else
	{
		mm=ans%n;
	}
	if(!((ans/n+ok)%2))
	{
		mm=n-mm+1;
	}
//	cout<<ans<<endl;
	cout<<ans/n+ok<<' '<<mm<<endl;
	return 0;
}
