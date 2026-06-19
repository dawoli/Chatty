#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T,n,a[100009][5],ax,bx,cx,ans,zd;
ll b[100009][5],zx;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		ans=0;
		ax=bx=cx=0;
		if(n==2){
			ll aa,bb,cc,dd,ee,ff;
			cin>>aa>>bb>>cc>>dd>>ee>>ff;
			ans=max(aa,max(bb,cc))+max(dd,max(ee,ff));
			cout<<ans<<endl;
			continue;
		}
	}
	return 0;
}       
