#include<bits/stdc++.h>
using namespace std;
int cnt[100003];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n,up=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int tmp;
		scanf("%d",&tmp);
		up=max(up,tmp);
		cnt[tmp]++;
	}
	int ans=0;
	for(int i=1;i<=up;i++){
		ans-=cnt[i];
		ans=max(ans,0);
		ans+=cnt[i];
	}
	printf("%d",ans);
	return 0;
}
