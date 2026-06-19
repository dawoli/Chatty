#include<bits/stdc++.h>
using namespace std;
int n,r,cnt,ans;
int main() {
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>r;
		if(r==1) cnt++;
		if(r==2) ans++;
	}
	cout<<n-min(cnt,ans)<<endl;
	return 0;
}
