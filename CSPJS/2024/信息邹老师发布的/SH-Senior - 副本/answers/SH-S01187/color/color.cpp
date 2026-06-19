#include<bits/stdc++.h>
#define int long long
#define maxn 123456
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
int t,n,a[maxn],ans,sum;
bool clri,clrj;
signed main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	while(t--){
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
		ans=-inf;
		for(int s=0;s<(1<<n);s++){
			sum=0;
			for(int i=n;i>=1;i--){
				clri=s&(1<<(i-1));
				for(int j=i-1;j>=1;j--){
					clrj=s&(1<<(j-1));
					if(clri==clrj){
						if(a[i]==a[j])sum+=a[i];
						break;
					}
				}
			}
			ans=max(ans,sum);
		}
		printf("%lld\n",ans);
	}
	return 0;
}

// code written by luogu user #951212
