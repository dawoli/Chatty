#include <bits/stdc++.h>
using namespace std;

long long ans,k,n,a[200250],p[200250],t,ansc,_max=-1e9,C[200250];//ºì=0   À¶=1 
long long dfs(long long depth,long long c){
	if(depth==n){
		_max=max(_max,c);
		k++;
		if(k==ansc){
			printf("%lld\n",c);
			return 0;
		}
		return 0;
	}
	for(int i=0;i<2;i++){
		long long s=c;
		p[depth]=i;
		for(long long j=depth-1;j>=0;j--){
			if(p[depth]==p[j]&&a[depth]==a[j]){
				//cout<<"depth="<<depth<<" j="<<j<<" p[j]="<<p[j]<<endl;
				s+=a[depth];
				break;
			}
		}
		C[depth]=s;
		dfs(depth+1,s);
	}
	return 0;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout); 
	scanf("%lld",&t);
	while(t--){
		_max=-1e9;
		k=0;
    	scanf("%lld",&n);
 	    for(long long i=0;i<n;i++){
    		scanf("%lld",&a[i]);
    	}
    	ansc=pow(2,n);
    	dfs(0,0);
	}
	return 0;
}
