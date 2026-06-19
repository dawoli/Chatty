#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,ans=1;
	for (int i = 1;i <= n;i++){
		ans *= i,ans%=998244353;
	}	
	cout << ans%998244353;
	return 0;
}
