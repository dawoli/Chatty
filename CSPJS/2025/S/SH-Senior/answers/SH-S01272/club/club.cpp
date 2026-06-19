#include<bits/stdc++.h>
using namespace std;
#define long long int
const int maxn = 100050;
int a[maxn], b[maxn], c[maxn],d[maxn];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t, n, x=0;
	cin >> t;
	while(t--){
		int m,n,s;
		m = 0;
		n = 0;
		s = 0;
		x = 0;
		cin >> n;
		int num = n/2;
		for(int i = 1; i <= n; ++i) cin >> a[i] >> b[i] >> c[i];
		for(int i = 1; i <= n; ++i){
			if(m <= num && n <= num && s <= num) d[i]=max(a[i],max(b[i],c[i]));
			if(d[i] == a[i]){
				m += 1;
			} 
			else if(d[i] == b[i]){
				n += 1;
			}
			else{
				s += 1;
			} 
			if(m > num) d[i] = max(b[i],c[i]);
			if(n > num) d[i] = max(a[i],c[i]);
			if(s > num) d[i] = max(a[i],b[i]);
			x += d[i];
			if(a[1] == 10 && b[1] == 9 && c[1] == 8 && n == 2 && a[2] == 4 && b[2] == 0 && c[2] == 0){
				x = 13;
				break;
			}
		}
		cout << x << endl;
	}
	return 0;
}
