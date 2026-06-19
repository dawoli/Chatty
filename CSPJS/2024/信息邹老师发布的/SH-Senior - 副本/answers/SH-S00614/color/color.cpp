#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,a[200010],o,b,r,sum,ans;
bool c[200010];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		ans=0;
		scanf("%lld",&n);
		for(ll i=1;i<=n;i++)scanf("%lld",&a[i]);
		for(ll i=0;i<pow(2,n);i++){
			sum=b=r=0,o=i;
			for(ll j=1;j<=n;j++){
				c[j]=o%2,o/=2;
				if(c[j]){
					if(b>0&&a[j]==a[b])sum+=a[j];
					b=j;
				}else{
					if(r>0&&a[j]==a[r])sum+=a[j];
					r=j;
				}
			}
			ans=max(ans,sum);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
