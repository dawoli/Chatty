#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5005],f[5005],ans,p=1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	f[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=a[i];j++){
			ans=(ans+f[j])%mod;
		}
		for(int j=a[n];j>=a[i];j--){
			f[j]=(f[j]+f[j-a[i]])%mod;
		}
		p=2*p%mod;
	}
	printf("%d",((p-ans-1)%mod+mod)%mod);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
