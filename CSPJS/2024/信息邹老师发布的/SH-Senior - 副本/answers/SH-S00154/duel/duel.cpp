#include<bits/stdc++.h>
using namespace std;
int a[100010];
int main(){
//	freopen("duel.in","r",stdin);
//	freopen("duel.out","w",stdout);
	int n,ans,p=1;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	ans=n;
	for(int i=1;i<=n;i++){
		int t=lower_bound(a+p,a+n+1,a[i])-a;
		if(t-1==p-1)continue;
		ans--,p++;
	}
	cout<<ans;
	return 0;
}
