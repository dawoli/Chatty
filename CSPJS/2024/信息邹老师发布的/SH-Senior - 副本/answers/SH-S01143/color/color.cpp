#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=20;
ll n,a[N],b[N],ptn,t;
ll maxn,sum;
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		for(int i=1;i<=n;++i)
			scanf("%lld",&a[i]);
		ptn=pow(2,n)-1;
		cout<<ptn<<endl;
		maxn=0;
		for(ll i=0;i<=ptn;++i){
			sum=0;
			int c=i;
			for(ll j=n;j>=1;--j){
				b[j]=c%2;
				c/=2;
			}
			for(ll j=1;j<=n;++j){
				for(ll k=j-1;k>=1;--k)			
					if(b[k]==b[j]){
						if(a[k]==a[j])
							sum+=a[j];
						break;
					}
			}
			maxn=max(maxn,sum);
		}
		printf("%lld\n",maxn);
	}
	return 0;
}
