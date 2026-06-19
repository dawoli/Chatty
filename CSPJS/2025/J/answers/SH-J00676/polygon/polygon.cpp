#include<bits/stdc++.h>
using namespace std;
const int Mod = 998244353;
int n;
int a[5009],ans;
void dfs(int sum,int end){
	if(end == (n - 1)){
		if(sum > a[end]){
			ans++;
			if(ans >= Mod){
				ans -= Mod;
			}
		}
		return;
	}
	for(int i = end + 1;i < n;i++){
		dfs((end == -1) ? sum : sum + a[end],i);
	}
	if(sum > a[end]){
		ans++;
		if(ans >= Mod){
			ans -= Mod;
		}
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n == 3){
		int a,b,c;
		cin>>a>>b>>c;
		if((a + b) > c and abs(a - b) < c){
			cout<<1;
		}else{
			cout<<0;
		}
		return 0;
	}
	bool flag = 1;
	for(int i = 0;i < n;i++){
		cin>>a[i];
		if(a[i] != 1){
			flag = 0;
		}
	}
	if(flag){
		long long sum = n * (n - 1) * (n - 2) / 6,ans;
		sum %= Mod;
		ans = sum;
		for(int i = 3;i < n;i++){
			sum = sum * (n - i) / (i + 1);
			sum %= Mod;
			ans += sum;
			if(ans >= Mod){
				ans -= Mod;
			}
		}
		cout<<ans;
		return 0;
	}
	sort(a,a + n);
	dfs(0,-1);
	if(ans >= Mod){
		ans -= Mod;
	}
	cout<<ans;
	return 0;
}
