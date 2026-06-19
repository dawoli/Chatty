#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,wz,h=1,r=1,x,y,sl;
pair<ll,ll> p[100005];
bool cmp(pair<ll,ll> x,pair<ll,ll> y){return x>y;}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	sl=n*m;
	for(int i=1;i<=sl;i++) scanf("%lld",&p[i].first),p[i].second=i;
	sort(p+1,p+sl+1,cmp);
	for(int i=1;i<=sl;i++)
		if(p[i].second==1) wz=i;
	x=(wz-1)/(n*2),y=(wz-1)%(n*2)+1;
	if(y<=n) cout<<x*2+1<<' '<<y<<endl;
	else cout<<x*2+2<<' '<<n-(y-n)+1<<endl;
	return 0;
}
