#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N=12;
int n,m,a[N*N];
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int g=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1,dy=1,x=1,y=1;i<=n*m;i++) {
		if(a[i]==g) {
			cout<<x<<' '<<y;
			break;
		}
		y+=dy;
		if(y>m) x++,y=m,dy=-1;
		if(y<1) x++,y=1,dy=1;
	}
	return 0;
}
