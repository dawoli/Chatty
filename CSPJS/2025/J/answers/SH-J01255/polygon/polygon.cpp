#include<bits/stdc++.h>
using namespace std;
int a[5005];
short jw[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,x;
	scanf("%d",&n,&x);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-1;j++){
			if(a[j]>a[j+1]){
				swap(a[j],a[j+1]);
			}
		}
	}
	long long sum=0;int mxi=0;
	while(true){
		int bs=0;
		for(int i=1;i<=n;i++){
			if(jw[i]>=2){
				jw[i]=0;
				jw[i+1]++;
			}
			if(jw[i]>0){
				bs++;
				if(i>mxi){
					mxi=i;
				}
			}
		}
		if(jw[n+1]>=1){
			break;
		}
		int xum=0;
		for(int i=1;i<=mxi;i++){
			if(jw[i]>=1){
				xum+=a[i];
			}
		}
		if(xum>2*a[mxi]&&bs>=3){
			sum++;
		}
		jw[1]++;
	}
	printf("%lld",sum%998244353);
}
