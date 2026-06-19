#include <iostream>
#include <fstream>
#define EIN fin
#define EOUT fout
using namespace std;
ifstream fin("color.in");
ofstream fout("color.out");
long long ll[200010],t,n,a,ans;
void funcd(long long nu,long long re,long long bl,long long k)
{
	if(nu==n+1)
	{
		ans=max(ans,k);
		return;
	}
	if(ll[nu]==ll[re])
		funcd(nu+1,nu,bl,k+ll[nu]);
	else
		funcd(nu+1,nu,bl,k);
	if(ll[nu]==ll[bl])
		funcd(nu+1,re,nu,k+ll[nu]);
	else
		funcd(nu+1,re,nu,k);
}
int main()
{
	ios::sync_with_stdio(0);
	EIN>>t;
	while(t--)
	{
		ans=0;
		EIN>>n;
		for(a=1;a<=n;a++)
			EIN>>ll[a];
		funcd(1,0,0,0);
		EOUT<<ans<<'\n';
	}
	fin.close();
	fout.close();
	return 0;
}
