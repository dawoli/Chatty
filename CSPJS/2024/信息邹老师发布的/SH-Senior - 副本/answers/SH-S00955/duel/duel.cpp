#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n, a[N], ni, ai[N], num[N], pre, cnt;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) ai[i]=a[i];
	ni = unique(ai+1,ai+n+1)-ai-1;
	int it=0;
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i-1]) it++;
		num[it]++;
	}
	pre=num[1];
	for(int i=2;i<=ni;i++){
		cnt+=min(pre,num[i]);
		pre=max(pre,num[i]);
	}
	printf("%d\n",n-cnt);
	return 0;
}
