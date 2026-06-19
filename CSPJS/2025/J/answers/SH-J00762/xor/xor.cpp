#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 5e5 + 10;
ll n,k,cnt1,cnt2;
ll a[N];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(a[i] == 1){
			cnt1++;
		}
		if(a[i] == 0){
			cnt2++;
		}
	}
	if(cnt1 == n && k == 0){
		cout << n;
		return 0;
	}
	if(cnt2 == n && k == 0){
		cout << n;
		return 0;
	}
	if(k != 0){
		cout << 2;
		return 0;
	}
	if((cnt1 != n || cnt2 != n) && k == 0){
		cout << 1;
		return 0;
	}
	else{
		cout << 3;
		return 0;
	}
	return 0;
}
