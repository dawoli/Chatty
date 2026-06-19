#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N],b[N],n,sum[N],cnt,ans;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),sum[a[i]]++;
	sort(a+1,a+n+1);
	unique(a+1,a+n+1);
	b[1]=sum[a[1]];
    for(int i=2;i<=n;i++){
    	if(a[i]<=a[i-1]) break;
    	ans+=min(b[i-1]-ans,sum[a[i]]);
    	b[i]=b[i-1]+sum[a[i]];
	}
	printf("%d\n",n-ans);
	return 0;
}
