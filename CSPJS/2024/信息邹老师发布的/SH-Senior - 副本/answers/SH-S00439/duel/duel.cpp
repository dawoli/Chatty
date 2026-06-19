#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MaxN=100010;
ll n,m;
ll a[MaxN];
ll b[MaxN];
int main(){
	//*/
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	//*/
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++)
		scanf("%lld",a+i);
	sort(a+1,a+n+1);
	a[0]=a[1]-1;
	for(ll i=1;i<=n;i++){
		m+=(a[i]!=a[i-1]);
		b[m]++;
	}
	printf("%lld",*max_element(b+1,b+m+1));
	fclose(stdin);
	fclose(stdout);
	return 0;
}
