#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n,b,ans=0;
	cin >> n; 
	for(int i=0;i<n;i++){
		cin >> b;
		a[b]++;
		ans=max(ans,a[b]);
	}
	cout << ans;
	return 0;
}
