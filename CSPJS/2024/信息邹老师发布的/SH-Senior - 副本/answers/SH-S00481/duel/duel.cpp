#include<bits/stdc++.h>
#define Hatsune return
#define Miku 0
using namespace std;

typedef long long ll;
const int N=1e5+10;

ll n,a[N],stk[N],tt;

int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	ll pre=0;
	for(ll i=1;i<=n;i++)
	{
		if(tt&&stk[tt]<a[i]) tt--;
		if(a[i]!=a[i+1])
		{
			for(ll j=i;a[j]==a[i];j--)
			{
				stk[++tt]=a[i];
			}
		}
	}
	cout<<tt;
	Hatsune Miku;
}
