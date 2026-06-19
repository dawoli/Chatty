#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[105];
bool cmp(int a,int b) {
	return a>b;
}
signed main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n*m;i++) {
		cin >> a[i];
	}
	int s=a[1];
	sort(a+1,a+n*m+1,cmp);
	int r=0,c=1;
	for(int i=1;i<=n*m;i++) {
		if(c%2==1) {
			r++;
			if(r>n) {
				r=n;
				c++;
			}
		}
		else {
			r--;
			if(r<1) {
				r=1;
				c++;
			}
		}
		if(a[i]==s) {
			cout << c << ' ' << r << endl;
			return 0;
		}
	}
	return 0;
} 
