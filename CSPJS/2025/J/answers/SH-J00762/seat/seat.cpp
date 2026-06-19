#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,q5,k4,cnt3,d2;
ll c1,r6;
ll a[200];
ll R;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	q5 = n * m;
	for(int i = 1;i <= q5;i++){
		cin >> a[i];
	}
	R = a[1];
	sort(a + 1,a + q5 + 1);
	for(int i = q5;i >= 1;i--){
		cnt3++;
		if(a[i] == R){
			k4 = cnt3;
			break;
		}
	}
	d2 = k4;
	for(int i = 1;i <= m;i++){
		if(i % 2 == 1){
			for(int j = 1;j <= n;j++){
				d2--;
				if(d2 == 0){
					c1 = i;
					r6 = j;
					cout << c1 << " " << r6;
					return 0;
				}
			}
		}
		else if(i % 2 == 0){
			for(int j = n;j >= 1;j--){
				d2--;
				if(d2 == 0){
					c1 = i;
					r6 = j;
					cout << c1 << " " << r6;
					return 0;
				}
			}
		}
	}
	return 0;
}
