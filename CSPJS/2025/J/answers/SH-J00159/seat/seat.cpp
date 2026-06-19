#include<bits/stdc++.h>
using namespace std;
int n,m,a[105];
int grid[10][10];
bool cmp(int x,int y) {
	return x>y;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++) {
		cin>>a[i];
	}
	int r=a[0],t=0;
	sort(a,a+n*m,cmp);
	for(int i=1;i<=m;i++) {
		if(i%2==1) {
			for(int j=1;j<=n;j++) {
				if(a[t]==r) {
					cout<<i<<" "<<j;
					return 0;
				}
				t++;
			}
		}
		else {
			for(int j=n;j>=1;j--) {
				if(a[t]==r) {
					cout<<i<<" "<<j;
					return 0;
				}
				t++;
			}
		}
	}
	return 0;
}
//#Shang4Shan3Ruo6Shui4
