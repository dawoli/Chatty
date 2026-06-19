#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[10010],s[110][110];
bool cmp(ll x,ll y){
	return x > y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++){
		cin >> a[i];
	}
	ll base = a[1];
	sort(a + 1,a + n * m + 1,cmp);
	ll x,y;
	for(int i = 1;i <= n * m;i++){
		if(a[i] == base){
			if(i % n == 0){
				x = i / n;
				if(x % 2 == 0) y = 1;
				else y = n;
				break;
			}
			x = i / n + 1;
			if(x % 2 == 0) y = n - i % n + 1;
			else y = i % n;
			break;
		}
	}
	cout << x << " " << y;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
