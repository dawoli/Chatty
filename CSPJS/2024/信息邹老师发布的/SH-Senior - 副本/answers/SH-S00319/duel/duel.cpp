#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int n,r[N],cnt[N],len,ans;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&r[i]);
	sort(r+1,r+1+n);
	for(int i=1;i<=n;++i){
		if(r[i]!=r[i-1]) len++;
		cnt[len]++;
	}
	for(int i=1;i<=len;++i){
		ans-=cnt[i];
		ans=max(ans,0);
		ans+=cnt[i];
	}
	printf("%d",ans);
	return 0;
}
