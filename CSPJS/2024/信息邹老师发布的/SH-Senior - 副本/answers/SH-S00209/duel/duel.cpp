#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	cin >> n;
	int a[n],b[n],c[n];
	for(int i = 0;i < n;i++) {
		cin >> a[i];
		b[i] = 1;
		c[i] = 1;
	}
	sort(a,a+n);
	//for(int i = 0;i < n;i++) cout << a[i] << ' ';
	for(int i = 1;i < n;i++){
		if (a[i] > a[i-1] && c[i - 1] != 0 && b[i] != 0){
			c[i-1] = 0;
			b[i] = 0;
		}
		else{
			for(int j = 0;j < i;j++){
				if (b[i] == 0) continue;
				if (c[j] == 1 && b[i] == 1 && a[j] < a[i]){
					c[j] = 0;
					b[i] = 0;
				}
			}
		}
	} 
	int ans = 0;
	for(int i = 0;i < n;i++)
		if (c[i] == 1)
			ans++;
	cout << ans;
	return 0;
}
