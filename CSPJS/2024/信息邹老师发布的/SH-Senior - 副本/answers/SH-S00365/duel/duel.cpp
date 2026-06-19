#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+100;
int a[MAXN],n,sum[MAXN],cnt[MAXN],maxc;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),cnt[a[i]]++,maxc=max(maxc,a[i]);
	for(int i=1;i<=maxc;i++){
		sum[i]=cnt[i];
		if(cnt[i]<sum[i-1])sum[i]+=sum[i-1]-cnt[i];
	}
	printf("%d",sum[maxc]);
	return 0;
}
