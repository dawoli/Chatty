#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n,ans;
int a[100005];

int main() {
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int l=1,r=2;
	ans=n;
	while(r<=n) {
		while(r<=n && a[l]==a[r])
			r++;
		if(r>n) break;
		while(r<=n && a[l]<a[r]) {
			ans--;
			l++;
			r++;
		}
		if(r>n) break;
	}
	cout<<ans<<endl;
	return 0;
}

