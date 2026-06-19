#include <bits/stdc++.h>
using namespace std;
int T,n=0;
int ans[100005];
int main() {
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	for (int i=0;i<T;i++) {
		cin>>n;
		if (n==1) ans[i]=-1;
	}
	for (int i=0;i<T;i++) cout<<ans[i];
	return 0;
} 

