#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
ll T,a[N],c[N],n,ma,ans,t[20];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	t[0]=1;
	for(int i=1;i<=15;i++) t[i]=(t[i-1]<<1);
	scanf("%d",&T);

	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		if(n<=15){
			int m=33000;
			ma=0;ans=0;
			int lx=0,ly=0;
			for(int i=0;i<=t[n];i++){
				ans=0;
				lx=0,ly=0;
				for(int j=n-1;j>=0;j--){
					if((i>>j)&1){
						if(lx&&a[lx]==a[n-j]){
							ans+=a[lx];
						}
						lx=n-j;
					}
					else{
						if(ly&&a[ly]==a[n-j]){
							ans+=a[ly];
						}
						ly=n-j;
					}
				}
			//	cout<<ans<<" "<<ma<<"      "<<i<<endl;
				ma=max(ma,ans);
				
			}
			printf("%lld\n",ma);
		}
	} 
	return 0;
}

