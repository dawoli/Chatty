#include <bits/stdc++.h>
using namespace std;
int T;
int n;
int a[200010];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		int rd=0,bl=0;
		long long anss=0;
		for(int qqq=0;qqq<(1<<n);qqq++){
			rd=0,bl=0;
			long long ans=0;
			for(int i=1;i<=n;i++){
				bool cl=(qqq>>(i-1))&1;
				if(cl)ans+=(a[bl]==a[i]? a[i]:0),bl=i;
				else ans+=(a[rd]==a[i]? a[i]:0),rd=i;
			}
			anss=max(anss,ans);
//			cout<<qqq<<" "<<ans<<endl;
		}
		printf("%d\n",anss);
	}
	return 0;
}
