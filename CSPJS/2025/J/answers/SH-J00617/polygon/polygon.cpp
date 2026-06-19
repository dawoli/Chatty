#include<bits/stdc++.h>
using namespace std;
int n;
int a[5010];
long long ans=0;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=2;i<=n;i++){
		for(int j=0;j<=(1<<(i-1))-1;j++){
			int cnt=0;
			for(int k=0;k<i-1;k++){
				if(((j>>k)&1)==1){
					cnt+=a[k+1];
				}
			}
			int ccnt=0;
			int k=j;
			while(k){
				if((k&1)==1)ccnt++;
				k=k>>1;
			}
			if(ccnt>=2&&cnt>a[i]){
				ans++;
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}
