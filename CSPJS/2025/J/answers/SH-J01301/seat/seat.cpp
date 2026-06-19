#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],l,h;
bool cmp(int a,int b) {
	return a>b;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++) scanf("%d",&a[i]);
	int r=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++) {
		if(i%2==1) {
			for(int j=1;j<=n;j++) {
				if(a[(i-1)*m+j]==r) {
					l=i,h=j;
					break;
				}
			}
		}
		else {
			for(int j=1;j<=n;j++) {
				if(a[(i-1)*m+j]==r) {
					l=i,h=n-j+1;
					break;
				}
			}
		}
	}
	printf("%d %d",l,h);
	return 0;
}
