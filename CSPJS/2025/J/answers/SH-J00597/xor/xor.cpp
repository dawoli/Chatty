#include<bits/stdc++.h>
using namespace std;
int n,k,a,dp,ans,s,f[1100000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k),memset(f,-1,sizeof(f)),f[0]=0;
	for(int w=1;w<=n;w++)
		scanf("%d",&a),s^=a,dp=max(dp,f[s^k]+1),f[s]=max(f[s],dp),ans=max(ans,dp);
	printf("%d",ans);
	return 0;
}
