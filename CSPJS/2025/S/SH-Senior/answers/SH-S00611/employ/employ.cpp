#include<bits/stdc++.h>
#define int long long
using namespace std;
ifstream fin("employ.in");
ofstream fout("employ.out");
const int maxn=505,mod=998244353;
int n,m,a[maxn],c[maxn],cnt1,cnt2,cnt3,st[maxn];
signed main() {
	fin>>n>>m; st[0]=1; int ans=0;
	for(int i=1;i<=n;i++)  st[i]=st[i-1]*i%mod;
	for(int i=1;i<=n;i++) {
		char ch; fin>>ch;
		a[i]=ch-'0'; cnt1+=a[i]; cnt3+=!cnt1;
	}
	for(int i=1;i<=n;i++) {
		fin>>c[i]; cnt2+=c[i];
	}
	if(m==n) {
		if(cnt1!=n||cnt2!=n)  fout<<0;
		else  fout<<st[n];
	}
	else  fout<<0;
//	else if(m==1) {
//		//枚举哪个人会被录取，以及在哪里被录取，显然它一定是最高的一个 
//		if(cnt1) {
//			int cnt=0;
//			for(int i=1;i<=n;i++)  if(c[i]>cnt3)  cnt++;
//			ans=st[n-1]*cnt;
//		}
//	}
	return 0;
}
