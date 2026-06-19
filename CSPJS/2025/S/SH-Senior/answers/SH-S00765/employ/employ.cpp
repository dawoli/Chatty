#include<bits/stdc++.h>
using namespace std;
const int M = 998244353;
int n,m,a[501],q[501];
string s;
bool allone;
inline long long A(int a,int b) {
	long long ans=1;
	for(long long i = b;i<=a;i++){
		ans=(ans%M)*(i%M)%M;
	}return ans%M;
}	
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>s;
	for(int i = 0;i<n;i++){
		cin>>a[i];
		q[i]=s[i]-48;
		if(!q[i]) allone=1;
	}if(!allone) cout<<A(n,m);
	return 0;
}

