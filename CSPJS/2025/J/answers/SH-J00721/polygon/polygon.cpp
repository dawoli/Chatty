#include<bits/stdc++.h>
using namespace std;
const int N=5e3+9;
const long long M=998244353;
int a[N],n;
long long f[N],p[N],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);p[0]=1ll;
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		p[i]=(p[i-1]<<1)%M; 
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		ans+=f[a[i]];
		ans%=M;
		for(int j=5000;j>=0;j--){
			if(j>=a[i])f[j]+=f[j-a[i]];
			else f[j]+=p[i-1];
			f[j]%=M;
		}
	}
	printf("%d",ans);
	return 0;
}
