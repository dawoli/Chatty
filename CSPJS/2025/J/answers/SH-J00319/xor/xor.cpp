#include<bits/stdc++.h>
using namespace std;
int n,k,a[500001],xsum[500001],f[500001];
int decide(int l,int r){
	if((xsum[l-1]^xsum[r])==k) return 1;
	else return 0;
}signed main(void){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) xsum[i]=(xsum[i-1]^a[i]);
	if(a[1]==k) f[1]++;
	for(int i=2;i<=n;i++){
		for(int j=0;j<i;j++){
			f[i]=max(f[i],f[j]+decide(j+1,i));
//			if(decide(j+1,i)) cout<<j+1<<" "<<i<<endl;
		}
	}printf("%d\n",f[n]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
