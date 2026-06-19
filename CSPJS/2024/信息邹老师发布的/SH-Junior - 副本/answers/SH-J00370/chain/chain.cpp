#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll t;
ll s[2009][2009],l[2009];
int main(){
    freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	scanf("%d",&t);
	for(int asdasd=1;asdasd<=t;asdasd++){
        ll n,k,q;
        scanf("%lld %lld %lld",&n,&k,&q);
        for(int i=1;i<=n;i++) {
            scanf("%lld",&l[i]);
            for(int j=1;j<=l[i];j++) {
                scanf("%lld",&s[i][j]);
            }
        }
        for(int i=1;i<=q;i++) {
            ll a,b;
            scanf("%lld %lld",&a,&b);
            for(int j=1;j<=n;j++) {
                ll last1=-2141473647;
                for(int uk=1;uk<=l[j];uk++) {
                    if(s[j][uk]==1) last1=uk;
                    if(s[j][uk]==b&&uk-last1<k){
                        printf("1\n");
                        goto nothing;
                    }
                }
            }
            printf("0\n");
            nothing:
                if(0) ;
        }
	}
	return 0;
}
