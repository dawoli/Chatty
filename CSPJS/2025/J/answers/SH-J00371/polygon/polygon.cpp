#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod=998244353;
int n,a[5005],ans=0,cnt=0,mx=0;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],cnt+=a[i],mx=max(mx,a[i]);
	if(n<3){
		cout<<0;
		return 0;
	}
	if(cnt>2*mx) ans++;
	cout<<ans;
	return 0;
}
