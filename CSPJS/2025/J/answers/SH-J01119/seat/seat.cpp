#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m+1];
	for(int i=1; i<n*m+1; i++) {
		cin>>a[i];
	}
	int tar=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1; i<=n*m+1; i++) {
		if(a[i]==tar) {
			int x=(i+n-1)/n;
			if(x%2) {
				int y=i%n;
				if(!y) {
					y=n;
				}
				cout<<x<<" "<<y;
				return 0;
			} else {
				int y=n+1-i%n;
				if(y==n+1) {
					y=1;
				}
				cout<<x<<" "<<y;
				return 0;
			}

		}
	}
	return 0;
}
