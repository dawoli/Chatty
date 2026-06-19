#include <bits/stdc++.h>
using namespace std;
int n,a[100001],ans;

void read() {
	cin>>n;
	for(int i = 1;i<=n;i++) {
		cin>>a[i];
	} 
}

int main() {
    freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	read();
	
	int cur = 1;
	sort(a+1,a+n+1);
	
	for(int i = 2;i<=n;i++) {
		if(a[i] > a[cur]) {
			ans++;
			cur++;
		}
	}
	
	cout<<n-ans<<endl;
	return 0;
}
