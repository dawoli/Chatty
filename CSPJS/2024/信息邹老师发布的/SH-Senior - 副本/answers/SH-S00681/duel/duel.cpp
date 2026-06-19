#include <bits/stdc++.h>
using namespace std;
int a[100010],ans,n;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin >> n;
	ans = n;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for (int i = 1,f = 1;i <= n && f <= n;i++){
		if (i != f && a[i] > a[f] && i <= 100010){
			ans--;
			f++;
		}
	}
	cout << ans;
	return 0;
}

