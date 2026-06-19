#include<bits/stdc++.h>
using namespace std;
signed main(){
	freopen("color.in","r",stdin);
	freopen("color.in","w",stdout);
	int T;cin >> T;
	while(T--){
		int n;cin >> n;
		int ans=0,A[n+20];
		for(int i=1;i<=n;i++)cin >> A[i];
		sort(A+1,A+1+n);
		for(int i=1;i<=n;i++){
			if(A[i]==A[i+1])ans+=A[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}
