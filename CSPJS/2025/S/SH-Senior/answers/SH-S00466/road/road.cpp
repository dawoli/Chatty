#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MaxN=1100010;
ll T,n,m,k,qk,am,ans;
ll a[13][MaxN];
ll c[MaxN];
ll d[MaxN];
ll au[MaxN];
ll av[MaxN];
ll aw[MaxN];
ll ra[MaxN];
ll pe[MaxN];
inline ll readi(){
	char rc;ll rx;
	for(rc=getchar();(rc<'0')||('9'<rc);rc=getchar());
	for(rx=0;('0'<=rc)&&(rc<='9');rc=getchar())
		rx=rx*10+(rc^'0');
	return rx;
}
bool cmp(ll x,ll y){
	return aw[x]<aw[y];
}
inline const ll&fap(const ll&x){
	if(pe[x]==x)
		return x;
	return pe[x]=fap(pe[x]);
}
int main(){
	ll rx,rq=0;
	ll *rya,*ryb;
	ll rza,rzb;
	//*/
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	//*/
	n=readi();m=readi();k=readi();
	for(ll i=1;i<=m;i++){
		au[i]=readi();av[i]=readi();aw[i]=readi();
		ra[i]=i;
	}
	for(ll i=1;i<=k;i++){
		c[i]=readi();
		for(ll j=1;j<=n;j++)
			a[i][j]=readi();
		rya=min_element(a[i]+1,a[i]+n+1);
		rza=*rya;*rya=0x3f3f3f3f3f3f3f3f;
		ryb=min_element(a[i]+1,a[i]+n+1);
		rzb=*ryb;*rya=rza;
		d[i]=c[i]+rza+rzb;
	}
	sort(ra+1,ra+m+1,cmp);
	rx=0;
	for(ll i=1;i<=n;i++)
		pe[i]=i;
	for(ll i,ii=1;(ii<=m)&&(rx<n-1);ii++){
		i=ra[ii];
		if(fap(au[i])!=fap(av[i])){
			rx++;
			pe[fap(av[i])]=fap(au[i]);
			rq=aw[i];
		}
	}
	am=m;qk=0;
	for(ll i=1;i<=k;i++){
		if(d[i]<rq){
			qk++;
//			ans+=c[i];
			for(ll j=1;j<=n;j++){
				am++;
				ra[am]=am;
				au[am]=n+qk;
				av[am]=j;
				aw[am]=a[i][j];
			}
		}
	}
	rx=0;
//	printf("%lld  !!!",qk);
	for(ll i=1;i<=n+qk;i++)
		pe[i]=i;
	sort(ra+1,ra+am+1,cmp);
	for(ll i,ii=1;(ii<=m)&&(rx<n+qk-1);ii++){
		i=ra[ii];
		if(fap(au[i])!=fap(av[i])){
			rx++;
			pe[fap(av[i])]=fap(au[i]);
			ans+=aw[i];
		}
	}
	printf("%lld\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
