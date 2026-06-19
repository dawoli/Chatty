#include<bits/stdc++.h>
using namespace std;
const int N=100009;
int n,a[N],b[N],cnt[N],ans;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b+1,b+n+1);
	int m=unique(b+1,b+n+1)-b-1;
	for(int i=1;i<=n;i++){
		a[i]=lower_bound(b+1,b+m+1,a[i])-b;
		cnt[a[i]]++;
		ans=max(ans,cnt[a[i]]);
	}
	cout<<ans<<endl;
	return 0;
}
