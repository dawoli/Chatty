#include<bits/stdc++.h>
#define int long long
using namespace std;
const int P=998244353;
int n,m;
string s;
int a[1145];
int fac[1145],ifac[1145];
int qp(int x,int y) {
	if(y==0) return 1;
	int res=qp(x,y/2);
	res=res*res%P;
	if(y%2) return res*x%P;
	else return res;
}
int p[1145];
signed main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	cin >> s;
	s=' '+s;
	for(int i=1;i<=n;i++) {
		cin >> a[i];
	}
	fac[0]=1;
	for(int i=1;i<=n;i++) {
		fac[i]=fac[i-1]*i%P;
	}
	ifac[n]=qp(fac[n],P-2);
	for(int i=n-1;i>=0;i--) {
		ifac[i]=ifac[i+1]*(i+1)%P;
	}
	//solve
	if(m==n) {
		bool flag=1;
		for(int i=1;i<=n;i++) {
			if(s[i]=='0') flag=0;
		}
		for(int i=1;i<=n;i++) {
			if(a[i]==0) flag=0;
		}
		if(flag==0) cout << 0;
		else cout << fac[n];
	}
	else if(n<=10) {
		for(int i=1;i<=n;i++) {
			p[i]=i;
		}
		int ans=0;
		do{
			int cnt=0;
			for(int i=1;i<=n;i++) {
				if(cnt>=a[p[i]]) cnt++;
				else if(s[i]=='0') cnt++;
			}
			if(cnt<=n-m) ans++;
		}while(next_permutation(p+1,p+n+1));
		cout << ans;
	}
	return 0;
}
/*
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int P=998244353;
int n,m;
string s;
int a[1145];
int fac[1145],A[1145][1145];
int qp(int x,int y) {
	if(y==0) return 1;
	int res=qp(x,y/2);
	res=res*res%P;
	if(y%2) return res*x%P;
	else return res;
}
int AA(int x,int y) {
	cout << x << ' ' << y << '\n';
	if(y<0||y>x) return 0;
	else return A[x][y];
}
int p[1145];
int usd[1145],sum[1145];
int ac[1145],acs[1145];
int bc[1145],bcs[1145];
int cal() {
	for(int i=0;i<=n;i++) bc[i]=0;
	int cnt=0;
	for(int i=1;i<=n;i++) {
		if(usd[i]==0) {
			cnt++; 
		}
		else {
			bc[cnt]++;
		}
	}
	int ans=1;
	for(int i=n;i>=0;i--) {
		bcs[i]=bcs[i+1]+bc[i];
		ans=ans*AA(acs[i]-bcs[i+1],bc[i])%P;
	}
	return ans;
}
signed main() {
//	freopen("employ.in","r",stdin);
//	freopen("employ.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	cin >> n >> m;
	cin >> s;
	s=' '+s;
	for(int i=1;i<=n;i++) {
		cin >> a[i];
		ac[a[i]]++;
	}
	for(int i=n;i>=0;i--) {
		acs[i]=acs[i+1]+ac[i];
	}
	fac[0]=1;
	for(int i=1;i<=n;i++) {
		fac[i]=fac[i-1]*i%P;
	}
	A[0][0]
	for(int i=1;i<=n;i++) {
		A[i][0]=1;
		for(int j=1;j<=i;j++) {
			A[i][j]=A[i][j-1]*(i-j+1)%P; 
		}
	}
	//solve
	if(0&&m==n) {
		bool flag=1;
		for(int i=1;i<=n;i++) {
			if(s[i]=='0') flag=0;
		}
		for(int i=1;i<=n;i++) {
			if(a[i]==0) flag=0;
		}
		if(flag==0) cout << 0;
		else cout << fac[n];
	}
	else {
		int cnt=0;
		for(int i=1;i<=n;i++) {
			if(s[i]=='1') cnt++;
		}
		int ans=0;
		for(int i=0;i<(1<<cnt);i++) {
			int ii=i;
			for(int j=1;j<=n;j++) {
				if(s[j]=='1') {
					usd[j]=ii%2;
					ii/=2;
				}
				else usd[j]=0;
			}
			for(int j=1;j<=n;j++) {
				sum[j]=sum[j-1]+usd[j];
			}
			if(sum[n]<m) continue;
			cout << i << '\n';
			ans=(ans+cal())%P;
		}
		cout << ans;
	}
	return 0;
}
*/
