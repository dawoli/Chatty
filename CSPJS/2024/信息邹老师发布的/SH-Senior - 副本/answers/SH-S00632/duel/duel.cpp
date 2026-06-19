#include<bits/stdc++.h>
using namespace std;
int n,x,a[100005],last,ans;
int main() {
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>x;
		a[x]++;
	}
	for(int i=1;i<=100000;i++) {
		if(a[i]!=0) {
			if(last==0) {
				last+=a[i];
			}
			else {
				ans+=min(last,a[i]);
				last-=min(last,a[i]);
				last+=a[i];
			}
		}
	}
	cout<<n-ans;
    return 0;
}

