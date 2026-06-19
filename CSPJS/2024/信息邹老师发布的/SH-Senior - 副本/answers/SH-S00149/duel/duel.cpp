#include<bits/stdc++.h>
using namespace std;
int n,a[100010],maxx;
int ans;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		a[x]++;
		maxx=max(x,maxx);
	}
	for(int i=1;i<=maxx;i++){
		ans=max(0,ans-a[i]);
		ans+=a[i];
	}
	printf("%d",ans);
}
