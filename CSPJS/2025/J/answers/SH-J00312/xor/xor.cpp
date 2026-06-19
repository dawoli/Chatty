#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,a[500010],pre[500010],tong[500010],cnt;
bool cmp(ll x,ll y){
	return x > y;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin >> n >> k;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		pre[i] = pre[i - 1] ^ a[i];
		tong[k ^ pre[i]]++;
	}
	ll tj = 0;
	for(int i = 1;i <= n;i++){
		for(int j = tj;j < i;j++){
			ll x = pre[i] ^ pre[j];
			if(x == k){
				cnt++;
				tj = i;
				break;
			}
		}
	}
	cout << cnt;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
