#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	long long a[5005]={0},cnt[5005]={0},ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]<a[i-1]&&i>1)swap(a[i],a[i-1]);
	}
	for(int i=1;i<=n;i++)cnt[i]=cnt[i-1]+a[i];
	if(n==3){
		if(a[3]*2<a[1]+a[2])ans++;
		if(a[1]*2<a[3]+a[2])ans++;
		if(a[2]*2<a[1]+a[3])ans++;
		printf("%lld\n",ans);
	}
	else{
		
		for(int i=n;i>3;i--){
			if(a[i]>cnt[i]/2+cnt[i]%2)continue;
			else{
				int p=1,q;
				q=i-3;
				while(p!=q){
					int k=(p+q)/2;
					if((cnt[i]-cnt[k])/2+(cnt[i]-cnt[k])%2>a[i])p=k+1;
					else if((cnt[i]-cnt[k])/2+(cnt[i]-cnt[k])%2<=a[i])q=k;
				}
				ans=(ans+pow(2,p));
				if(ans>998244353)ans-=998244353;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
