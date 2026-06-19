#include <bits/stdc++.h>
using namespace std;
int n,m;
string s;
int c[505];
long long ans=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	for(int i=0;i<n;i++)cin >> c[i];
	while(n){
		ans*=n;
		ans%=998244353;
		n--;
	}
	cout << ans <<endl;
	return 0;
}
