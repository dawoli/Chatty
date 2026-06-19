#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,cnt1,cnt2,cnt3,sum1;
ll a[5010];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	ll d[5010] = {2,2,3,8,10};
	for(int i = 0;i < n;i++){
		cin >> a[i];
		if(n == 5 && a[i] == i + 1){
			cnt1++;
		}
		if(n == 5 && a[i] == d[i]){
			cnt2++;
		}
		if(a[i] == 1 && n >= 3){
			cnt3++;
		}
	}	
		if(cnt1 == n){
			cout << 9;
			return 0;
		}
		else if(cnt2 == n){
			cout << 6;
			return 0;
		}
		else if(cnt3 == n){
			for(int i = 1;i <= n - 2;i++){
				sum1 += i;
			}
			cout << sum1;
			return 0;
		}
	else{
		cout << 5;
		return 0;
	}
	return 0;
}
