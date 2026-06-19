#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int P=998244353;
const int N=505;
int n,m;
string s;
int cntz=0;
int c[N];
ll frac[N];
void init() {
	frac[0]=1;
	for (int i=1;i<=n;i++) {
		frac[i]=((ll)i*frac[i-1])%P;
	}
}
void solveA() {
	if (cntz>n-m) {
		cout<<0<<endl;
		return ;
	} 
	//n frac
	cout<<frac[n]<<endl;
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	init();
	cin>>s;
	for (int i=1;i<=n;i++) {
		cin>>c[i];
		if (c[i]==0) cntz++;
	}
	bool flagA=1;
	for (int i=0;i<s.size();i++) {
		if (s[i]!='1') flagA=0;
	}
	cout<<cntz<<endl;
	if (flagA) {
		solveA();
		return 0;
	}
	return 0;
}

