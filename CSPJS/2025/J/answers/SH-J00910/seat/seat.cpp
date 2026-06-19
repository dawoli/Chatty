#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[105];
bool cmp(ll x,ll y){
	return x > y;
}
int main(){
	//freopen("seat","in",stdin);
	//freopen("seat","out",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++){
		cin >> a[i];
	}
	ll r = a[1];
	sort(a + 1,a + 1 + n * m,cmp);
	ll k = 1;
	for(int i = 1;i <= n;i++){
		if(i % 2 == 1){
			for(int j = 1;j <= m;j++){
				if(a[k] == r){
					cout << i << " " << j;
					return 0;
				}
				k++;
			}
		}else if(i % 2 == 0){
			for(int j = m;j >= 1;j--){
				if(a[k] == r){
					cout << i << " " << j;
					return 0;
				}
				k++;
			} 
		}
	}
	
	return 0;
}
