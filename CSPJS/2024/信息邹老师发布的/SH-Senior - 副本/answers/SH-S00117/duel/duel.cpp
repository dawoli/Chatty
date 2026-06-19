#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n,a[maxn],ans,sum,t;
bool gj[maxn];
signed main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(register int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(register int i=1;i<=n;i++){
		ans=upper_bound(a+1,a+n+1,a[i])-a;
		if(!gj[ans]){
			t=0;
		}
		ans+=t;
		while(gj[ans]==1){
			t++;
			ans++;
		}
		if(a[ans]>a[i]){
			sum++;
			gj[ans]=1;
		}
	}
	cout<<n-sum;
	return 0;
}
