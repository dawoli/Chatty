# include <bits/stdc++.h>
using namespace std;
int main(){
 	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5050],sum = 0,ans = 0;
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[n];
		sum += a[i];
	}
	if(n == 3){
		for(int i = 1;i <= n;i++){
			for(int j = i + 1;j <= n;j++){
				if(a[i] <= a[j]){
					swap(a[i],a[j]);
					}
				}
			}
		if(sum >= 2 * a[1]){
			cout << "1";
		}
		else{
			cout << "0";
		}
		return 0;
	}
	else{
		for(int i = 3;i <= n;i++){
			ans += (n * (n - 1) * 2) / i;
		}
		cout << ans << endl;
		return 0;
	}
	return 0;
}
