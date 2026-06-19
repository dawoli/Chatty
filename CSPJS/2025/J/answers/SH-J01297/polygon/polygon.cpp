#include<bits/stdc++.h>
using namespace std;
const int N = 5009;
const int MOD =  998244353 ;
int a[N],n,k,sum,ans;
void bfs(int i){
	if (sum > a[i]*2){
		ans = (ans + 1)%MOD;
	}
	for(int j = i+1;j <= n;j++){
		sum += a[j];
		bfs(j);
		sum -= a[j];
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n ;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for (int i = 1;i <= n;i++){
		sum = a[i];
		bfs(i);
	}
	cout << ans;
	return 0; 
} 
