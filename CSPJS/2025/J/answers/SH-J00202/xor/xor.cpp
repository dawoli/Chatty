#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+5;
int a[N],f[N],sum[N],n,k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		f[i]=f[i-1];
		sum[i]=sum[i-1]^a[i];
		for(int j=i;j;j--){
			if((sum[i]^sum[j-1])==k){
				f[i]=max(f[i],f[j-1]+1);
				break;
			}
		}
	}
	cout<<f[n];
	return 0;
}
