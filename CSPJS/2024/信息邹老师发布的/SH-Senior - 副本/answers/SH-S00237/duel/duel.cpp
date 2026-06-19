#include<bits/stdc++.h>
using namespace std;
const int N=100009;
int n,r[N],cnt[N],mx=100000;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	    scanf("%d",&r[i]);
	for(int i=1;i<=n;i++)
	    cnt[r[i]]++;
	int ans=0;
	for(int i=1;i<=mx;i++){
		ans=max(ans-cnt[i],0);
		ans+=cnt[i];
	}
	printf("%d",ans);
	return 0;
}
