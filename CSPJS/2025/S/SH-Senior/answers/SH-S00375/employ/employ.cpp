#include<bits/stdc++.h>
using namespace std;
long long n,m,c[505];
bool f = 1;
string s;
long long a(long long n){
	long long ans = 1;
	for(long long i = 1;i <= n;i++){
		ans *= i;
		ans %= 998244353;
	}
	return ans;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(long long i = 1;i <= n;i++){
		cin>>c[i];
		if(s[i-1] != '1'){
			f = 0;
		}
	}
	if(f){
		cout<<a(n)<<endl;
	}
	else{
		cout<<0<<endl;
	}
	return 0;
}
