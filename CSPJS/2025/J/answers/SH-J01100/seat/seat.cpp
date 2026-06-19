#include<bits/stdc++.h>
using namespace std;
struct stu{
	int n,i;
}a[110];
int f[1000][1000];
bool cmp(stu x,stu y) {
	return x.n>y.n;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) {
		cin>>a[i].n;
		a[i].i=i;
	}
	sort(a+1,a+n*m+1,cmp);
	int c=0;
	for(int j=1;j<=m;j++) {
		if(j%2) {
			for(int i=1;i<=n;i++) {
				f[i][j]=a[++c].n;
				if(a[c].i==1) {
					cout<<j<<' '<<i<<'\n';
					return 0;
				}
			}
		}
		else {
			for(int i=n;i>=1;i--) {
				f[i][j]=a[++c].n;
				if(a[c].i==1) {
					cout<<j<<' '<<i<<'\n';
					return 0;
				}
			}
		}
	}
	return 0;
}
