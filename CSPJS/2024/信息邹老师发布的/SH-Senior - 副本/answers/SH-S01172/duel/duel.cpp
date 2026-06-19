#include <bits/stdc++.h>
using namespace std;


long long n,a[100250],f[100250],to[100250],t,_inmax=-1e9,_inmin=1e9,l,r,ans;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout); 
	scanf("%lld",&n);
	ans=n;
	for(long long i=1;i<=n;++i){
		scanf("%lld",&a[i]);
		f[a[i]]++;
		to[a[i]]=f[a[i]];
		_inmax=max(_inmax,a[i]);
		_inmin=min(_inmin,a[i]);
	}
	sort(a+1,a+n+1);
	for(long long i=0;i<=_inmax;i++){
		f[i]=f[i-1]+f[i];
	}
	for(long long i=0;i<=n;++i){
		
		if(abs(f[_inmax]-f[a[i]])>=to[a[i]]){
			if(a[i]==a[i-1]){
				continue;
			}
			ans-=to[a[i]];
		} else {
			ans-=f[_inmax]-f[a[i]];
			break;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
