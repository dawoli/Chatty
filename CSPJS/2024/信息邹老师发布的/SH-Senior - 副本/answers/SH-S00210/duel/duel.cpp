#include<bits/stdc++.h>
using namespace std;
int n,a[100010];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i];
	sort(a + 1,a + n + 1);
	int ans = n,j = 1;
	for(int i = 1;i <= n;i++){
		while(j <= n && a[j] <= a[i]) j++;
		if(j > n) break;
		ans--,j++;
	}
	cout << ans;
	return 0;
}
