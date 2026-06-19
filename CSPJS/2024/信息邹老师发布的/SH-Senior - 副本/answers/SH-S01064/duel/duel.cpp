#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[1000010],ans,cnt;
signed main(){
	freopen("deul.in","r",stdin);
	freopen("deul.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){cin>>a[i];}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(cnt==0)cnt++;
		else if(a[i]>a[i-cnt])ans++;
		else cnt++;
	}
	cout<<n-ans;
	return 0;
}
