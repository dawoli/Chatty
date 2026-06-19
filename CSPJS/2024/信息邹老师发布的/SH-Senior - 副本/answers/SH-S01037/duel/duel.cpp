#include<bits/stdc++.h>
#define maxn 100010
using namespace std;
int n,cnt[maxn];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for(int i=1,r;i<=n;i++){
		scanf("%d",&r);
		cnt[r]++;
	}
	int lst=0,ans=0;
	for(int i=1,tmp;i<=1e5;i++){
		if(!cnt[i]) continue;
		tmp=min(lst,cnt[i]);
		lst+=cnt[i]-tmp, ans+=tmp;
	}
	printf("%d\n",n-ans);
	return 0;
}

