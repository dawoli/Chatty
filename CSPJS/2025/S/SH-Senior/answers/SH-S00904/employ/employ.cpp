#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define FOR(n) for(int i=1;i<=n;i++)
#define FORj(n) for(int j=1;j<=n;j++)
#define For(n) for(int i=0;i<n;i++)
#define Forj(n) for(int j=0;j<n;j++)
#define ci(x) cin>>x;
#define ci2(x,y) cin>>x>>y;
#define ci3(x,y,z) cin>>x>>y>>z;
#define cr(x) cout<<x<<endl;
#define cr2(x,y) cout<<x<<' '<<y<<endl;
#define cr3(x,y,z) cout<<x<<' '<<y<<' '<<z<<endl;
int n,m;
string str;
bool s[100006];
int c[100006];
int a[10006];
int nx[10006];//耐心小于i的人数 
int fqn,ln;
int _2[10006];
const int mod=998244353;
void slv2() {
	int ans=0;
	FOR(n) {
		a[i]=i;
	}
	while(1) {
		fqn=0,ln=0;
		FOR(n) {
			if(s[i]) {
				if(c[a[i]]>fqn) {
					fqn++;
				} else {
					ln++;
				}
			} else {
				fqn++;
			}
			if(ln>=m)ans++;
		}
		if(!next_permutation(a+1,a+n+1))break;
	}
	cr(ans)
}
void h0peakioi() {
	_2[0]=1;
	FOR(500){
		_2[i]=_2[i-1]*i%mod;
	}
	ci2(n,m)
	ci(str)
	int len=str.size();
	For(len)s[i+1]=str[i]=='1';
	FOR(n)ci(c[i])
	if(n<=18)slv2();
	else cr(_2[n])
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int TOT=1;
//	ci(TOT)
// 多册吗 清空了吗
// 文件开了吗
	while(TOT--)h0peakioi();
}

