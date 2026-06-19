#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),endi=(b);i<=endi;++i)
#define foR(i,a,b) for(int i=(a),endi=(b);i>=endi;--i)
#define ll long long
#define N 200009
using namespace std;
int T;
int n;
int a[N];
int f[N][2];
void solveBF() {
	For(i,1,n)
		f[i][0]=f[i][1]=0;
	For(i,1,n) {
		f[i][0]=f[i-1][1];
		f[i][1]=f[i-1][0];
		if(a[i]!=a[i-1])
			f[i][1]=max(f[i][1],f[i-1][1]);
		foR(j,i-1,1)
			if(a[i]==a[j]) {
				f[i][1]+=a[i];
				break;
			}
	}
//	For(i,1,n)
//		cout<<f[i][0]<<' ';
//	cout<<'\n';
//	For(i,1,n)
//		cout<<f[i][1]<<' ';
//	cout<<'\n';
	cout<<f[n][1]<<'\n';
}
int main() {
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--) {
		cin>>n;
		For(i,1,n)
			cin>>a[i];
		if(n<=2000)
			solveBF();
	}
	return 0;
}

