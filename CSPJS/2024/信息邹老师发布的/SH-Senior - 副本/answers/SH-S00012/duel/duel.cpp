#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
int n,a[N],ans=0; 

int main() {
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int cnt=0,used=0;
	for(int i=1;i<=n;i++) {
		if(a[i]==a[i-1]) cnt++;
		else {
			used=max(used,i-1);
			if(n-used>=cnt) used+=cnt,ans+=cnt,cnt=1;
			else ans+=n-used,used=n,cnt=1;
		}
	}
	cout<<n-ans<<'\n';
	return 0;
} 
