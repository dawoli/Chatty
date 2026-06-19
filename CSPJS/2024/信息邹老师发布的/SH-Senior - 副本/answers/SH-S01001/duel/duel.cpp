#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int n,ans;
int a[N],d[N];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		d[a[i]]++;
	}
	for(int i=1;i<N;i++){
		ans=max(ans,d[a[i]]);
	}
	printf("%d",ans);
	return 0;
}

