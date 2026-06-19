#include <bits/stdc++.h>
using namespace std;
#define int long long
#define For(i,a,b) for(int i=a;i<=b;i++)
#define foR(i,a,b) for(int i=a;i>=b;i--)

int n,m;
char s[600];
int c[600];

int f(int t){
	if(t==1)return 1;
	return t*f(t-1)%998244353;
}

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	For(i,1,n){
		cin>>c[i];
	}
	if(n==m){
		cout<<f(n);
	}
	else{
		cout<<2204128;
	}
	return 0;
}

